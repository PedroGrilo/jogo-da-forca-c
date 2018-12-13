#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header(int x,char mens[])
{
    printf("/*******************************/\n");
    printf("/** Jogo da Forca - Player %d  **/\n",x);
    printf("/*******************************/\n");
    puts(mens);
}
void words ()
{
    char repetir, forca[100], frase[100], mens[100] = {};
    int i=0,k=0;
    do
    {
        system("cls");
        header(1,mens);

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
            {
                forca[0] = '\0';
                repetir='r';
                break;
            }
            else
            {
                frase[k]='-';
            }
            k++;
        }
        while(k<i);
        frase[k]='\0';
        system("cls");
        header(1,mens);
        printf("Frase: %s\n\n",forca);
        if(repetir!='r')
        {
            puts("Deseja alterar a sua frase, se sim prima [S].");
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
    char tentativa[26],falhas[6], mens[100] = {};;
    int i=0,k=0,samechar=0,guesssize=strlen(forca),falha=1,falhascount=0,counter=0;
    do
    {
        if(samechar!=1)
            system("cls");

        switch(falhascount)
        {
            default:
                break;
        }

        header(2,mens);
        puts(frase);
        puts("Introduza uma letra > ");
        fflush(stdin);
        tentativa[i]=getchar();
        strcpy(mens,"");


        if(isdigit(tentativa[i]))
        {
            system("cls");
            strcpy(mens,"\nNão são aceites números, tente novamente!\n");
            i--;
            continue;
        }

        falha=1;
        for(k=0; k<i; k++)
        {
            if(tentativa[i]==tentativa[k])
            {

                system("cls");
                strcpy(mens,"\nERRO: Esse caracter já foi introduzido\n");
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
                header(2,mens);
                printf("Perdeu o jogo contra o Player 1 :(\n Não ganhou pontos...");
                break;
            }
            if (strcmp(forca, frase) == 0)
            {
                system("cls");
                header(2,mens);
                printf("Parabéns, ganhou o jogo contra o Player 1!!\n Ganhou x pontos.");//mudar
                break;
            }
        }
        i++;
    }
    while(i<26);
}


