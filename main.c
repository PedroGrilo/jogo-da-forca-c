#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "menus.h"
#define MAX_CHAR 21

int main()
{
    setlocale(LC_ALL,"");
    system("color F0");
    menuPrincipal();
    return 0;
}
