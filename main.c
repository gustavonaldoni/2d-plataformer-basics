#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "include/raylib.h"
#include "include/raymath.h"

// Compile with: gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

#include "headers/utils.h"
#include "headers/player.h"
#include "headers/floor.h"

int main()
{
	srand(time(NULL));

	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "2D Plataformer");

	Player player = CreatePlayer(0,0);
	player.x = (GetScreenWidth() - player.size) / 2;
	player.y = (GetScreenHeight() - player.size) / 2 - GetScreenHeight() / 5;

	Floor floor = CreateFloor(0, 0, 500, 50);
	floor.x = (GetScreenWidth() - floor.width) / 2;
	floor.y = (GetScreenHeight() - floor.height) / 2;
	
	SetTargetFPS(144);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawPlayer(player);
		DrawFloor(floor);

		EndDrawing();
	}

	CloseWindow();
}
