typedef struct
{
    float x, y;
    float width, height;
    Color color;
} Floor;

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