typedef struct
{
    float x, y;
    float width, height;
    Color color;
} Floor;

Floor CreateFloor(float, float, float, float);
void DrawFloor(Floor);
void DrawFloors(Floor *, int);

Floor CreateFloor(float x, float y, float width, float height)
{
    return (Floor){x, y,
                   width, height,
                   DARKGRAY};
}

void DrawFloor(Floor floor)
{
    DrawRectangle(floor.x, floor.y,
                  floor.width, floor.height,
                  floor.color);
}

void DrawFloors(Floor floors[], int numberOfFloors)
{
    int i;

    for (i = 0; i < numberOfFloors; i++)
    {
        DrawFloor(floors[i]);
    }
}