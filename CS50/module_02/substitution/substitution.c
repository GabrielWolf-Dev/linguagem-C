#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    for (int i = 0, argl = strlen(argv[1]); i < argl; i++)
    {
        if (argl != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        if (isdigit(argv[1][i]))
        {
            printf("Key must only contain alphabet characters.\n");
            return 1;
        }
    }

    for (int i = 0, argl = strlen(argv[1]); i < argl; i++)
    {
        for (int j = i + 1; argv[1][j] != '\0'; j++)
        {
            if (argv[1][j] == argv[1][i])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
            if (isalpha(argv[1][j]) == 0)
            {
                printf("Key must not contain special characters.\n");
                return 1;
            }
        }
    }

    string t = get_string("plaintext: ");
    int text = strlen(t);
    string cipher = t;
    string X = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string x = ("abcdefghijklmnopqrstuvwxyz");

    for (int i = 0; i < 1; i++)
    {
        for (int a = 0, argl = strlen(argv[1]); a < text; a++)
        {
            for (int b = 0; b < argl; b++)
            {
                if (X[b] == t[a])
                {
                    do
                    {
                        argv[1][b] = toupper(argv[1][b]);
                    }
                    while (islower(argv[1][b]));
                    {}
                    cipher[a] = argv[1][b];
                    break;
                }
                if (x[b] == t[a])
                {
                    do
                    {
                        argv[1][b] = tolower(argv[1][b]);
                    }
                    while (isupper(argv[1][b]));
                    {}
                    cipher[a] = argv[1][b];
                    break;
                }
            }
        }
    }
    printf("ciphertext: %s\n", cipher);

    return 0;
}