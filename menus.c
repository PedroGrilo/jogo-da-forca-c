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

        switch(op){
        case '1':
            menuLogin();break;
        case '2':
            menuNovoUtilizador();break;
        case '3':
            continue;

        if(op < '1' || op > '3')
        {
            system("cls");
            printf("\nOpção Errada\n\n");
        }

    }
   } while(op<'1' || op>'3');


}
    void menuNovoUtilizador()
{
    system("cls");
    char passtemp, passtemp2,nometemp,pass,nome;
    printf("/************************************/\n");
    printf("/** Jogo da Forca - Novo utlizador **/\n");
    printf("/************************************/\n");
    printf("\nIntroduza o seu nome: ");
    gets(nometemp);
    printf("\nIntroduza a sua palavra-passe: ");
    gets(passtemp);
    printf("\nIntroduza novamente a sua palavra-passe: ");
    gets(passtemp2);

    if(passtemp2==passtemp)
    {
        pass = passtemp;
        nome = nometemp;
    }
    else{
        printf("\n\nCampo de repetir palavra-passe não é igual à sua Palavra-pass");
    }
}

menuLogin(char nome, char pass)
{
    system("cls");
    printf("/****************************/\n");
    printf("/** Jogo da Forca - Entrar **/\n");
    printf("/****************************/\n");
    printf("\nIntroduza o seu nome: ");
    gets(nome);
    printf("\nIntroduza a sua palavra-passe: ");
    gets(pass);
}
