void menuPrincipal()
{

    char op;
    do
    {
        system("cls");
        printf("/*******************/\n");
        printf("/** Jogo da Forca **/\n");
        printf("/*******************/\n");
        printf("\n1. Entrar");
        printf("\n2. Registar");
        printf("\n3. Sair");
        printf("\n\nEscolha uma opcão: ");
        scanf(" %c",&op);

        switch(op)
        {
            case '1':
                loginMenu();
                break;
            case '2':
                menuNovoUtilizador();
                break;

                if(op < '1' || op > '3')
                {
                    system("cls");
                    printf("\nOpção Errada\n\n");
                }

        }
    }
    while(op<'1' || op>'3');


}
void menuNovoUtilizador()
{
    system("cls");
    char passtemp[100];
    char passtemp2[100];
    char nometemp[50];
    char pass[50];
    char nome[50];
    printf("/************************************/\n");
    printf("/** Jogo da Forca - Novo utlizador **/\n");
    printf("/************************************/\n");
    printf("\nIntroduza o seu nome: ");
    scanf("%s",nometemp);
    printf("\nIntroduza a sua palavra-passe: ");
    scanf("%s",passtemp);
    printf("\nIntroduza novamente a sua palavra-passe: ");
    scanf("%s",passtemp2);
    if(strcmp(passtemp,passtemp2)==0)
    {
        strcpy(pass,passtemp);
        strcpy(nome,nometemp);
        printf("\nRegistado com sucesso!!\nPressione qualquer tecla para voltar ao menu principal...");
        getch();
        menuPrincipal();
    }
    else
        printf("\nERRO: Campo de repetir palavra-passe não é igual à sua Palavra-passe.\nPressione qualquer tecla para voltar ao menu principal...");
    getch();
    menuPrincipal();
}

void loginMenu()
{
    char pass[50];
    char nome[50];

    system("cls");
    printf("/****************************/\n");
    printf("/** Jogo da Forca - Entrar **/\n");
    printf("/****************************/\n");
    printf("\nIntroduza o seu nome: ");
    scanf("%s",nome);
    printf("\nIntroduza a sua palavra pass: ");
    scanf("%s",pass);
    if(strcmp("admin",nome)==0 && strcmp("admin",pass)==0)
    {
        menuForca();
    }else
            printf("\nERRO: Nome ou Palavra-Passe estão incorretas.\nPressione qualquer tecla para voltar ao menu principal...");
    getch();
    menuPrincipal();

}

void menuForca(){
    char op;
    system("cls");
    printf("/*******************/\n");
    printf("/** Jogo da Forca **/\n");
    printf("/*******************/\n");
    printf("\n1. P1 VS PC");
    printf("\n2. P1 VS P2");
    printf("\n3. Ver Ranking");
    printf("\n4. Sair ");
    printf("\nEscolha uma opção:")
    scanf(" %c",&op);

        switch(op)
        {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                menuPrincipal();
                break;

                if(op < '1' || op > '4')
                {
                    system("cls");
                    printf("\nOpção Errada\n\n");
                }

        }

}
