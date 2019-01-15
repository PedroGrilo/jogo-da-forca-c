#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxforca 100
typedef struct {
  char nome[21];
  char pass[21];
  int pontos;
  int pontosvspc;
  int jogadas;
  int jogadaspc;
} USERS;

loginMenu();
int isvogal(char letra)  // verificar se Ã© vogal
{
  if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
    return 1;
  else
    return 0;
}

void header(char nome[], char msg[], int vidas, char tentativas[], int i) {
  int k = 0;
  system("cls");
  printf("/**********************************/\n");
  printf("/** Jogo da Forca - Player %-06s**/\n", nome);
  printf("/**********************************/\n");
  vida(vidas);
  printf("\nLetras ja usadas: ");
  for (k = 0; k < i; k++) printf("%c ", tentativas[k]);
  printf("\n");
  puts(msg);
}

void words(USERS p1, USERS p2) {
  // player 1, introduzir a palavra/frase para o player 2;
  char repetir, forca[maxforca], frase[maxforca], msg[maxforca] = {};
  int i = 0, k = 0;
  do {
    system("cls");
    do {
      printf("/**********************************/\n");
      printf("/** Jogo da Forca - Player %-06s**/\n", p1.nome);
      printf("/**********************************/\n");

      printf("Introduza a sua palavra/frase > ");
      fflush(stdin);
      gets(forca);
      system("cls");
    } while (verificacoes(forca));
    i = strlen(forca);
    system("cls");

    for (k = 0; k < i; k++) {
      // criar uma variavel, com os underscores correspondentes Ã  frase
      // introduzida.

      if (verificacoes(forca) == 0) {
        if (forca[k] == ' ') {
          fflush(stdin);
          frase[k] = ' ';
        } else {
          fflush(stdin);
          frase[k] = '_';
        }
      }
    }
    frase[k] = '\0';
    printf("Frase: %s\n\n", forca);
    printf("Deseja alterar a frase? [S/N]\n");
    fflush(stdin);
    scanf("%c", &repetir);
  } while (tolower(repetir) == 's');
  system("cls");
  guesser(forca, frase, p2, p1);
}
void guesser(char forca[maxforca], char frase[maxforca], USERS p2, USERS p1) {
  // player 2, adivinhar a palavra/frase do player 1

  char tentativa[26], falhas[6], msg[maxforca] = {}, voltar;
  int i = 0, k = 0,g, samechar = 0, guesssize = strlen(forca), falha = 1,falhascount = 0, counter = 0;

  do {
    fflush(stdin);
    if (samechar != 1) system("cls");
    if (falhascount != 7 && falhascount != 6)
      header(p2.nome, msg, falhascount, tentativa, i);
    fflush(stdin);

    for (g = 0; i < guesssize; i++) printf("%c ", frase[i]);
    if (falhascount != 7 && falhascount != 6) {
      puts("\n\nIntroduza uma letra (0-Desistir) > ");  // desistir do jogo
      fflush(stdin);
      scanf("%c", &tentativa[i]);
      strcpy(msg, "");
      if (i < 2 && isvogal(tentativa[i])) {
        system("cls");
        strcpy(msg,
               "\nNÃO sao aceites vogais até à terceira ronda, tente novamente!\n");
        continue;
      }

      if (isdigit(tentativa[i])) {
        if (tentativa[i] != '0') {
          system("cls");
          strcpy(msg, "\nNÃO são aceites numeros, tente novamente!\n");
          continue;
        } else {
          system("cls");
          strcpy(msg, "\n");
          falhascount = 7;
          continue;
        }
      }
      if (tentativa[i] == ' ') {
        system("cls");
        strcpy(msg, "\nNÃO são aceites espacos, tente novamente!\n");

        continue;
      } else if (!((tolower(tentativa[i]) >= 97 &&
                    tolower(tentativa[i]) <= 122) ||
                   tentativa[i] == 32)) {
        system("cls");
        strcpy(msg,
               "\nNÃO são aceites caracteres especiais, tente novamente!\n");

        continue;
      } else {
        for (k = 0; k < i; k++) {
          if (tolower(tentativa[i]) == tolower(tentativa[k])) {
            system("cls");
            strcpy(msg, "\nERRO: Esse caracter já foi introduzido\n");
            i--;
            samechar = 1;
            continue;

          } else {
            samechar = 0;
          }
        }
      }
      falha = 1;

      if (samechar == 0) {
        for (k = 0; k < guesssize; k++) {
          if (tolower(tentativa[i]) == tolower(forca[k])) {
            frase[k] = tolower(tentativa[i]);
            falha = 0;
          }
        }
        if (falha == 1 && falhascount < 6 && samechar == 0)  // player 1
        {
          falhas[falhascount] = tentativa[i];
          falhascount++;
        } else if (falhascount > 6) {
          system("cls");
          header(p1.nome, msg, 7, tentativa, i);
          printf("Perdeu o jogo (%s) a o Player '%s' !!\n", p1.nome, p2.nome);
          printf("\n\nDeseja voltar ao menu?[S/N]");
          getchar();
          scanf(" %c", &voltar);
          if (tolower(voltar) == 's')
            menuForca(p1);
          else
            printf("\nVolte sempre");
          exit(1);
        }
        if (strcmp(forca, frase) == 0)  // player 2
        {
          system("cls");
          header(p2.nome, msg, 8, tentativa, i);
          printf("Ganhou o jogo (%s) contra o Player '%s' !!\n\n", p2.nome,
                 p1.nome);
          savepoints(falhascount, p2, guesssize);
          printf("\nDeseja voltar ao menu?[S/N]");
          fflush(stdin);
          scanf(" %c", &voltar);
          if (tolower(voltar) == 's')
            menuForca(p1);
          else
            printf("Volte sempre\n");
          exit(1);
        }
      }
      i++;
    } else {
      system("cls");
      header(p1.nome, msg, 7, tentativa, i);
      printf("Perdeu o jogo (%s) contra o Player '%s' !!\n", p1.nome, p2.nome);
      printf("\n\nDeseja voltar ao menu?[S/N]");
      fflush(stdin);
      scanf(" %c", &voltar);
      if (tolower(voltar) == 's')
        menuForca(p1);
      else
        printf("\nVolte sempre");
      exit(1);
    }
  } while (i < 26);
}
void savepoints(int erros, USERS p2, int stringlength) {
  typedef struct {
    char nome[21];
    char pass[21];
    int pontos;
    int pontosvspc;
    int jogadas;
    int jogadaspc;
  } reader;
  reader usersubdata, buffer;

  FILE* getpoints;
  long int recsize;
  usersubdata.pontos = p2.pontos;
  switch (erros) {
    case 0:
      printf("Ganhou: %d pontos\n", (10));
      usersubdata.pontos += (10);
      break;
    case 1:
      printf("Ganhou: %d pontos\n", (8));
      usersubdata.pontos += (8);
      break;
    case 2:
      printf("Ganhou: %d pontos\n", (6));
      usersubdata.pontos += (6);
      break;
    case 3:
      printf("Ganhou: %d pontos\n", (4));
      usersubdata.pontos += (4);
      break;
    case 4:
      printf("Ganhou: %d pontos\n", (3));
      usersubdata.pontos += (3);
      break;
    case 5:
      printf("Ganhou: %ed pontos\n", (2));
      usersubdata.pontos += (2);
      break;
    default:
      printf("Ganhou: %d pontos\n", (0));
      usersubdata.pontos += (0);
      break;
  }

  printf("Para um total de: %d pontos!", usersubdata.pontos);
  getpoints = fopen("users.dat", "rb+");
  rewind(getpoints);
  strcpy(usersubdata.nome, p2.nome);
  strcpy(usersubdata.pass, p2.pass);
  usersubdata.pontosvspc = p2.pontosvspc;
  usersubdata.jogadas = p2.jogadas + 1;
  usersubdata.jogadaspc = p2.jogadaspc;

  recsize = sizeof(reader);
  while (fread(&buffer, recsize, 1, getpoints) == 1) {
    if (strcmp(buffer.nome, p2.nome) == 0) {
      fseek(getpoints, -recsize, SEEK_CUR);
      fflush(getpoints);
      fwrite(&usersubdata, recsize, 1, getpoints);
      break;
    }
  }
  fclose(getpoints);
}

int verificacoes(char nome[])  // verifica se a frase que o player 1 introduz,
                               // tÃªm pelo menos 3 caracteres, nÃ£o conter
                               // espaÃ§os inciais e caracteres especiais
{
    int i;

  if (strlen(nome) < 3) {
    printf("A frase NÃO pode conter menos de 3 caracteres\n\n");
    return 1;
  } else if (nome[0] == 32) {
    printf("A frase NÃO pode conter espaços iniciais\n\n");
    return 1;
  } else {
    int tst = 0;

    for ( i = 0; i < strlen(nome); i++) {
      if ((nome[i] >= 97 && nome[i] <= 122) || (nome[i] >= 65 && nome[i] <= 90) || nome[i] == 32) {
        tst = 0;
      } else {
        tst = 1;
        break;
      }
    }

    if (tst == 1) {
      printf("A frase SÓ pode conter letras.\n\n");
      return 1;
    } else
      return 0;
  }
}
