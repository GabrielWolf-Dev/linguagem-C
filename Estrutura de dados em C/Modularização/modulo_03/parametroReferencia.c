#include <stdio.h>
#include <stdlib.h>

/*
  Passagem de parâmetro por referência - É atribuído nos parâmetros da função a alocação de memória de cada variável passada no parâmetro, qe é gerenciado por meio dos ponteiro para alterar o valor original da variável e não criar outra variável com o valor modificado.
*/

void dobro(int *pt_num) {
  printf("Conteúdo da variável pt_num: %x \n", pt_num);

  *pt_num = *pt_num * 2;
}

int main(void) {
  int v_num;

  printf("Insira um número: ");
  scanf("%d", &v_num);

  printf("Antes de executar a função dobro \n");
  printf("Conteúdo da variável v_num: %d \n", v_num);
  printf("Endereço de memória da vrivável v_num: %x \n", &v_num);

  printf("Após a execução da função: \n");
  dobro(&v_num);
  printf("O dobro é: %d\n", v_num);

  system("Pause");
  return 0;
}