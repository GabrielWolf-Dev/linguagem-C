#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b) {
  return (a + b);
};

void imprimirSoma(int value) {
  printf("A soma deu %d\n", value);
};

int main() {
  // Funções e procedimentos(Funções sem retorno)

  int total = soma(10, 5);
  imprimirSoma(total);
  return 0;
};

/*
  Função: As funções são procedimentos que retornam um único valor ao final de sua execução.
  Procedimentos: São estruturas que agrupam um conjunto de comandos, que são executados quando o procedimento é chamado, ou seja, procedimentos em linguagem C são funções do tipo void.

  O void é um tipo especial, utilizado principalmente em funções. Ele representa o “nada”, ou seja, uma variável desse tipo armazena conteúdo indeterminado, e uma função desse tipo retorna um conteúdo indeterminado.
*/