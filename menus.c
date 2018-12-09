#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define MAX_CHAR 21

FILE *acc;

struct users
{
    char nome[MAX_CHAR];
    char pass[MAX_CHAR];
    int pontos;
} user;

void animation(char string[])
{
    system("cls");
    printf("\n\t%s",string);
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".\n");
    Sleep(500);
}

void menuPrincipal()
{
    char op;
    do
    {
        system("cls");
        printf("/*******************/\n");
        printf("/** Jogo da Forca **/\n");
        printf("/*******************/\n");
        printf("\n1. Entrar");
        printf("\n2. Registar");
        printf("\n3. Sair");
        printf("\n\nEscolha uma opcão: ");
        scanf(" %c",&op);

        switch(op)
        {
            case '1':
                loginMenu();
                break;
            case '2':
                menuNovoUtilizador();
                break;
        }
    }
    while(op<'1' || op>'3');
}

void menuNovoUtilizador()
{
    //nao esquecer verificar os nomes iguais
    system("cls");

    char nometemp[100];
    char passtemp[100];
    char passtemp2[100];

    acc=fopen("users.dat","a+");

    printf("/************************************/\n");
    printf("/** Jogo da Forca - Novo utlizador **/\n");
    printf("/************************************/\n");
    printf("\nIntroduza o seu nome: ");
    scanf("%s",user.nome);
    printf("\nIntroduza a sua palavra-passe: ");
    scanf("%s",passtemp);
    printf("\nIntroduza novamente a sua palavra-passe: ");
    scanf("%s",passtemp2);

    animation("A registar");

    char nome[50],pass[50];
    int userexists=0,pontos;

    if(strcmp(passtemp,passtemp2)==0){
        user.pontos = 0;
        strcpy(user.pass,passtemp);

        while(fscanf(acc,"%s\t%s\t%i",nome,pass,&pontos)!=EOF)
            if(!strcmp(nome,user.nome))
                userexists = 1;

        if(userexists == 0){
            fprintf(acc,"%s\t%s\t%d\n",user.nome,user.pass,user.pontos);
            if(fprintf != 0){
                printf("\n\tRegistado com sucesso!\n\n\tPressione qualquer tecla para voltar ao menu principal...");
            }else
                printf("\n\tErro ao registar, tente novamente!\n\n\tPressione qualquer tecla para voltar ao menu principal...");
        }else
            printf("\n\tErro ao registar, utilizador ja existe!\n\n\tPressione qualquer tecla para voltar ao menu principal...");
    }else{
        printf("\n\tERRO: Campo de repetir palavra-passe não é igual à sua Palavra-passe.\n\n\tPressione qualquer tecla para voltar ao menu principal...");
    }

    getch();
    fclose (acc);
    menuPrincipal();
}

void loginMenu()
{

    char loggedname[50],nome[50],pass[50];
    int pontos =0,disponivel=0;
    acc=fopen("users.dat","r");

    system("cls");
    printf("/****************************/\n");
    printf("/** Jogo da Forca - Entrar **/\n");
    printf("/****************************/\n");
    printf("\nIntroduza o seu nome: ");
    scanf("%s",user.nome);
    printf("\nIntroduza a sua palavra-passe: ");
    scanf("%s",user.pass);

    while(fscanf(acc,"%s\t%s\t%i",nome,pass,&pontos)!=EOF)
        if(!strcmp(nome,user.nome) && !strcmp(pass,user.pass))
            disponivel=1;

    animation("A verificar se está correta");

    if(disponivel==0)
    {
        printf("\n\tSenha incorreta, tente novamente!\n");
        Sleep(800);
        strcpy(loggedname,"");
        menuPrincipal();
        fclose(acc);
    }
    else
    {
        printf("\n\tEntrou com sucesso na sua conta!\n");
        Sleep(800);
        strcpy(loggedname,user.nome);
        menuForca(loggedname,pontos);
        fclose(acc);
    }
}

void menuForca(char loggedname[],int pontos)
{
    char op;

    system("cls");
    printf("/*******************/\n");
    printf("/** Jogo da Forca **/\n");
    printf("/*******************/\n");
    printf("\nBem vindo(a) %s,",loggedname);
    printf("\nPontos: %d\n",pontos);
    printf("\n1. P1 VS P2");
    printf("\n2. P1 VS PC");
    printf("\n3. Ver Ranking");
    printf("\n4. Sair ");
    printf("\nEscolha uma opção:");
    scanf(" %c",&op);

    switch(op)
    {
        case '1':
            playervsplayer();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            menuPrincipal();
            break;
            if(op < '1' || op > '4')
            {
                system("cls");
                printf("\nOpção Errada\n\n");
            }
    }
}


