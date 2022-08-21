#include <stdio.h>

int main (void) {
  typedef struct {
    int dia;
    int mes;
    int ano;
  } Data;

  typedef struct {
    char rua[30];
    int numero;
    char bairro[30];
    char cidade[30];
    char estado[2];
    int cep
  } Endereco;

  struct ficha_aluno {
    int matricula;
    char nome[50];
    char disciplina[30];
    float nota;

    Data datanasc;
    Endereco endaluno;
  };

  struct ficha_aluno aluno[2];

  int i;

  printf("\n Ficha do Auno \n");

  for(i=0; i<2; i++) {
    printf("Matricula do aluno: ");
    scanf("%d", &aluno[i].matricula);

    printf("Nome do aluno: ");
    scanf("%s%*c", &aluno[i].nome);

    printf("Informe o endereço do aluno (Rua): ");
    scanf("%s%*c", &aluno[i].endaluno.rua);

    printf("Informe o endereço do aluno (Número): ");
    scanf("%s%*c", &aluno[i].endaluno.numero);

    printf("Informe o endereço do aluno (Bairro): ");
    scanf("%s%*c", &aluno[i].endaluno.bairro);

    printf("Informe o endereço do aluno (Cidade): ");
    scanf("%s%*c", &aluno[i].endaluno.cidade);

    printf("Informe o endereço do aluno (Estado): ");
    scanf("%s%*c", &aluno[i].endaluno.estado);

    printf("Informe o endereço do aluno (CEP): ");
    scanf("%s%*c", &aluno[i].endaluno.cep);

    printf("Informe a data de nascimento (Dia): ");
    scanf("%d%*c", &aluno[i].datanasc.dia);

    printf("Informe a data de nascimento (Mês): ");
    scanf("%d%*c", &aluno[i].datanasc.mes);

    printf("Informe a data de nascimento (Ano): ");
    scanf("%d%*c", &aluno[i].datanasc.ano);

    printf("Disciplina que está cursdando: ");
    scanf("%s%*c", &aluno[i].disciplina);

    printf("Informe a nota da disciplina: ");
    scanf("%d%*c", &aluno[i].nota);
  }

  for(i=0; i<2; i++) {
    printf("\n Ficha do Aluno \n");
    printf("Matrícula: %d\n", aluno[i].matricula);
    printf("Nome: %s\n", aluno[i].nome);
    printf("Endereço: %s, %d, Bairro %s, Cidade %s, CEP %d\n", aluno[i].endaluno.rua, aluno[i].endaluno.numero, aluno[i].endaluno.bairro, aluno[i].endaluno.cidade, aluno[i].endaluno.cep);
    printf("Data de nascimento: %d/%d/%d\n", aluno[i].datanasc.dia, aluno[i].datanasc.mes, aluno[i].datanasc.ano);
    printf("Disciplina: %s\n: ", aluno[i].disciplina);
    printf("Nota: %.2f\n\n", aluno[i].nota);
  }

  system("PAUSE");
  return 0;
};