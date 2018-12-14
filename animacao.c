#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void forcadefault()
{
    printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
    printf("   %c\n",186);
    printf("   %c\n",186);
    printf("   %c\n",186);
    printf(" %c%c%c%c%c\n",205,205,202,205,205);
}
void vida1()
{
    printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
    printf("   %c    O\n",186);
    printf("   %c    \n",186);
    printf("   %c\n",186);
    printf(" %c%c%c%c%c\n",205,205,202,205,205);

}
void vida2()
{
    printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
    printf("   %c    O\n",186);
    printf("   %c    |\n",186);
    printf("   %c\n",186);
    printf(" %c%c%c%c%c\n",205,205,202,205,205);
}
void vida3()
{
    printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
    printf("   %c   \\O\n",186);
    printf("   %c    |\n",186);
    printf("   %c\n",186);
    printf(" %c%c%c%c%c\n",205,205,202,205,205);
}
void vida4()
{
    printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
    printf("   %c   \\O/\n",186);
    printf("   %c    |\n",186);
    printf("   %c\n",186);
    printf(" %c%c%c%c%c\n",205,205,202,205,205);
}

void vida5()
{
    printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
    printf("   %c   \\O/\n",186);
    printf("   %c    |\n",186);
    printf("   %c   /\n",186);
    printf(" %c%c%c%c%c\n",205,205,202,205,205);
}
void vida6()
{
    printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
    printf("   %c   \\O/\n",186);
    printf("   %c    |\n",186);
    printf("   %c   / \\\n",186);
    printf(" %c%c%c%c%c\n",205,205,202,205,205);
}
void animacaoperdeu()
{
    int i = 0;
    while(i<=3)
    {
        system("cls");
        printf("%c%c%c%c%c-RESULTADO-%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205);
        printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
        printf("   %c   \\O/\n",186);
        printf("   %c    |\n",186);
        printf("   %c   / \\\n",186);
        printf(" %c%c%c%c%c\n",205,205,202,205,205);
        Sleep(200);
        system("cls");

        printf("%c%c%c%c%c-RESULTADO-%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205);
        printf("   %c%c%c%c%c%c\n",201,205,205,205,205,187);
        printf("   %c    \O\n",186);
        printf("   %c   /|\\\n",186);
        printf("   %c   / \\\n",186);
        printf(" %c%c%c%c%c\n",205,205,202,205,205);
        Sleep(200);
        i++;
    }
}
void win()
{
    int i =0;
    while (i<=5)
    {
        system("cls");
        printf("\t%c%c%c%c%c-RESULTADO-%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205);
        printf("\n\t* * * PARABENS! * * *\n");
        Sleep(200);
        system("cls");
        printf("\t%c%c%c%c%c-RESULTADO-%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205);
        printf("\n\t      PARABENS!      \n");
        Sleep(200);
        i++;
    }
    system("cls");
    printf("\t%c%c%c%c%c-RESULTADO-%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205);
    printf("\n\t* * * PARABENS! * * *\n");
}

void vida(int vida)
{

    switch(vida)
    {
        case 0:
            forcadefault();
            break;
        case 1:
            vida1();
            break;
        case 2:
            vida2();
            break;
        case 3:
            vida3();
            break;
        case 4:
            vida4();
            break;
        case 5:
            vida5();
            break;
        case 6:
            vida6();
            break;
        case 7:
            animacaoperdeu(); /// 7 = perdeu
            break;
        default:
            win(); ///senao - ganhou
    }

    if(vida<5)
    {
        printf("RESTAM %d VIDA(S)",6-vida);
    }
}


