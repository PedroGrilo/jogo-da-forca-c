#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void animation(char string[])
{
    system("cls");
    printf("\n\t%s",string);
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".");
    Sleep(200);
    printf(".\n");
    Sleep(500);
}

void forcadefault()
{
    printf("    ________\n");
    printf("   |/       |\n");
    printf("   |\n");
    printf("   |\n");
    printf("   |\n");
    printf("   |\n");
    printf("___|___\n");
}
void vida1()
{
    printf("    ________\n");
    printf("   |/       |\n");
    printf("   |        0\n");
    printf("   |\n");
    printf("   |\n");
    printf("   |\n");
    printf("___|___\n");
}
void vida2()
{

    printf("    ________\n");
    printf("   |/       |\n");
    printf("   |        0\n");
    printf("   |        |\n");
    printf("   |\n");
    printf("   |\n");
    printf("___|___\n");
   }

void vida3()
{
    printf("    ________\n");
    printf("   |/       |\n");
    printf("   |        0\n");
    printf("   |       /|\n");
    printf("   |\n");
    printf("   |\n");
    printf("___|___\n");
   }
void vida4()
{
    printf("    ________\n");
    printf("   |/       |\n");
    printf("   |        0\n");
    printf("   |       /|\\\n");
    printf("   |\n");
    printf("   |\n");
    printf("___|___\n");
}

void vida5()
{

    printf("    ________\n");
    printf("   |/       |\n");
    printf("   |        0\n");
    printf("   |       /|\\\n");
    printf("   |       /\n");
    printf("   |\n");
    printf("___|___\n");}
void vida6()
{
    printf("    ________\n");
    printf("   |/       |\n");
    printf("   |        0\n");
    printf("   |       /|\\\n");
    printf("   |       / \\\n");
    printf("   |\n");
    printf("___|___\n");
    }
void animacaoperdeu()
{
    int i = 0;
    while(i<=3)
    {
        system("cls");
        printf(" * * * RESULTADO * * *\n");
        printf("    ________\n");
        printf("   |/       |\n");
        printf("   |        0\n");
        printf("   |       /|\\\n");
        printf("   |       / \\\n");
        printf("   |\n");
        printf("___|___\n");
            Sleep(200);
        system("cls");


        printf("       RESULTADO      \n");
        printf("    ________\n");
        printf("   |/       |\n");
        printf("   |       \\0/\n");
        printf("   |        |\n");
        printf("   |       / \\\n");
        printf("   |\n");
        printf("___|___\n");i++;
     Sleep(200);
    }
}
void win()
{
    int i =0;
    while (i<=5)
    {
        system("cls");
        printf("\t       RESULTADO      \n");
        printf("\n\t * * * PARABENS! * * *\n");
        Sleep(200);
        system("cls");
        printf("\t * * * RESULTADO * * *\n");
        printf("\n\t       PARABENS!      \n");
        Sleep(200);
        i++;
    }
    system("cls");
        printf("\t       RESULTADO      \n");
        printf("\n\t * * * PARABENS! * * *\n");}

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

    if(vida<6)
    {
        printf("RESTAM %d VIDA(S)",6-vida);
    }
}


