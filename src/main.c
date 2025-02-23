#include <raylib.h>

#include "game.h"
#include "hotreload.h"

int main()
{
	SetTraceLogLevel(LOG_WARNING);

	InitWindow(800, 600, "Hot Reload DEMO");

	SetTargetFPS(60);

	hotreload_open();

	while (!WindowShouldClose()) {
		hotreload_check();
		main_loop();
	}

	CloseWindow();

	hotreload_close();

	return 0;
}
