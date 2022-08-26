#include <stdio.h>
#include <stdlib.h>

int main() {
  int y = 0;
  short int x = 32767;

  printf("Tamanho de um int na memória: %d bytes\n", sizeof y);

  printf("Tamanho em memória de short: %d bytes\n", sizeof x);

  /*
    Operador short int otimiza a memória até 32.767, se for maior fica -32.768, pois 32.767 tem 15 casas decimais do binário, mas o último 16 é o sinal de positivo ou negativo, então tomar cuidado em não estourar a memória com esse operador.
    Segue o exemplo:
  */

  printf("\n======= Estouro de memória =======\n");
  printf("Valor de x: %d\n", x);
  x++;
  printf("Valor de x: %d\n", x);
 
  return 0;
}