#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#ifdef __unix__
#include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#endif
#include "menus.h"



int main()
{
    system("color F0");
    setlocale(LC_ALL,"");
    menuPrincipal();    return 0;
}
