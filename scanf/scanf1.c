#include <stdio.h>
#include <stdlib.h>

int main() {
  int valor, valor2; // Criação de variáveis do tipo inteiro

  valor = 50; // Atribuir um valor para variável

  printf("Digite um valor inteiro: ");
  scanf("%d", &valor); // & referencia a região onde a variável está alocada

  printf("Digite um segundo valor inteiro: ");
  scanf("%d", &valor2);

  printf("\n\n Primeiro valor: %d \n Segundo valor: %d \n\n", valor, valor2);

  return 0;
}