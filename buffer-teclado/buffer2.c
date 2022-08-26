#include <stdio.h>
#include <stdlib.h>

int main() {
  char a, b;

  // Limpando um caracter:
  printf("Digite uma letra: ");
  scanf("%c", &a); // Quando adicionamos o primeiro caracter e pressiona o ESPAÇO ou ENTER essas teclas são lidas como caracter no buffer, então sempre dê espaço após cada scanf seguinte.

  // Outra alternativa é fazer a leitura novamente do scanf("%c");

  printf("Digite uma letra: ");
  scanf(" %c", &b);

  printf("Primeira letra: %c\n Segunda letra: %c\n", a, b);

  return 0;
}