#include <stdio.h>
#include <string.h>
#include <cs50.h>

// strlen = variable.length || s[i] != '\0'(Pois o último "caracter" do array de strings é 0 em ASCII ou valor NULL para definir o final do array para o PC)

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32); // Pois a diferença entre letras maiúsculas e minúsculas do código ASCII é 32, ex: A - 65 decimal & a - 97 em decimal 97 - 65 = 32
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}