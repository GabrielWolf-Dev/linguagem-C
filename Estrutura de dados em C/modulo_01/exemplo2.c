#include <stdio.h>

/*
  Operador unário “&” ou ponteiro constante ‒ Tem a função de obter o endereço de memória de uma variável.
  Operador unário “*” de indireção ‒ É usado para fazer a deferência.
*/

int main(void) {
  int x = 5;
  int *pt_x;

  pt_x = &x;

  printf("Referenciando a variável x: %d\n", *pt_x);

  *pt_x = 50;

  printf("Varivável pt_x %d, variável x %d", *pt_x, x);
  return 0;
}