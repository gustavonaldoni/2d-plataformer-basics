bool RandomProbabilityManipulation(int);
int GenerateRandomNumber(int, int);

bool RandomProbabilityManipulation(int percentage)
{
    int n;
    
    n = (rand() % 100) + 1;
    
    return n <= percentage;
}

int GenerateRandomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}