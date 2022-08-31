#include <stdio.h>
#include <stdlib.h>

int main() {
  float x = 3.1415; // Precisão simples de valor
  double y = 3.1415545468897; // Precisão dupla, mais precisa que o float nas casas decimais.

  printf("Um float precisa de %d bytes de memória.\n", sizeof x);

  printf("Um double precisa de %d bytes de memória.\n", sizeof y);

  // No float não é pssível inserir long e nem short
  return 0;
}