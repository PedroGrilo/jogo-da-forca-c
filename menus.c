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

USERS data, p1, p2;

FILE *fout;
FILE *fin;

void menuPrincipal() {
  char op;
  int a;
  system("cls");
  printf("/*******************/\n");
  printf("/** Jogo da Forca **/\n");
  printf("/*******************/\n");
  printf("\n1. Entrar");
  printf("\n2. Registar");
  printf("\n0. Sair");
  printf("\n\nEscolha uma opcão: ");
  scanf(" %c", &op);
  switch (op) {
    case '1':
      loginMenu();
      break;
    case '2':
      menuNovoUtilizador();
      break;
    case '0':
      printf("\nVolte Sempre\n");
      exit(1);
  }

}

int vEspacos(char string[])  // verificação de espaços, ou enter's
{
  int i;
  int tst = 0;

  if (string[0] == '\0') {
    tst = 1;
  } else {
    for (i = 0; i < strlen(string); i++) {
      if (string[i] == 32) {
        tst = 1;
        break;
      } else
        tst = 0;
    }
  }
  if (tst == 1)
    return 1;
  else
    return 0;
}

void menuNovoUtilizador() {
  char nometemp[MAX_CHAR];
  char passtemp[MAX_CHAR];
  char passtemp2[MAX_CHAR];
  int pontos = 0;
  int pontosvspc = 0;
  int continuar;
  do {
    system("cls");
    printf("/************************************/\n");
    printf("/** Jogo da Forca - Novo utlizador **/\n");
    printf("/************************************/\n");
    if (vEspacos(nometemp) == 1) {
      printf("\nO nome de utilizador NÃO pode conter espaços\n");
    } else if (vEspacos(passtemp) == 1 || vEspacos(passtemp2) == 1) {
      printf("\nAs palavras-passes NÃO podem conter espaços\n");
    }
    printf("\nIntroduza o seu nome: ");
    fflush(stdin);
    gets(nometemp);
    printf("\nIntroduza a sua palavra-passe: ");
    fflush(stdin);
    gets(passtemp);
    printf("\nIntroduza a sua palavra-passe novamente: ");
    fflush(stdin);
    gets(passtemp2);
  } while (vEspacos(nometemp) == 1 || vEspacos(passtemp) == 1 ||
           vEspacos(passtemp2) == 1);

  animation("A registar");

  if (!strcmp(passtemp, passtemp2)) {
    fflush(stdin);
    fin = fopen("users.dat", "a+");

    int userex = 0;

    while (!feof(fin)) {
      fread(&p1, sizeof(USERS), 1, fin);
      if ((!strcmp(nometemp, p1.nome))) {
        userex = 1;
        break;
      }
    }

    fclose(fin);

    if (userex == 0) {
      fout = fopen("users.dat", "a+");

      strcpy(data.nome, nometemp);
      strcpy(data.pass, passtemp);
      data.pontos = pontos;
      data.pontosvspc = pontosvspc;
      data.jogadas = 0;
      data.jogadaspc = 0;
      fwrite(&data, sizeof(USERS), 1, fout);
      if (fwrite) {
        fclose(fout);
        printf(
            "\n\tRegistado com Sucesso, prima qualquer tecla para voltar ao "
            "menu principal.\n");
        getchar();
        menuPrincipal();
      }
    } else {
      fclose(fout);
      printf(
          "\n\tUtilizador ja existe, prima qualquer tecla para voltar ao menu "
          "principal.");
      getchar();
      menuPrincipal();
    }

  } else {
    printf(
        "\n\tPalavra-Passe não combinam, prima qualquer tecla para voltar ao "
        "menu principal.");
    getchar();
    menuPrincipal();
  }
}

