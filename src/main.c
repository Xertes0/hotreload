#include <raylib.h>

#include "game.h"

#ifdef HOTRELOAD
#include "hotreload.h"
#endif

int main()
{
	SetTraceLogLevel(LOG_WARNING);

	InitWindow(800, 600, "Hot Reload DEMO");

	SetTargetFPS(60);

#ifdef HOTRELOAD
	hotreload_open();
#else
	char state_buff[sizeof(struct game_state)] = {0};
	state_g = (struct game_state *) state_buff;
#endif

	while (!WindowShouldClose()) {
#ifdef HOTRELOAD
		hotreload_check();
#endif
		game_tick();
	}

	CloseWindow();

#ifdef HOTRELOAD
	hotreload_close();
#endif

	return 0;
}
