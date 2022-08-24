#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int *v, int tamanho) { // Parâmetro como ponteiro do tipo inteiro "*v"
    int i;
    // Aritmética de ponteiros:
    for(i = 0; i < tamanho; i++) {
    printf("\n Aritmética de ponteiros: %d \n", *(v + i)); // Incrementa o endereço de memória e depois mostra o valor deste enreço com o *
    // Deste modo pode-se acessar todos os índices a partir do seu endereço com a aritmética de ponteiros, pois estamos percorrendo a partir dos ponteiros e não nos índices normalmente.
  }
}

void preencherVetorInt(int *v, int tam) {
  int i;
  for(i = 0; i < tam; i++) {
    printf("Digite um valor qualquer: ");
    scanf("%d", v + i); // Ponteiro do indice 0 mais o incremento do i
  }
}

int main() {
  int i, vet[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  printf("%p \t %p \n", vet, &vet[0]); // Ambos vão mostrar o endereço de memória, pois o vet sem o índice mostra o endereço de memória do índice 0.

  for(i = 0; i < 10; i++) {
    printf("%d \n", *vet); // Como so colocar vet, pega o endereço, o seu conteúdo é adquirido via índice ou *(ponteiro do valor)
    // Neste caso como estamos mostrando somente o valor de vet, sempre vai ser 0, pois o incremento está no "i"
  }

  preencherVetorInt(vet, 10); // Passagem de parâmetro por referência, pois é um ponteiro(uma seta que aponta a um endereço de memória), diferente de uma variável que é passagem de valor.
  imprimirVetor(vet, 10);
}