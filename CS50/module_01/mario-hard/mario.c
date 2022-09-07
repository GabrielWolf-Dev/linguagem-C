#include <stdio.h>
#include <cs50.h>

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
    int hash = 1;
    int maxHashes = getMaxHashes();

    do
    {


        for (int dots = maxHashes; hash <= dots - 1; dots--)
        {
            if (maxHashes != 1)
            {
                printf(" ");
            }
        }

        for (int iHash = 1; iHash <= hash; iHash++)
        {
            printf("#");
        }

        printf("  ");

        for (int iHash = 1; iHash <= hash; iHash++)
        {
            printf("#");
        }

        printf("\n");
        hash++;
    }
    while (hash <= maxHashes);
}