int loginMenu() {
  char nometemp[MAX_CHAR];
  char passtemp[MAX_CHAR];
  int logged = 0;

  int continuar;
  do {
    system("cls");

    printf("/****************************/\n");
    printf("/** Jogo da Forca - Entrar **/\n");
    printf("/****************************/\n");

    if (vEspacos(nometemp) == 1) {
      printf("\nO nome de utilizador NÃO pode conter espaços\n");
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
  while (!feof(fin)) {
    fread(&p1, sizeof(USERS), 1, fin);
    if ((!strcmp(nometemp, p1.nome)) && (!strcmp(passtemp, p1.pass))) {
      logged = 1;
      break;
    }
  }
  fclose(fin);
  if (logged == 1) {
    printf("\n\tEntrou com sucesso na sua conta!\n");
    Sleep(800);
    menuForca(p1);
  } else {
    printf("\n\tSenha incorreta, tente novamente!\n");
    Sleep(800);
    menuPrincipal();
  }
}
int loginp2() {
  char nometemp[MAX_CHAR];
  char passtemp[MAX_CHAR];
  int logged = 0;
  int continuar;
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
    fread(&p2, sizeof(USERS), 1, fin);
    if ((!strcmp(nometemp, p2.nome)) && (!strcmp(passtemp, p2.pass))) {
      if ((strcmp(p2.nome, p1.nome))) {
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
void menuForca(USERS p1) {
  char op;

  system("cls");

  printf("/*******************/\n");
  printf("/** Jogo da Forca **/\n");
  printf("/*******************/\n");
  printf("\nBem vindo(a) %s", p1.nome);
  printf("\n1. P1 VS P2");
  printf("\n2. P1 VS PC");
  printf("\n3. Ver Ranking");
  printf("\n0. Sair ");
  printf("\n\nEscolha uma opção > ");
  fflush(stdin);
  op = getchar();
  switch (op) {
    case '1':
      if (loginp2() == 1)
        words(p1, p2);
      else
        menuForca(p1);
      break;
    case '2':
      wordspc(p1);
      break;
    case '3':
      ranking(p1);
      break;
    case '0':
      menuPrincipal();
      break;
    default:
      printf("\nOpção Errada!Qualquer tecla para tentar novamente\n");
      fflush(stdin);
      getchar();
      menuForca(p1);
  }
}
void ranking(USERS p1) {
  char op = '0';

  system("cls");
  printf("/*******************/\n");
  printf("/***** Ranking *****/\n");
  printf("/*******************/\n");
  printf("\n1. Ver ranking P1 VS P2");
  printf("\n2. Ver ranking P1 VS PC");
  printf("\n0. Voltar");
  printf("\n\nEscolha uma opção >");
  fflush(stdin);
  scanf("%c", &op);

  switch (op) {
    case '1':
      rankpvp(p1);
      break;
    case '2':
      rankpvc(p1);
      break;
    case '0':
      menuForca(p1);
      break;
    default:
      ranking(p1);
  }
}

void rankpvp(USERS p1) {
  int i = 0;
  typedef struct {
    char nome[21];
    char pass[21];
    int pontos;
    int pontosvspc;
    int jogadas;
    int jogadaspc;
  } reader;

  reader data, buffer[200], temp;

  FILE *getpoints;

  getpoints = fopen("users.dat", "rb");

  if (getpoints == NULL)  // verifica se o ficheiro existe na pasta
  {
    printf("Erro ao abrir ficheiro, saia do jogo e volte a inicia-lo\n\n");
    getchar();
  } else {
    long int recsize;

    system("cls");
    printf("/************************************/\n");
    printf("/******** Ranking P1 VS P2 **********/\n");
    printf("/************************************/\n");
    printf("\n    Nome      |NºJogos| Pontos:\n");
    printf("\n    %-10s |  %d  | %04d \n\n", p1.nome, p1.jogadas, p1.pontos);
    printf("************ HIGHSCORES *************\n\n");

    rewind(getpoints);
    strcpy(data.nome, p2.nome);
    strcpy(data.pass, p2.pass);

    recsize = sizeof(reader);

    while (!feof(getpoints)) {
      if (!(fread(&data, recsize, 1, getpoints))) {
        break;
      } else {
        buffer[i] = data;
      }
      i++;
    }

    // bubble sort - ordenaçao no ranking por pontos e jogadas

    for (int n = 0; n < i - 1; n++) {
      for (int t = 0; t < (i - 1 - n); t++) {
        if (buffer[t].pontos < buffer[t + 1].pontos) {
          temp = buffer[t];
          buffer[t] = buffer[t + 1];
          buffer[t + 1] = temp;
        }

        if ((buffer[t].pontos == buffer[t + 1].pontos) &&
            (buffer[t].jogadas > buffer[t + 1].jogadas)) {
          temp = buffer[t];
          buffer[t] = buffer[t + 1];
          buffer[t + 1] = temp;
        }
      }
    }
    for (int x = 0; x < i; x++)  // printf dos dados dos utilizadores
      printf(" %d. %-10s |  %d  | %04d \n", x + 1, buffer[x].nome,
             buffer[x].jogadas, buffer[x].pontos);

    fclose(getpoints);
    printf("\n************************************\n");
    system("pause");
    ranking(p1);
  }
}

void rankpvc(USERS p1) {
  int i = 0;
  typedef struct {
    char nome[21];
    char pass[21];
    int pontos;
    int pontosvspc;
    int jogadas;
    int jogadaspc;
  } reader;
  reader data, buffer[200], temp;

  FILE *getpoints;

  getpoints = fopen("users.dat", "rb");

  if (getpoints == NULL)  // verifica se o ficheiro existe na pasta
  {
    printf("Erro ao abrir ficheiro, saia do jogo e volte a inicia-lo\n\n");
    getchar();
  } else {
    long int recsize;

    system("cls");
    printf("/************************************/\n");
    printf("/******** Ranking P1 VS PC **********/\n");
    printf("/************************************/\n");
    printf("\n    Nome      |NºJogos| Pontos:\n");
    printf("\n    %-10s |  %d  | %04d \n\n", p1.nome, p1.jogadaspc,
           p1.pontosvspc);
    printf("************ HIGHSCORES *************\n\n");

    rewind(getpoints);
    strcpy(data.nome, p2.nome);
    strcpy(data.pass, p2.pass);

    recsize = sizeof(reader);

    while (!feof(getpoints)) {
      if (!(fread(&data, recsize, 1, getpoints))) {
        break;
      } else {
        buffer[i] = data;
      }
      i++;
    }

    // bubble sort - ordenaçao no ranking por pontos e jogadaspc

    for (int n = 0; n < i - 1; n++) {
      for (int t = 0; t < (i - 1 - n); t++) {
        if (buffer[t].pontosvspc < buffer[t + 1].pontosvspc) {
          temp = buffer[t];
          buffer[t] = buffer[t + 1];
          buffer[t + 1] = temp;
        }

        if ((buffer[t].pontosvspc == buffer[t + 1].pontosvspc) &&
            (buffer[t].jogadaspc > buffer[t + 1].jogadaspc)) {
          temp = buffer[t];
          buffer[t] = buffer[t + 1];
          buffer[t + 1] = temp;
        }
      }
    }
    for (int x = 0; x < i; x++)  // printf dos dados dos utilizadores
      printf(" %d. %-10s |  %d  | %04d \n", x + 1, buffer[x].nome,
             buffer[x].jogadaspc, buffer[x].pontosvspc);

    fclose(getpoints);
    printf("\n************************************\n");
    system("pause");
    ranking(p1);
  }
}
