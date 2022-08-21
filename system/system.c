#include <stdio.h>
#include <stdlib.h>

// system("pause"); -- Funciona somente no Windows, então utilize a função abaixo para rodar em todos os navegadores, pois carrega as libs principais do compilador C.

int main() {
  // Faz toda a lógica do código e no final...

  printf("Pressione qualquer tecla para finalizar.");
  getchar(); // Pega qualquer tipo de caracter do teclado.

  return 0;
}