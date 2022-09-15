typedef struct
{
    float x, y;
    float width, height;
    float speedX;
    Color color;
} Bullet;

Bullet CreateBullet();
void DrawBullet(Bullet);
void DrawBullets(Bullet *, int);
void MoveBullet(Bullet *);
void MoveBullets(Bullet *, int);
void CleanBullets(Bullet *, int);

Bullet CreateBullet()
{
    Bullet bullet;

    bullet.speedX = GenerateRandomNumber(400.0f, 600.0f);

    bullet.x = GetScreenWidth();
    bullet.y = (float)GenerateRandomNumber(100, GetScreenHeight() - 100);

    bullet.width = 10.0f;
    bullet.height = 10.0f;

    bullet.color = DARKBLUE;

    return bullet;
}

void CreateBullets(Bullet bullets[], int maxBullets)
{
    int i;

    for (i = 0; i < maxBullets; i++)
    {
        bullets[i] = CreateBullet();
    }
}

void DrawBullet(Bullet bullet)
{
    DrawRectangle(bullet.x, bullet.y, bullet.width, bullet.height, bullet.color);
}

void DrawBullets(Bullet bullets[], int maxBullets)
{
    int i;

    for (i = 0; i < maxBullets; i++)
    {
        if (bullets[i].width != 0)
        {
            DrawBullet(bullets[i]);
        }
    }
}

void MoveBullet(Bullet *bullet)
{
    bullet->x -= bullet->speedX * GetFrameTime();

    if (bullet->x <= 0)
    {
        bullet->x = GetScreenWidth();
        bullet->y = (float)GenerateRandomNumber(100, GetScreenHeight() - 100);
    }
}

void MoveBullets(Bullet bullets[], int maxBullets)
{
    int i;

    for (i = 0; i < maxBullets; i++)
    {
        if (bullets[i].width != 0)
        {
            MoveBullet(&bullets[i]);
        }
    }
}

void CleanBullets(Bullet bullets[], int maxBullets)
{
    int i;

    for (i = 0; i < maxBullets; i++)
    {
        bullets[i].color = DARKBLUE;
        bullets[i].height = 0.0f;
        bullets[i].width = 0.0f;
        bullets[i].speedX = 0.0f;
        bullets[i].x = 0.0f;
        bullets[i].y = 0.0f;
    }
}
