#include <cs50.h>
#include <stdio.h>

int getMaxHashes()
{
    int maxHashes;

    do
    {
        maxHashes = get_int("Heigth: ");
    }
    while (maxHashes < 1 || maxHashes > 8);

    return maxHashes;
}

int main(void)
{
    int maxHashes = getMaxHashes();


    for (int i = 0; i < maxHashes; i++)
    {
        for (int j = 1; j < maxHashes - i; j++)
        {
            printf(" ");
        }

        for (int j1 = 0; j1 < i + 1; j1++)
        {
            printf("#");
        }

        printf("\n");
    }
}