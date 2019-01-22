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



void userdatamenu(USERS p1){
    char op;
    int a;
    system("cls");
    printf("/***************************************/\n");
    printf("/** Jogo da Forca - Editar Informa��o **/\n");
    printf("/***************************************/\n");
    printf("\n1. Alterar password");
    printf("\n2. Alterar nome de utilizador");
    printf("\n3. Redefinir pontos");
    printf("\n4. Apagar conta");
    printf("\n0. Sair");
    printf("\n\nEscolha uma opc�o: ");
    scanf(" %c", &op);
    switch (op) {
        case '1':
            altpass(p1);
        break;
        case '2':
            altnom(p1);
        break;
        case '3':
            altpoints(p1);
        break;
        case '4':
            deleteacc(p1);
        break;
        case '0':
            printf("\nVolte Sempre\n");
        menuForca(p1);
    }
};

void altnom(USERS p1){
    typedef struct {
      char nome[MAX_CHAR];
      char pass[MAX_CHAR];
      int pontos;
      int pontosvspc;
      int jogadas;
      int jogadaspc;
    } USERS;
    long int recsize;
    int userex=0;
    USERS tempuser,buffer,tester;
    FILE *f, *fin;
    f = fopen("users.dat", "rb+");
  rewind(f);
  char nometemp[MAX_CHAR] , nometempver[MAX_CHAR];
  recsize = sizeof(tempuser);
  do{
  system("cls");
  printf("Introduza o seu novo nome >");
  fflush(stdin);
  gets(nometemp);
  printf("Confirme o seu novo nome >");
  fflush(stdin);
  gets(nometempver);
  }while(strcmp(nometemp,nometempver)==1);

    fin=fopen("users.dat","rb");
    while (!feof(fin)) {
      fread(&tester, sizeof(USERS), 1, fin);
      if (strcmp(tester.nome,nometemp)==0) {
        userex = 1;
        break;
      }
    }

    if(vEspacos(nometemp)==1){
        userex = 2;
    }

    fclose(fin);

    if(userex==0){
    tempuser.jogadas=p1.jogadas;
    tempuser.jogadaspc=p1.jogadaspc;
    tempuser.pontos=p1.pontos;
    tempuser.pontosvspc=p1.pontosvspc;
    strcpy(tempuser.nome,nometemp);
    strcpy(tempuser.pass,p1.pass);

  while (fread(&buffer, recsize, 1, f) == 1) {
    if (strcmp(buffer.nome, p1.nome) == 0) {
      fseek(f, -recsize, SEEK_CUR);
      fflush(f);
      fwrite(&tempuser, recsize, 1, f);
      break;
    }
  }
  fclose(f);
  strcpy(p1.nome,tempuser.nome);
  }else if(userex == 1){
        printf(
          "\n\tUtilizador ja existe, prima qualquer tecla para voltar ao menu "
          "principal.");
      getchar();
  }else{
  printf(
          "\n\tN�o pode conter espa�os, prima qualquer tecla para voltar ao menu "
          "principal.");
      getchar();
  }
  userdatamenu(p1);

}

void altpass(USERS p1){
    typedef struct {
      char nome[MAX_CHAR];
      char pass[MAX_CHAR];
      int pontos;
      int pontosvspc;
      int jogadas;
      int jogadaspc;
    } USERS;
    long int recsize;
    int userex = 0;
    USERS tempuser,buffer;
    FILE *f;
    f = fopen("users.dat", "rb+");
  rewind(f);
  char passtemp[MAX_CHAR] , passtempver[MAX_CHAR];
  recsize = sizeof(tempuser);
  do{
  system("cls");
  printf("Introduza a sua nova pass >");
  fflush(stdin);
  gets(passtemp);
  printf("Confirme a sua nova pass >");
  fflush(stdin);
  gets(passtempver);
  }while(strcmp(passtemp,passtempver)==1);

    if(vEspacos(passtemp)==1){
        userex = 2;
    }

  if(userex==0){
    tempuser.jogadas=p1.jogadas;
    tempuser.jogadaspc=p1.jogadaspc;
    tempuser.pontos=p1.pontos;
    tempuser.pontosvspc=p1.pontosvspc;
    strcpy(tempuser.nome,p1.nome);
    strcpy(tempuser.pass,passtemp);

  while (fread(&buffer, recsize, 1, f) == 1) {
    if (strcmp(buffer.nome, p1.nome) == 0) {
      fseek(f, -recsize, SEEK_CUR);
      fflush(f);
      fwrite(&tempuser, recsize, 1, f);
      break;
    }
  }
  fclose(f);
  strcpy(p1.pass,tempuser.pass);
  }else{
  printf(
          "\n\tN�o pode conter espa�os, prima qualquer tecla para voltar ao menu "
          "principal.");
      getchar();
  }
  userdatamenu(p1);
}

