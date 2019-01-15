#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <locale.h>
#define MAX_CHAR 21

typedef struct {
  char nome[MAX_CHAR];
  char pass[MAX_CHAR];
  int pontos;
  int pontosvspc;
  int jogadas;
  int jogadaspc;
} USERS;

int userdatalogin(USERS p1) {
    USERS p1temp;
  char nometemp[MAX_CHAR];
  char passtemp[MAX_CHAR];
  int logged = 0;
  int continuar;
  FILE *fin;
  do {
    system("cls");
    printf("/*************************************/\n");
    printf("/** Jogo da Forca - Entrar Player 2 **/\n");
    printf("/*************************************/\n");
    if (vEspacos(nometemp) == 1) {
      printf("\nO nome NÃO pode conter espaços\n");
    } else if (vEspacos(passtemp) == 1) {
      printf("\nA palavra-passe NÃO pode conter espaços\n");
    }
    printf("\nIntroduza o seu nome: ");
    fflush(stdin);
    gets(nometemp);
    printf("\nIntroduza a sua palavra-passe: ");
    fflush(stdin);
    gets(passtemp);
    fflush(stdin);
  } while (vEspacos(nometemp) == 1 || vEspacos(passtemp) == 1);

  fin = fopen("users.dat", "ab+");

  animation("A verificar se está correta");
  while (!feof(fin))  // Percorre o ficheiro e armazena na estrutura
  {
    fread(&p1temp, sizeof(USERS), 1, fin);
    if ((!strcmp(nometemp, p1temp.nome)) && (!strcmp(passtemp, p1temp.pass))) {
      if ((strcmp(p1temp.nome, p1.nome))) {
        logged = 1;
        break;
      } else {
        logged = 2;
      }
    }
  }
  fclose(fin);
  if (logged == 1) {
    printf("\n\tEntrou com sucesso na sua conta!\n");
    Sleep(1000);
    return 1;
  } else if (logged == 2) {
    printf("\n\tA conta nao pode ser a mesma do player 1...");
    Sleep(1000);
    return 0;
  } else {
    printf("\n\tSenha incorreta, tente novamente!\n");
    Sleep(1000);
    return 0;
  }
}
