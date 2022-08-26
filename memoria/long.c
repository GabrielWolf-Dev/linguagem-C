#include <stdio.h>
#include <stdlib.h>

/*
  Os operadores long, short, etc... Que gerenciam e otimizam a manipulação da memória entre variáveis dependen muito da arquitetura de cada computador!
*/

int main() {
  long int x = 2147483647; // Normalmente, o valor máximo que a variável consegue alocar de memória. Pode ocorrer, mesmo com o "long" estourar a memória, pois depende de cada máquina.
 
  printf("Tamanho de x em bytes: %d\n", sizeof x);
  
  printf("Valor de x: %d\n", x);
  x++;
  printf("Valor de x: %d\n", x); // No meu pc não tem diferença colocar um long e normalmente não vai ter mesmo na grande maioria dos PC's. Mas podemos utilizar "long long variável".

  long long y = 2147483647;

  printf("Tamanho de y em bytes: %d\n", sizeof y); // Ocupa 8 bytes de memória, 64 bits, e aparentemente parece estar dando estouro de memória se imprimir com "%d", pois o correto é imprimir com "%li ou %ld"
  
  printf("Valor de y: %d\n", y);
  y++;
  printf("Valor de y: %d\n", y);

  printf("Valor de y(com li ou ld): %lli\n", y);
  y++; // Como é dois long, então se insere ll + int == lli
  printf("Valor de y(com li ou ld): %lld\n", y);

  // No short não é possível replicar para ultrapasar o limite padrão, e no caso do long é somente duas vezes(long long)
  return 0;
}