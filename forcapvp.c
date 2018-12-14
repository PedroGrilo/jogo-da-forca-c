#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void header(int x,char msg[],int vidas)
{
    system("cls");
    printf("/*******************************/\n");
    printf("/** Jogo da Forca - Player %d  **/\n",x);
    printf("/*******************************/\n");
    if(x==2)
        vida(vidas);
    puts(msg);
}
void words ()
{
    char repetir, forca[100], frase[100], msg[100] = {};
    int i=0,k=0;
    do
    {
        system("cls");
        header(1,msg,1);

        if(repetir=='r'&&forca[0]==0)
        {
            printf("Não são aceites números, tente novamente!\n\n");
        }
        repetir='\0';
        printf("Introduza a sua palavra/frase > ");
        fflush(stdin);
        gets(forca);
        i=strlen(forca);
        system("cls");

        do
        {
                if(forca[k]==' ')
                {
                    frase[k]=' ';
                }
            else if(forca[k]<='9'&&forca[k]>='0')

                forca[0] = '\0';
                repetir='r';
                break;

                else
                {
                    frase[k]='_';
                }

            k++;
        }
        while(k<i);
        frase[k]='\0';
        printf("Frase: %s\n\n",forca);
        if(repetir!='r')
        {
            puts("Deseja alterar a sua frase?[S/N]");
            scanf(" %c",&repetir);
        }
    }
    while(tolower(repetir)=='s');
    system("cls");
    guesser(forca,frase);
    puts("");
}
void guesser(char forca[100],char frase[100])
{

    char tentativa[26],falhas[6], msg[100] = {},voltar;
    int i=0,k=0,samechar=0,guesssize=strlen(forca),falha=1,falhascount=0,counter=0;

    do
    {
        if(samechar!=1)
            system("cls");

        header(2,msg,falhascount);
        fflush(stdin);

        for (int i=0; i<guesssize; i++)
            printf("%c ",frase[i]);

        puts("\n\nIntroduza uma letra > ");
        fflush(stdin);
        tentativa[i]=getchar();
        strcpy(msg,"");

        if(isdigit(tentativa[i]))
        {
            system("cls");
            strcpy(msg,"\nNao sao aceites numeros, tente novamente!\n");
            i--;
            continue;
        }
        else if(tentativa[i]==32)
        {
            system("cls");
            strcpy(msg,"\nNao sao aceites espacos, tente novamente!\n");
            i--;
            continue;
        }
        else if(tentativa[i]=='\n')
        {
            system("cls");
            strcpy(msg,"\nNao introduziu nenhuma letra, tente novamente!\n");
            i--;
            continue;
        }

        falha=1;
        for(k=0; k<i; k++)
        {
            if(tentativa[i]==tentativa[k])
            {
                system("cls");
                strcpy(msg,"\nERRO: Esse caracter já foi introduzido\n");
                i--;
                samechar=1;
                continue;

            }
            else
            {
                samechar=0;
            }

        }
        if(samechar==0)
        {
            for(k=0; k<guesssize; k++)
            {
                if(tolower(tentativa[i])==tolower(forca[k]))
                {
                    frase[k]=tolower(tentativa[i]);
                    falha=0;
                }
            }
            if(falha==1 && falhascount<5 && samechar==0)
            {
                falhas[falhascount]=tentativa[i];
                falhascount++;
            }
            else if(falhascount>=5)
            {
                system("cls");
                header(2,msg,7);
                printf("Perdeu o jogo contra o Player 1 :(\n Não ganhou pontos...");
                printf("\n\nDeseja voltar ao menu?[S/N]");
                getchar();
                scanf(" %c",&voltar);
                if(tolower(voltar)=='s')
                    menuForca();
                else
                    printf("\nVolte sempre");
                exit(1);
            }
            if (strcmp(forca, frase) == 0)
            {
                system("cls");
                header(2,msg,8);
                printf("Ganhou o jogo contra o Player 1!!\n Ganhou x pontos.");//mudar
                printf("\n\nDeseja voltar ao menu?[S/N]");
                getchar();
                scanf(" %c",&voltar);
                if(tolower(voltar)=='s')
                    menuForca();
                else
                    printf("Volte sempre\n");
                exit(1);
            }
        }
        i++;
    }
    while(i<26);
}


