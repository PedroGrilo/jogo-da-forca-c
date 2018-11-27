#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "menus.h"



int main()
{
    system("color F0");
    setlocale(LC_ALL,"");

   char op;
    do{

       menuprincipal();
       scanf(" %c",&op);

       if(op < '1' || op > '3'){
       system("cls");
       printf("\nOpção Errada\n\n");
       }

   }while(op<'1' || op>'3');


    return 0;
}
