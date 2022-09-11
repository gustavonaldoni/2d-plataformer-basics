#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "include/raylib.h"
#include "include/raymath.h"

// Compile with: gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

int main()
{
	srand(time(NULL));

	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "2D Plataformer");
	
	SetTargetFPS(144);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		EndDrawing();
	}

	CloseWindow();
}