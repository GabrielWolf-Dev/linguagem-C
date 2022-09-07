#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Número do Cartão: ");
    }
    while (card < 0);

    int algarism = 0;
    for (long i = card ; i > 0 ; i /= 10)
    {
        algarism++;
    }

    if (algarism < 13 || algarism > 16 || algarism == 14)
    {
        printf("INVALID\n");
        return 0;
    }

    int checksum = 0;

    for (long i = card / 10 ; i > 0 ; i /= 100)
    {
        int digit = i % 10;
        if (digit * 2 < 10)
        {
            checksum += (digit * 2);
        }
        else
        {
            checksum += ((digit * 2) % 10) + 1;
        }
    }

    for (long i = card ; i > 0 ; i /= 100)
    {
        int digit = i % 10;
        checksum += digit;
    }

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long first_digits = card;
    for (int i = algarism - 2 ; i > 0 ; i--)
    {
        first_digits /= 10;
    }

    if ((algarism == 15) && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
        return 0;
    }

    if ((algarism == 16) && (first_digits > 50 && first_digits < 56))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    if ((algarism == 13 || algarism == 16) && (first_digits / 10 == 4))
    {
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");
}