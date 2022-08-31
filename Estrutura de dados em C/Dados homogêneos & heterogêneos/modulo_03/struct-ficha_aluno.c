#include <stdio.h> // Funções de Input&Output nos dispositivos stdin, stdout e files
#include <conio.h> // Funções de manipulação de caracteres na tela

int main(void) {
  /*
    int matricula;
    char nome[50];
    float nota;

    float vnotas[20]; // Vetor de notas com 20 posições
    float mnotas[10][2]; // Matriz de 10 linhas e 2 colunas (10 alunos e 2 matérias)

    // Declaração da struct
    struct <identificador> {
      <listagem dos tipos e membros>
    };
  */

 struct ficha_aluno {
  int matricula;
  char nome[50];
  char disciplina[30];
  float nota;
 };

 // Declaração da variávrel aluno do tipo struct ficha_aluno
 struct ficha_aluno aluno;

  // Função printf -- impressão em tela
  // Função scanf -- Leitura de dados do teclado

  printf("\n Ficha do aluno \n");

  printf("Matricula do aluno: ");
  scanf("%d", &aluno.matricula);

  printf("Nome do aluno: ");
  scanf("%s", &aluno.nome);

  printf("Disciplina do aluno: ");
  scanf("%s", &aluno.disciplina);

  printf("Informe a nota do aluno: ");
  scanf("%f", &aluno.nota);

  printf("\n ----------------- Ficha Aluno ----------------- \n");

  printf("Matricula: %d\n", aluno.matricula);
  printf("Nome: %s\n", aluno.nome);
  printf("Disciplina: %s\n", aluno.disciplina);
  printf("Nota: %.2f\n", aluno.nota); // .2 para obrigar conter duas casas decimais somente, mesmo que seja inteiro

  system("PAUSE");
  return 0;
}