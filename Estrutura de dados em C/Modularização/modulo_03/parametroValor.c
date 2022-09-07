#include <stdio.h>
#include <stdlib.h>

/*
  Passagem por parâmetro de valor, onde as são criados/atribuidos cópias das variáveis originais nos parametros da função.
*/

int soma(int x, int y) {
  return x + y;
}

int main(void) {
  int num1, num2, total;

  printf("Digite um número: ");
  scanf("%d", &num1);

  printf("Digite outro número: ");
  scanf("%d", &num2);

  total = soma(num1, num2);

  printf("Soma de %d + %d é %d \n", num1, num2, total);

  system("Pause");
  return 0;
}