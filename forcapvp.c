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
        puts("Deseja alterar a sua frase, se sim prima [R].");
        scanf(" %c",&repetir);
    }while(tolower(repetir)=='r');
    system("cls");
    guesser(forca,frase);
    puts("");
}
void guesser(char forca[100],char frase[100])
{
    char tentativa[36],falhas[6];
    int i=0,k=0,samechar=0,guesssize=strlen(forca),falha=1,falhascount=0,counter=0;
    do{
        if(samechar!=1){
            system("cls");
        }
        switch(falhascount){
            default:  break;


        }
        puts(frase);
        puts("Intrduza o seu palpite");
        fflush(stdin);
        tentativa[i]=getchar();
        falha=1;
        for(k=0;k<i;k++){
            if(tentativa[i]==tentativa[k]){
                system("cls");
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
                    frase[k]=tolower(tentativa[i]);
                    falha=0;
                }
            }
            if(falha==1 && falhascount<6 && samechar==0){
                falhas[falhascount]=tentativa[i];
                falhascount++;
            }else if(falhascount>=6){
                system("cls");
                printf("Perdeu, Lamento");
                break;
            }
            if (strcmp(forca, frase) == 0){
                system("cls");
                printf("gg");
                break;
            }
        }
        i++;
    }while(i<36);
}


