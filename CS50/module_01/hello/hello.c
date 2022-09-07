#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int main(void) {
    string name = get_string("Qual é o seu nome?\n");
    // get_string é uma função específica da biblioteca do CS50!
    printf("Olá %s!\n", name);
}