#include <stdio.h>
#include <cs50.h>

/*
    Parâmetros do main
    int argc(Contagem de argumentos) -- Um número inteiro que vai representar o número de palavras que o usuário digita no prompt
    string argv(Vetor de argumento) --  Uma variável que armazena em um array todas as strings que o usuário digita no prompt do programa
*/

int main(int argc, string argv[])
{
    if(argc == 2) // Uma palavra é a o nome do programa executável para iniciar ele + a palavra que vc deseja, no caso o nome
    {
        printf("hello, %s\n", argv[1]); // o argv[0] -- É o nome do executável que o usuário digita no prompt
    }
    else
    {
        printf("Hello World!\n");
    }
}

// O main é do tipo int, pois retorna um inteiro, no caso 0 se a função não teve nenhum problema.