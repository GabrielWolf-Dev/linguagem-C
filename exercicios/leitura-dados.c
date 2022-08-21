#include <stdlib.h>
#include <stdio.h>

int main() {
  char sexo;
  int idade;
  float peso, altura;

  printf("Digite o sexo(F ou M), idade, peso e altura: \n");
  scanf("%c%d%f%f", &sexo, &idade, &peso, &altura);

  printf("Sexo: %c \n Idade: %d \n Peso: %.1f \n Altura: %.2f \n", sexo, idade, peso, altura);

  return 0;
}