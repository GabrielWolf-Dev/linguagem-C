#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, arg_len = strlen(argv[1]); i < arg_len; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string text = get_string("Texto: ");
    string cipher = text;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]) == 0)
        {
            cipher[i] = text[i];
        }
        else if (islower(text[i]))
        {
            cipher[i] -= 'a';
            cipher[i] = (cipher[i] + key) % 26;
            cipher[i] += 'a';
        }
        else
        {
            cipher[i] -= 'A';
            cipher[i] = (cipher[i] + key) % 26;
            cipher[i] += 'A';
        }

    }
    printf("ciphertext: %s\n", cipher);
}