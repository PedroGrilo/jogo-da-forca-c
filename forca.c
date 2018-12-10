#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <ctype.h>
#define VIDAS 6

char palavra[20];
char forca[20];
char introduzidos[27];


int jogo(void)
{
    system("cls");
    header();
    printf("Player 1:\n");
    printf("Digite uma palavra: ");
    getchar();
    gets(palavra);
    fflush(stdin);
    int i, x;

    char letra;

    int chances = VIDAS, letras = 0,vitoria = 0, tried = 0, encontrou = 0;
    letras = strlen(palavra);

    for (x = 0; x < letras; x++)
        if (palavra[x] == ' ')
            forca[x] = ' '; //espaço
        else
            forca[x] = '_'; //underscore

    while (chances > 0)
    {
        system("cls");
        header();
        printf("Player 2:\n");
        printf("Chances: %d - palavras tem %d letras\n\n", chances, letras);


        for(int i=0;i<letras;i++)
        printf("%c ", forca[i]);

        if (strlen(introduzidos) > 0)
            printf("\nLetras que já sairam: %s", introduzidos);

        printf("\n\nInsira uma letra: ");
        scanf("%c", & letra);
        fflush(stdin);

        vitoria = 1;

        if (!isalpha(letra))
            continue;

        for (int i = 0;i<strlen(introduzidos); i++)
        {
            if (introduzidos[i] == toupper(letra))
            {
                tried = 1;
                break;
            }
        }

        if (tried)
            continue;

        for (i = 0; forca[i] != 0; i++)
        {
            if (toupper(forca[i]) == toupper(letra))
            {
                tried = 1;
                break;
            }
        }

        if (tried)
            continue;

        for (i = 0; i < letras; i++)
        {
            if (!isalpha(palavra[i]))
                continue;

            if (forca[i] == '_')   //para verificar se ainda existe underscores no array forca
            {
                if (toupper(palavra[i]) == toupper(letra))
                {
                    forca[i] = palavra[i];
                    encontrou = 1;
            } else {
               vitoria = 0;
            }
         }
      }

      if (!encontrou)//se nao encontrou a letra na string
         chances--;

      if (vitoria)
         return 1;

        introduzidos[strlen(introduzidos)] = toupper(letra); //colocar na string, para mostrar os caracters introduzidos

   }

   return 0;
}

void mostrarResultado(  int resultado) {
   fflush(stdin);
   if (resultado == 0) {
      printf("\nPerdeste contra o Player 1. \nA palavra era %s. \nNão ganhaste pontos", palavra);
   } else {
      printf("\nParabéns, ganhaste o jogo contra o Player 2. Ganhaaste %s pontos ", palavra);
   }
}




