#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}

// O main é do tipo int, pois retorna um inteiro, no caso 0 se a função não teve nenhum problema.
// Para verificar a saída de valores do retorno, basta rodar o programa e digitar o comando "echo $?"