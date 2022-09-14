bool CheckCollisionPlayerFloor(Player, Floor);
bool CheckCollisionPlayerFloors(Player, Floor *, int);

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