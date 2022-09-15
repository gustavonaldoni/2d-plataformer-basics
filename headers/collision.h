bool CheckCollisionPlayerFloor(Player, Floor);
bool CheckCollisionPlayerFloors(Player, Floor *, int);
bool CheckCollisionPlayerBullet(Player, Bullet);
bool CheckCollisionPlayerBullets(Player, Bullet *, int);

bool CheckCollisionPlayerFloor(Player player, Floor floor)
{
    return CheckCollisionRecs((Rectangle){player.x, player.y, player.size, player.size},
                              (Rectangle){floor.x, floor.y, floor.width, floor.height});
}

bool CheckCollisionPlayerFloors(Player player, Floor floors[], int numberOfFloors)
{
    int i;

    for (i = 0; i < numberOfFloors; i++)
    {
        if (CheckCollisionPlayerFloor(player, floors[i]))
        {
            return true;
        }
    }

    return false;
}

bool CheckCollisionPlayerBullet(Player player, Bullet bullet)
{
    return CheckCollisionRecs((Rectangle){player.x, player.y, player.size, player.size},
                              (Rectangle){bullet.x, bullet.y, bullet.width, bullet.height});
}

bool CheckCollisionPlayerBullets(Player player, Bullet bullets[], int numberOfBullets)
{
    int i;

    for (i = 0; i < numberOfBullets; i++)
    {
        if (CheckCollisionPlayerBullet(player, bullets[i]))
        {
            return true;
        }
    }

    return false;
}