#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

FILE*acc;
bool logged = false;
char loggedname[50];

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

                if(op < '1' || op > '3')
                {
                    system("cls");
                    printf("\nOpção Errada\n\n");
                }

        }
    }
    while(op<'1' || op>'3');


}

void menuNovoUtilizador()
{
    char txt[5]=".dat";
    system("cls");
    char passtemp[100];
    char passtemp2[100];
    char nometemp[50];
    char pass[50];
    char nome[50];
    printf("/************************************/\n");
    printf("/** Jogo da Forca - Novo utlizador **/\n");
    printf("/************************************/\n");
    printf("\nIntroduza o seu nome: ");
    scanf("%s",nometemp);
    printf("\nIntroduza a sua palavra-passe: ");
    scanf("%s",passtemp);
    printf("\nIntroduza novamente a sua palavra-passe: ");
    scanf("%s",passtemp2);
    if(strcmp(passtemp,passtemp2)==0)
    {
        strcpy(pass,passtemp);
        strcpy(nome,nometemp);
        strcat(nome,txt);
        acc=fopen(nome,"wb");
        fprintf(acc,"%s",passtemp);
        printf("\nRegistado com sucesso!!\nPressione qualquer tecla para voltar ao menu principal...");
        fclose(acc);
    }
    else
    {
        printf("\nERRO: Campo de repetir palavra-passe não é igual à sua Palavra-passe.\nPressione qualquer tecla para voltar ao menu principal...");
    }
    getch();
    menuPrincipal();

}

void loginMenu()
{

    char txt[5]=".dat",pass[50],passuser[50],nome[50],nomefile[50],password[50],passtest[100];

    system("cls");
    printf("/****************************/\n");
    printf("/** Jogo da Forca - Entrar **/\n");
    printf("/****************************/\n");
    printf("\nIntroduza o seu nome: ");
    getchar();
    gets(nome);
    strcpy(nomefile,nome);
    strcat(nomefile,txt);
    printf("\nIntroduza a sua palavra-passe: ");
    scanf("%s",&pass);
    strcpy(passtest,nome);
    strcat(passtest,txt);

    acc=fopen(nomefile,"rb");

    fscanf(acc,"%s",&password);

    if(strcmp(password,pass)!=0)
    {
        system("cls");
        printf("\n\t A verificar se a senha está correta ");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".\n");
        Sleep(500);
        printf("\n\tSenha incorreta, tente novamente!\n");
        Sleep(800);
        strcpy(loggedname,"");
        logged = false;
        fclose(acc);
        menuPrincipal();
    }
    else
    {
        system("cls");
        printf("\n\t A verificar se a senha está correta ");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".\n");
        Sleep(500);
        printf("\n\t Entrou com sucesso na sua conta!\n");
        Sleep(800);
        strcpy(loggedname,nome);
        logged = true;
        fclose(acc);
        menuForca();
    }

}

void menuForca()
{
    if(logged == true)
    {
        char op;
        system("cls");
        printf("/*******************/\n");
        printf("/** Jogo da Forca **/\n");
        printf("/*******************/\n");
        printf("\nBem vindo(a) %s,\n",loggedname);
        printf("\n1. P1 VS P2");
        printf("\n2. P1 VS PC");
        printf("\n3. Ver Ranking");
        printf("\n5. Sair ");
        printf("\nEscolha uma opção:");
        scanf(" %c",&op);

        switch(op)
        {
            case '1':
                words();
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
    else
    {
        strcpy(loggedname,"");
        menuPrincipal();
    }
}
