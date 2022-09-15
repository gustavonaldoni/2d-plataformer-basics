typedef struct
{
    float x, y;
    float size;
    float speedX, speedY;
    bool canJump;
    bool lost;
    Color color;
} Player;

Player CreatePlayer(float, float);
void DrawPlayer(Player);

Player CreatePlayer(float x, float y)
{
    return (Player){x, y,
                    50,
                    300, 200,
                    false, false,
                    (Color){GenerateRandomNumber(0, 100), GenerateRandomNumber(0, 100), GenerateRandomNumber(0, 100), 255}};
}

void DrawPlayer(Player player)
{
    DrawRectangle(player.x, player.y,
                  player.size, player.size,
                  player.color);
}