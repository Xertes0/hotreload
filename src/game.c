#include <stdio.h>

#include <raylib.h>

#define HOTRELOAD_DO_DEFINE
#include "game.h"

/* state_g is pointed to a zero-initialized buffer in hotreload.c. */
struct game_state *state_g = (struct game_state *) 0xDEAD;

void game_tick()
{
	if (IsKeyPressed(KEY_SPACE)) {
		state_g->counter++;
	}

	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Change this text in src/game.c and recompile the project.",
		 110, 150, 20, BLACK);

	char text2[128];
	sprintf(text2,
		"Press SPACE to increase this counter: %i\n"
		"Application state is preserved across reloads.",
		state_g->counter);
	DrawText(text2, 110, 350, 20, BLACK);

	EndDrawing();
}