void altpoints(USERS p1){
    typedef struct {
      char nome[MAX_CHAR];
      char pass[MAX_CHAR];
      int pontos;
      int pontosvspc;
      int jogadas;
      int jogadaspc;
    } USERS;
    long int recsize;
    USERS tempuser,buffer;
    FILE *f;
    f = fopen("users.dat", "rb+");
  rewind(f);
  char red[MAX_CHAR];
  recsize = sizeof(tempuser);
  do{
  system("cls");
  printf("Insira \"REDEFINIR\" para redefinir os seus pontos a 0 (0 - cancelar)>");
  fflush(stdin);
  gets(red);
  if(red=='0')
    break;
  }while(strcmp(red,"REDEFINIR")==1);
  if(strcmp(red,"0")==1){
    tempuser.jogadas=0;
    tempuser.jogadaspc=0;
    tempuser.pontos=0;
    tempuser.pontosvspc=0;
    strcpy(tempuser.nome,p1.nome);
    strcpy(tempuser.pass,p1.pass);

  while (fread(&buffer, recsize, 1, f) == 1) {
    if (strcmp(buffer.nome, p1.nome) == 0) {
      fseek(f, -recsize, SEEK_CUR);
      fflush(f);
      fwrite(&tempuser, recsize, 1, f);
      break;
    }
  }
  fclose(f);
    p1.jogadas=0;
    p1.jogadaspc=0;
    p1.pontos=0;
    p1.pontosvspc=0;
  }
  userdatamenu(p1);

}

void deleteacc(USERS p1){
    typedef struct {
      char nome[MAX_CHAR];
      char pass[MAX_CHAR];
      int pontos;
      int pontosvspc;
      int jogadas;
      int jogadaspc;
    } USERS;
    long int recsize;
    USERS tempuser,buffer,tempbuf;
    FILE *f;
    f = fopen("users.dat", "rb+");
  rewind(f);
  char red[MAX_CHAR];
  recsize = sizeof(tempuser);
  do{
  system("cls");
  printf("Insira \"APAGAR\" para redefinir os seus pontos a 0 >");
  fflush(stdin);
  gets(red);
  if(strcmp(red,"0")==0)
    break;
  }while(strcmp(red,"APAGAR")==1);
  if(strcmp(red,"0")==0){
        userdatamenu(p1);
  }else{

    tempuser.jogadas=p1.jogadas;
    tempuser.jogadaspc=p1.jogadaspc;
    tempuser.pontos=p1.pontos;
    tempuser.pontosvspc=p1.pontosvspc;
    strcpy(tempuser.nome,p1.nome);
    strcpy(tempuser.pass,p1.pass);

    while (!feof(f)) {
        if(feof(f))
            break;
        else{
            fread(&tempbuf, recsize, 1, f);
        }
    }
    fflush(stdin);
    rewind(f);
    while (fread(&buffer, recsize, 1, f) == 1) {
        if (strcmp(buffer.nome, p1.nome) == 0) {
          fseek(f, -recsize, SEEK_CUR);
          fflush(f);
          fwrite(&tempbuf, recsize, 1, f);

          strcpy(tempbuf.nome,"DELETED USER");
          strcpy(tempbuf.pass,"IASDGAUIDGAISUDASIUDHASUDHSJHDSIUDY");
          tempbuf.jogadas=-1;
          tempbuf.jogadaspc=-1;
          tempbuf.pontos=-1;
          tempbuf.pontosvspc=-1;

          fseek(f, -recsize, SEEK_END);
          fflush(f);
          fwrite(&tempbuf, recsize, 1, f);
          break;
        }
    }




  fclose(f);
    p1.jogadas=0;
    p1.jogadaspc=0;
    p1.pontos=0;
    p1.pontosvspc=0;

  menuPrincipal();
  }
}
