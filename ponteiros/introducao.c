#include <stdio.h>
#include <stdlib.h>

int main() {
  int *valor1, valor2 = 50;
  // variável valor2 é do tipo inteiro e recebe o valor 50;
  // variável valor1 é do tipo ponteiro, onde não armazena um valor e sim um Endereço de Memória
  char *letra1, letra2 = 'g';
  // Já letra1 é um ponteiro para o tipo caracter

  // valor1 = valor2; -- Da um erro lógico, pois valor um é um ponteiro e precisa do endenreço de memória da variável valor2 para atribuir o seu valor
  valor1 = &valor2; // valor1 que é um ponteiro está armazenando o endereço de memória(&) do valor2
  letra1 = &letra2;

  // "%p" -- Para ponteiro/endereço
  printf("Valor da variável valor2: %d \n", valor2);
  printf("Endereço da variável valor2: %p \n", &valor2);
  printf("Conteúdo da variável valor1: %p \n", valor1);
  printf("Conteúdo apontado pela variável valor1: %d \n", *valor1);

  printf("\n ----------------------------- \n");

  printf("Valor da variável letra2: %c \n", letra2);
  printf("Endereço da variável letra2: %p \n", &letra2);
  printf("Conteúdo da variável letra1: %p \n", letra1);
  printf("Conteúdo apontado pela variável letra1: %c \n", *letra1);

  
  return 0;
}