#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void words ()
{
    char repetir, forca[100], frase[100];
    int i=0,k=0;
    do{
        system("cls");
        printf("Introduza a sua palavra/frase: \n");
        getchar();
        gets(forca);
        i=strlen(forca);
        system("cls");
        do{
            if(forca[k]==' '){
                frase[k]=' ';
            }else{
                frase[k]='-';
            }
            k++;
        }while(k<i);
        frase[k]='\0';
        system("cls");
        puts(forca);
        puts("Deseja alterar a sua frase ? Alterar(R)");
        scanf(" %c",&repetir);
    }while(tolower(repetir)=='r');
    guesser(forca,frase);
    puts("");
}
void guesser(char forca[100],char frase[100])
{
    char tentativa[36];
    int i=0,k=0,samechar=0,guesssize=strlen(forca),falha=0,falhas=0;
    do{
        puts(frase);
        puts("Intrduza o seu palpite");
        fflush(stdin);
        tentativa[i]=getchar();
        falha=1;
        for(k=0;k<i;k++){
            if(tentativa[i]==tentativa[k]){
                printf("%c Esse caracter ja foi introduzido\n",tentativa[i]);
                i--;
                samechar=1;
                continue;
            }else{
                samechar=0;
            }
        }
        if(samechar==0){
            for(k=0;k<guesssize;k++){
                if(tolower(tentativa[i])==tolower(forca[k])){
                    frase[k]=tentativa[i];
                    falha=0;
                }
            }

        }
        i++;
    }while(i<36);
}


