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


int jogo(void) {

  printf("\tPlayer 1:\n");
   printf("\tDigite uma palavra: ");
   getchar();
   gets(palavra);
   fflush(stdin);
   int i, x;
   for (x = 0; x < strlen(palavra); x++)
      if (palavra[x] == ' ')
         forca[x] = ' '; //espaço
      else
         forca[x] = '_'; //underscore

   char letra;
   int chances = VIDAS, letras = 0,vitoria = 0, tried = 0, encontrou = 0;

   letras = strlen(palavra);

   while (chances > 0) {
      system("cls");
      printf("\tPlayer 2:\n");
      printf("\tChances: %d - palavras tem %d letras\n\n", chances, letras);

      printf("\t%s", forca);

      if (strlen(introduzidos) > 0)
         printf("\n\tLetras introduzidas: %s", introduzidos);

      printf("\n\n\tDigite uma letra: ");
      scanf("%c", & letra);
      fflush(stdin);

      if (!isalpha(letra)) continue;
      vitoria = 1;
      for (i = 0; introduzidos[i] != 0; i++) {
         if (introduzidos[i] == toupper(letra)) {
            tried = 1;
            break;
         }
      }

      if (tried) continue;

      for (i = 0; forca[i] != 0; i++) {
         if (toupper(forca[i]) == toupper(letra)) {
            tried = 1;
            break;
         }
      }

      if (tried) continue;

      introduzidos[strlen(introduzidos)] = toupper(letra); //colocar na string, para mostrar os caracters introduzidos

      for (i = 0; i < strlen(palavra); i++) {
         if (!isalpha(palavra[i]))
            continue;

         if (forca[i] == '_') { //para verificar se ainda existe underscores no array forca
            if (toupper(palavra[i]) == toupper(letra)) {
               forca[i] = palavra[i];
               encontrou = 1;
            } else
               vitoria = 0;
         }
      }

      if (!encontrou)//se nao encontrou a letra na string
         chances--;

      if (vitoria)
         return 1;
   }
   return 0;
}

void mostrarResultado(int resultado) {
   fflush(stdin);
   if (resultado == 0) {
      printf("\nVoce perdeu. \nA palavra era %s", palavra);
   } else {
      printf("\nParabens, voce acertou a palavra %s ", palavra);
   }
}




