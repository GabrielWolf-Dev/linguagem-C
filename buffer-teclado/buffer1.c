#include <stdio.h>
#include <stdlib.h>

int main() {
  char a, b;

  // Limpando conjunto de caracteres:
  printf("Digite duas letras: ");
  scanf("%c %c", &a, &b); // De uma espaço para desconsiderar a atribuição de um enter, tab, \n como buffer no valor da variável.

  // Espaço entre os %c -- comando para o computador desconsiderar o ENTER, TAB, ESPAÇO
  // fflush(); -- Função somente no Windows, lib externa que não é do C e não funcione em todos os casos. Essa função serve para limpar o buffer tbm.
  printf("Primeira letra: %c\n Segunda letra: %c\n", a, b);

  return 0;
}