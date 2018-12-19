#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define MAX_CHAR 21

typedef struct
{
    char nome[MAX_CHAR];
    char pass[MAX_CHAR];
    int pontos;
} USERS;
 USERS data,p1,p2;



FILE *fout;
FILE *fin;


void menuPrincipal()
{
    char op;
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
        case '3':
            printf("\nVolte Sempre\n");
            exit(1);
    }
}

void menuNovoUtilizador()
{

    char nometemp[MAX_CHAR];
    char passtemp[MAX_CHAR];
    char passtemp2[MAX_CHAR];
    int pontos = 200;

    int continuar;

    system("cls");
    printf("/************************************/\n");
    printf("/** Jogo da Forca - Novo utlizador **/\n");
    printf("/************************************/\n");
    printf("\nIntroduza o seu nome: ");
    fflush(stdin);
    scanf("%s",nometemp);
    printf("\nIntroduza a sua palavra-passe: ");
    fflush(stdin);
    gets(passtemp);
    printf("\nIntroduza a sua palavra-passe novamente: ");
    fflush(stdin);
    gets(passtemp2);

    animation("A registar");

    if(!strcmp(passtemp,passtemp2))
    {
        fflush(stdin);
        fin = fopen("users.dat", "a+");

        int userex = 0;

        while (!feof(fin))
        {
            fread( &p1, sizeof(USERS), 1, fin);
            if ((!strcmp(nometemp, p1.nome)))
            {
                userex = 1;
                break;
            }
        }

        fclose(fin);

        if (userex == 0)
        {
            fout = fopen("users.dat", "a+");

            strcpy(data.nome, nometemp);
            strcpy(data.pass, passtemp);
            data.pontos = pontos;

            fwrite(&data, sizeof(USERS), 1, fout);
            if (fwrite)
            {
                printf("\n\tRegistado com Sucesso, vai ser redirecionado dentro de instantes!\n");
                Sleep(1000);
                fclose(fout);
                menuForca(data);
            }
        }
        else
        {
            printf("\n\tUtilizador ja existe, prima qualquer tecla para voltar ao menu principal.");
            getchar();
            menuPrincipal();
        }

    }
    else
    {
        printf("\n\tPalavra-Passe não combinam, prima qualquer tecla para voltar ao menu principal.");
        getchar();
        menuPrincipal();
    }

}

int loginMenu()
{
    char nometemp[MAX_CHAR];
    char passtemp[MAX_CHAR];
    int logged = 0;

    int continuar;
    system("cls");
    printf("/****************************/\n");
    printf("/** Jogo da Forca - Entrar **/\n");
    printf("/****************************/\n");
    fflush(stdin);
    printf("\nIntroduza o seu nome: ");
    gets(nometemp);

    fflush(stdin);
    printf("\nIntroduza a sua palavra-passe: ");
    gets(passtemp);
    fflush(stdin);
    fin = fopen("users.dat", "a+");


    animation("A verificar se está correta");
    while (!feof(fin))
    {
        fread(&p1, sizeof(USERS), 1, fin);
        if ((!strcmp(nometemp, p1.nome)) && (!strcmp(passtemp, p1.pass)))
        {
            logged = 1;
            break;
        }
    }
    fclose(fin);
    if(logged ==1)
    {
        printf("\n\tEntrou com sucesso na sua conta!\n");
        Sleep(800);
        menuForca(p1);
    }
    else
    {
        printf("\n\tSenha incorreta, tente novamente!\n");
        Sleep(800);
        menuPrincipal();
    }
}
int loginp2(){
    char nometemp[MAX_CHAR];
    char passtemp[MAX_CHAR];
    int logged = 0;

    int continuar;
    system("cls");
    printf("/*************************************/\n");
    printf("/** Jogo da Forca - Entrar Player 2 **/\n");
    printf("/*************************************/\n");
    fflush(stdin);
    printf("\nIntroduza o seu nome: ");
    gets(nometemp);

    fflush(stdin);
    printf("\nIntroduza a sua palavra-passe: ");
    gets(passtemp);
    fflush(stdin);
    fin = fopen("users.dat", "a+");


    animation("A verificar se está correta");
    while (!feof(fin))
    {
        fread(&p2, sizeof(USERS), 1, fin);
        if ((!strcmp(nometemp, p2.nome)) && (!strcmp(passtemp, p2.pass)))
        {
            if((strcmp(p2.nome,p1.nome))){
            logged = 1;
            break;
            }else
            logged = 2;
        }
    }
    fclose(fin);
    if(logged ==1)
    {
        printf("\n\tEntrou com sucesso na sua conta!\n");
        Sleep(1000);
        return 1;
    }
    else if(logged==2){
        printf("\n\tA conta nao pode ser a mesma do player 1...");
        Sleep(1000);
        return 0;
    }
    else
    {
        printf("\n\tSenha incorreta, tente novamente!\n");
        Sleep(1000);
        return 0;
    }
}
void menuForca(USERS p1)
{
    char op;

    system("cls");
    printf("/*******************/\n");
    printf("/** Jogo da Forca **/\n");
    printf("/*******************/\n");
    printf("\nBem vindo(a) %s",p1.nome);
    printf("\n1. P1 VS P2");
    printf("\n2. P1 VS PC");
    printf("\n3. Ver Ranking");
    printf("\n4. Sair ");
    printf("\n\nEscolha uma opção > ");
    fflush(stdin);
    op=getchar();
    switch(op)
    {
        case '1':
            if(loginp2()==1)
            words(p1,p2);
            else
            menuForca(p1);
            break;
        case '2':
            printf("Em desenvolvimento");
            break;
        case '3':
            ranking(p1);
            break;
        case '4':
            menuPrincipal();
            break;
        default:
            printf("\nOpção Errada!Qualquer tecla para tentar novamente\n");
            fflush(stdin);
            getchar();
            menuForca(p1);

    }
}
void ranking(USERS p1)
{
    char op='0';

    system("cls");
    printf("/*******************/\n");
    printf("/***** Ranking *****/\n");
    printf("/*******************/\n");
    printf("\n1. Ver ranking P1 VS PC");
    printf("\n2. Ver ranking P1 VS P2");
    printf("\n0. Voltar");
    printf("\n\nEscolha uma opção >");
    fflush(stdin);
    scanf("%c",&op);


    switch (op)
    {
        case '1':
            printf("\nVersão em desenvolvimento\n\nPressione qualquer tecla para voltar ao menu...\n");
            fflush(stdin);
            getchar();
            menuForca(p1);
            break;
        case '2':
        //rankpvp();break;

        case '0':
            menuForca(p1);
        default:
            ranking(p1);
    }

}



