#include "hotreload.h"

#include <dlfcn.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <unistd.h>

#define HOTRELOAD_NO_EXTERN
#include "game.h"

void *dlhandle;
int inotify_fd;
pthread_t watch_thread;
/* Do I need atomic when only one thread writes to this? */
bool should_reload;

static void open_and_load()
{
	/* RTLD_NOW instead of LAZY? */
	dlhandle = dlopen("src/.libs/libgame.so", RTLD_LAZY);
	if (!dlhandle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}
	dlerror();

	char *error = NULL;

	*(void **) (&main_loop) = dlsym(dlhandle, "main_loop");

	error = dlerror();
	if (error != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
}

static void *watch_events(void *data)
{
	(void) data;

	char buf[4096]
		__attribute__
		((aligned(__alignof__(struct inotify_event))));
	const struct inotify_event *event;

	for (;;) {
		int size = read(inotify_fd, buf, sizeof(buf));
		if (size == -1 && errno != EAGAIN) {
			perror("inotify_fd read");
			exit(1);
		}

		if (size <= 0)
			break;

		for (char *ptr = buf; ptr < buf + size;
		     ptr += sizeof(struct inotify_event) + event->len) {
			event = (const struct inotify_event *) ptr;
			if (event->mask & IN_CLOSE_WRITE) {
				/* printf("IN_CLOSE_WRITE: %.*s\n", */
				/*        event->len, */
				/*        event->name); */

				if (event->len >= 10 &&
				    strncmp(event->name, "libgame.so", 10) == 0) {
					/* This does not detect the write to libgame.so but to
					   libgame.so.x.y.z which is the target of libgame.so
					   symlink.

					   Because with dlopen() we are opening libgame.so
					   there is a small window when libgame.so.x.y.z
					   exists but the symlink hasn't been yet created.

					   I chose to dlopen() libgame.so insted of
					   libgame.so.x.y.z because the last digits
					   represent the library's version which may change.
					*/
					sleep(1);
					should_reload = true;
				}
			}
		}
	}

	return NULL;
}

void hotreload_open()
{
	should_reload = false;
	open_and_load();

	inotify_fd = inotify_init();
	if (inotify_fd == -1) {
		perror("inotify_init");
		exit(1);
	}

	int watch = inotify_add_watch(inotify_fd,
				      "src/.libs",
				      IN_CLOSE_WRITE /* | IN_MODIFY */);
	if (watch == -1) {
		perror("inotify_add_watch");
		exit(1);
	}

	printf("Watching src/.libs for libgame.so\n");

	pthread_create(&watch_thread, NULL, watch_events, NULL);
}

void hotreload_check()
{
	if (should_reload) {
		should_reload = false;
		printf("RELOADING...\n");
		dlclose(dlhandle);
		open_and_load();
	}
}

void hotreload_close()
{
	close(inotify_fd);
	dlclose(dlhandle);
}
