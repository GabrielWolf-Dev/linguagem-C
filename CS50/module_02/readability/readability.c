#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string t = get_string("Please Write your text here: ");
    int n = strlen(t);
    int l = 0;
    int w = 0;
    int c = 0;
    int s = 0;
    float index = 0;
    float L = 0;
    float S = 0;

    for (int i = 0; i < n; i++)
    {
        if (isalpha(t[i]))
        {
            l++;
        }
        if (isspace(t[i]))
        {
            c++;
            w = c + 1;
        }
        if (t[i] == '.' || t[i] == '!' || t[i] == '?')
        {
            s++;
        }
    }
    
    L = ((float) l * 100 / (float) w);
    S = ((float) s * 100 / (float) w);

    index = ((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        index = 1;
        printf("Before Grade %i\n", (int) index);
    }
    else if (index >= 16)
    {
        index = 16;
        printf("Grade %i+\n", (int) index);
    }
    else if (index == 7.53)
    {
        index = 7;
        printf("Grade %i\n", (int) index);
    }
    else if (index <= 15)
    {
        index = round(index * 1);
        printf("Grade %i\n", (int) index);
    }
}