#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#define VIDAS 6

void playervsplayer()
{
    system("cls");
    int chances = VIDAS,m=0,x=0,tamanho=0;
    char frase[100],tentativa[100],letra,samechar,introduzidas[26];
    bool digit =false, erro = true;

    do
    {
        printf("Player 1:\n");
        printf("Introduza uma palavra: ");
        getchar();
        gets(frase);
        tamanho = strlen(frase);

        if(strlen(frase)<=2){
            system("cls");
            printf("Erro: O minimo de letras são 3. Tente novamente.\n");
        }

        for(int h=0;h<tamanho;h++){
            if(isdigit(frase[h])){
                digit = true;
                 system("cls");
                 printf("Erro: A palavra só pode conter letras. Tente Novamente.\n");
            }else
                digit = false;
        }

    }while((strlen(frase)<=2)||digit ==true);

    for(x = 0; x<tamanho; x++)
    {
        if(frase[x]==' ')
        {
            tentativa[x]=' '; //espaço
        }
        else
        {
            tentativa[x]='_'; //underscore
        }
    }

    tentativa[x] = '\0';


    while((chances>=1) && strcmp(frase,tentativa)){
        system("cls");
        printf("Player 2:\n");
        if(m>0){
              printf("Letras introduzidas:");
              for(int n=0;n<m;n++){
                printf(" %c",introduzidas[n]);
                }
        }
        printf("Vidas: %d\n",chances);

        for(int i=0; i<strlen(tentativa); i++)
        {
            printf("%c ",tentativa[i]);
        }

        printf("\nInsira uma letra: ");
        scanf("%c",&letra);

        introduzidas[m] = letra;


        for(int i = 0; i<tamanho; i++)
        {
            if(letra==frase[i]){
                tentativa[i]=letra;
                erro=false;
            }
        }

        if(erro==true)
            chances=chances-1;

        m++;
    }//acaba o while


    if(chances == 0)
    {
        system("cls");
        printf("\n\tFrase: %s\n",frase);
        printf("\tPerdeu!! Perdeu o jogo da forca contra o Player 1.\n\tA voltar para o menu principal...");
        Sleep(500);
    }

    if(!strcmp(frase,tentativa))
    {
        system("cls");
        printf("\n\tFrase: %s\n",frase);
        printf("\tParabéns!! Ganhou o jogo da forca contra o Player 1.\n\tA voltar para o menu principal...");
        Sleep(500);

    }

}







