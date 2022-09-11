typedef struct 
{
    float x, y;
    float size;
    float speedX, speedY;
    Color color;
} Player;

Player CreatePlayer(float, float);
void DrawPlayer(Player);

Player CreatePlayer(float x, float y)
{
    return (Player){x, y,
                    GenerateRandomNumber(50, 80), 
                    GenerateRandomNumber(100, 200), GenerateRandomNumber(100, 200),
                    (Color){GenerateRandomNumber(0, 255), GenerateRandomNumber(0, 255), GenerateRandomNumber(0, 255), 255}};
}

void DrawPlayer(Player player)
{
    DrawRectangle(player.x, player.y, 
                  player.size, player.size,
                  player.color);
}