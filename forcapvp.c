#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  typedef struct {
    char nome[21];
    char pass[21];
    int pontos;
  }
USERS;

loginMenu();

void header(char nome[], char msg[], int vidas) {
  system("cls");
  printf("/**********************************/\n");
  printf("/** Jogo da Forca - Player %-06s**/\n", nome);
  printf("/**********************************/\n");
  vida(vidas);
  puts(msg);

}
void words(USERS p1, USERS p2) {
  char repetir, forca[100], frase[100], msg[100] = {};
  int i = 0, k = 0;
  do {
    system("cls");
    printf("/**********************************/\n");
    printf("/** Jogo da Forca - Player %-06s**/\n", p1.nome);
    printf("/**********************************/\n");
    if (repetir == 'r' && forca[0] == 0) {
      printf("Não são aceites números, tente novamente!\n\n");
    }
    repetir = '\0';
    printf("Introduza a sua palavra/frase > ");
    fflush(stdin);
    gets(forca);
    i = strlen(forca);
    system("cls");
    do {
      if (isdigit(forca[i])) {
        system("cls");
        strcpy(msg, "\nNao sao aceites numeros, tente novamente!\n");
        forca[0] = '\0';
        repetir = 'r';
        break;
      } else if (forca[i] == 32) {
        system("cls");
        printf("\nNao sao aceites espacos, tente novamente!\n");
        forca[0] = '\0';
        repetir = 'r';
        break;
      } else if (forca[i] == '\n') {
        system("cls");
        printf("\nNao introduziu nenhuma letra, tente novamente!\n");
        forca[0] = '\0';
        repetir = 'r';
        break;
      } else {
        if (forca[k] == ' ') {
          frase[k] = ' ';
        }
        //            else if(forca[k]<='9'&&forca[k]>='0')
        //            {
        //                forca[0] = '\0';
        //                repetir='r';
        //                break;
        //            }
        else {
          frase[k] = '_';
        }
      }
      k++;
    }
    while (k < i);
    frase[k] = '\0';
    printf("Frase: %s\n\n", forca);
    if (repetir != 'r') {
      puts("Deseja alterar a sua frase?[S/N]");
      scanf(" %c", & repetir);
    }
  }
  while (tolower(repetir) == 's');
  system("cls");
  guesser(forca, frase, p2, p1);
  puts("");
}

void guesser(char forca[100], char frase[100], USERS p2, USERS p1) {

  char tentativa[26], falhas[6], msg[100] = {}, voltar;
  int i = 0, k = 0, samechar = 0, guesssize = strlen(forca), falha = 1, falhascount = 0, counter = 0;

  do {
    if (samechar != 1)
      system("cls");

    header(p2.nome, msg, falhascount);
    fflush(stdin);

    for (int i = 0; i < guesssize; i++)
      printf("%c ", frase[i]);

    puts("\n\nIntroduza uma letra > ");
    fflush(stdin);
    tentativa[i] = getchar();
    strcpy(msg, "");

    if (isdigit(tentativa[i])) {
      system("cls");
      strcpy(msg, "\nNao sao aceites numeros, tente novamente!\n");
      i--;
      continue;
    } else if (tentativa[i] == 32) {
      system("cls");
      strcpy(msg, "\nNao sao aceites espacos, tente novamente!\n");
      i--;
      continue;
    } else if (tentativa[i] == '\n') {
      system("cls");
      strcpy(msg, "\nNao introduziu nenhuma letra, tente novamente!\n");
      i--;
      continue;
    }

    falha = 1;
    for (k = 0; k < i; k++) {
      if (tentativa[i] == tentativa[k]) {
        system("cls");
        strcpy(msg, "\nERRO: Esse caracter já foi introduzido\n");
        i--;
        samechar = 1;
        continue;

      } else {
        samechar = 0;
      }

    }
    if (samechar == 0) {
      for (k = 0; k < guesssize; k++) {
        if (tolower(tentativa[i]) == tolower(forca[k])) {
          frase[k] = tolower(tentativa[i]);
          falha = 0;
        }
      }
      if (falha == 1 && falhascount < 5 && samechar == 0) //player 1
      {
        falhas[falhascount] = tentativa[i];
        falhascount++;
      } else if (falhascount >= 5) {
        system("cls");
        header(p1.nome, msg, 7);
        printf("Perdeu o jogo (%s) contra o Player '%s' !!\n", p1.nome, p2.nome);
        printf("\n\nDeseja voltar ao menu?[S/N]");
        getchar();
        scanf(" %c", & voltar);
        if (tolower(voltar) == 's')
          menuForca(p2.nome);
        else
          printf("\nVolte sempre");
        exit(1);
      }
      if (strcmp(forca, frase) == 0) //player 2
      {
        system("cls");
        header(p2.nome, msg, 8);
        printf("Ganhou o jogo (%s) contra o Player '%s' !!\n Ganhou ", p2.nome, p1.nome);
        savepoints(falhascount,p2); //mudar
        printf("\nDeseja voltar ao menu?[S/N]");
        getchar();
        scanf(" %c", & voltar);
        if (tolower(voltar) == 's')
          menuForca(p1);
        else
          printf("Volte sempre\n");
        exit(1);
      }
    }
    i++;
  }
  while (i < 26);
}

void savepoints(int erros, USERS p2){

  FILE * getpoints;

  int pontos[7] = {10,8,6,4,3,2,0};

    switch (erros)
{
case 0:
    printf("10 pontos\n");
    p2.pontos += 10;
    break;
case 1:
    printf("8 pontos\n");
    p2.pontos += 8;
    break;
case 2:
    printf("6 pontos\n");
    p2.pontos += 6;
    break;
case 3:
    printf("4 pontos\n");
    p2.pontos += 4;
    break;
case 4:
    printf("3 pontos\n");
    p2.pontos += 3;
    break;
case 5:
    printf("2 pontos\n");
    p2.pontos += 2;
    break;
default:
    printf("0 pontos\n");
    }
}
