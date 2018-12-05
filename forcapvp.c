#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void words (){
    char repetir, forca[100], frase[100];
    int i;
    system("cls");
    printf("Introduza a sua palavra/frase: \n");
    getchar();
    gets(forca);
    system("cls");
    for (i=0;forca[i]!='\0';i++){
        if(forca[i]==' '){
            frase[i]=' ';
        }else{
            frase[i]='-';
        }
    }
    puts(frase);
    guesser(forca,frase);
    puts("");
}
void guesser(char forca[100],char frase[100]){
    char tentativa[26];
    int falhas=0,falha=0,i,k;
    for(i=0;i<100;i++){
        printf("Introduza o seu palpite: \n");
        fflush(stdin);
        scanf("%c",&tentativa[i]);
        falha=1;
        for(k=0;forca[k]!='\0';k++){
            if(tentativa[i]==forca[k]){
                if(tentativa[i]==' '){
                    continue;
                }
                frase[k]=tentativa[i];
                falha=0;
            }
        }
        system("cls");
        printf("%s \n",frase);
        if(falha==1){
            falhas++;
            if(falhas==6){
                break;
            }
        }else
            if(strcmp(frase,forca)==1){
                break;
                system("cls");
                printf("PARABENS GANHOU!");
            }
        }
        printf("\n\n\nforca: %s\n\nfrase: %s\n\n\n",forca,frase);

    }


