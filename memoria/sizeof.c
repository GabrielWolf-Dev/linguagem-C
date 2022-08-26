#include <stdio.h>
#include <stdlib.h>

/*
8 bits -- 1 byte
1024 bytes -- 1 Kilobyte
1024 Kilobytes -- 1 Megabyte
1024 Megabytes -- 1 Gigabyte
1024 Gigabytes -- 1 Terabyte
1024 Terabytes -- 1 Petabyte
1024 Petabytes -- 1 Exabyte
1024 Exabytes -- 1 Zettabyte
1024 Zettabytes -- 1 Yottabyte
*/

int main() {
  int bits = 8;
  float x = 1.0;

  printf("Tamanho de um float na memória: %d bytes\n", sizeof x);

  printf("Tamanho em memória de int: %d bytes\nOu seja, contém %d bits(8 * 4)", sizeof(int), sizeof(int) * bits);

  return 0;
}