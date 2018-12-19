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
    do{
        if(repetir=='r')
            printf("Verifique que a frase nao contem números nem começa por um espaço nem tem caracteres especiais\n\n");
        repetir = '\0';
        printf("Introduza a sua palavra/frase > ");
        fflush(stdin);
        gets(forca);
    }while(forca[0]=='\0');

    i = strlen(forca);
    system("cls");
    do{
        if(forca[0]==' '){
            repetir='r';
            break;
        }else if(forca[k] >= '0' && forca[k] <= '9'){
            repetir='r';
            k++;
            break;
        }else if((forca[k] >= 'a' && forca[k] <= 'z') || (forca[k] >= 'A' && forca[k] <= 'Z')){
            if(forca[k]==' '){
                frase[k]=' ';
            }else{
                frase[k]='_';
            }

        }else{
            repetir='r';
            k++;
            break;
        }
        k++;
    }while(k<i);
    printf("Frase: %s\n\n", forca);
    printf("Deseja alterar a frase? [S/N]\n");
    fflush(stdin);
    do{
    repetir=getchar();}while(tolower(repetir)=='r');
  }while (tolower(repetir) == 's' || tolower(repetir)=='r');
  system("cls");
  //guesser(forca, frase, p2, p1);
  for(k=0;k<i;k++){
    printf("%c",forca[k]);
  }
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

     if(tentativa[0]==32){
            system("cls");
            strcpy(msg, "\nNao sao aceites espacos, tente novamente!\n");
            i--;
            continue;
        }else if(tentativa[i] >= '0' && tentativa[i] <= '9'){
            system("cls");
            strcpy(msg, "\nNao sao aceites numeros, tente novamente!\n");
            i--;
            continue;
        }else if(!((tentativa[i] >= 'a' && tentativa[i] <= 'z') || (tentativa[i] >= 'A' && tentativa[i] <= 'Z'))){
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
