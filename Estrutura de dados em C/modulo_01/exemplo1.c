#include <stdio.h>

static int a = 0; // variável global, alocação estática
int d = 0; // variável global, alocação automática

void increment(void) {
  int b = 0; // variável local, alocação automática
  static int c = 0; // variável local, alocação estática

  printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d);
  a++;
  b++;
  c++;
  d++;
}

int main(void) {
  int i;
  for(i = 0; i < 5; i++)
  increment();
  system("pause");
  return(0);
}