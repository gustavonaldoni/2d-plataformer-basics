#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "include/raylib.h"
#include "include/raymath.h"

// Compile with: gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

#include "headers/utils.h"
#include "headers/timer.h"
#include "headers/stopwatch.h"
#include "headers/player.h"
#include "headers/floor.h"
#include "headers/bullet.h"
#include "headers/collision.h"

#define GRAVITY 350.0f
#define MAX_SPEEDY 450.0f

#define MAX_BULLETS 5

int main()
{
	srand(time(NULL));

	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "2D Plataformer");

	Player player = CreatePlayer(0, 0);
	player.x = (GetScreenWidth() - player.size) / 2;
	player.y = (GetScreenHeight() - player.size) / 2 - GetScreenHeight() / 5;

	Floor floors[3] = {CreateFloor(0, 0, 500, 50),
					   CreateFloor(0, 0, 200, 50),
					   CreateFloor(0, 0, 200, 50)};

	floors[0].x = (GetScreenWidth() - floors[0].width) / 2;
	floors[0].y = (GetScreenHeight() - floors[0].height) / 2;

	floors[1].x = (GetScreenWidth() - floors[1].width) / 2 - GetScreenWidth() / 4;
	floors[1].y = (GetScreenHeight() - floors[1].height) / 2 + GetScreenHeight() / 5;

	floors[2].x = (GetScreenWidth() - floors[2].width) / 2 + GetScreenWidth() / 5;
	floors[2].y = (GetScreenHeight() - floors[2].height) / 2 + GetScreenHeight() / 4;

	Bullet bullets[MAX_BULLETS];
	CleanBullets(bullets, MAX_BULLETS);
	CreateBullets(bullets, MAX_BULLETS);

	SetTargetFPS(144);
	while (!WindowShouldClose())
	{
		printf("player.speedY = %f\n", player.speedY);
		if (player.canJump)
			printf("CAN jump\n");

		else if (!player.canJump)
			printf("CANNOT jump\n");

		if (player.lost == false)
		{
			if (IsKeyDown(KEY_A))
				player.x -= player.speedX * GetFrameTime();

			if (IsKeyDown(KEY_D))
				player.x += player.speedX * GetFrameTime();

			if (IsKeyDown(KEY_SPACE) && player.canJump)
			{
				player.speedY = -player.speedY;
				player.canJump = false;

				player.y += player.speedY * GetFrameTime();
				player.speedY += GRAVITY * GetFrameTime();
			}

			if (!CheckCollisionPlayerFloors(player, floors, 3))
			{
				player.y += player.speedY * GetFrameTime();
				player.speedY += GRAVITY * GetFrameTime();

				if (player.speedY > MAX_SPEEDY)
					player.speedY = MAX_SPEEDY;

				player.canJump = false;
			}

			else if (CheckCollisionPlayerFloors(player, floors, 3))
			{
				player.canJump = true;
			}

			if (CheckCollisionPlayerBullets(player, bullets, MAX_BULLETS))
			{
				player.lost = true;
			}

			MoveBullets(bullets, MAX_BULLETS);
		}

		BeginDrawing();

		if (player.lost)
			ClearBackground(BLACK);
		else
			ClearBackground(RAYWHITE);

		DrawPlayer(player);
		DrawFloors(floors, 3);

		DrawBullets(bullets, MAX_BULLETS);

		EndDrawing();
	}

	CloseWindow();
}
