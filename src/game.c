#include <raylib.h>

#define HOTRELOAD_DO_DEFINE
#include "game.h"

void main_loop()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Change this text in src/game.c and recompile the project.",
		 110, 200, 20, BLACK);

	EndDrawing();
}
