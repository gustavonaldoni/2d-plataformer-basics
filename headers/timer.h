typedef struct
{
    float quantity;
} Timer;

Timer CreateTimer(float);
void ResetTimer(Timer*, float);
void ZeroTimer(Timer *);
void UpdateTimer(Timer *);

Timer CreateTimer(float initialQuantity)
{
    return (Timer){initialQuantity};
}

void ResetTimer(Timer* timer, float quantity)
{
    timer->quantity = quantity;
}

void ZeroTimer(Timer * timer)
{
    timer->quantity = 0.0f;
}

void UpdateTimer(Timer *timer)
{
    timer->quantity -= GetFrameTime();
}
