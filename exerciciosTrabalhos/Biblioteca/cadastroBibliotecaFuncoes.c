#include "cadastroBiblioteca.h"

void Iniciar (TModuloLivro *mod) {
    
    mod->INDICE = 0;
}

void LeituraDeDados (TLivro *L) {
    
    system("clear");

    printf("\n#########################################");
    printf("\n#        Lendo dados do Livro !!!       #");
    printf("\n#########################################\n\n");
    
    printf("\nDigite o ISBN(Código do livro): ");
    __fpurge(stdin);
    scanf("%d", &L->ISBN);
    
    printf("\nDigite o Título do livro: ");
    __fpurge(stdin);
    fgets(L->titulo, 100, stdin);
    
    printf("\ntDigite a edição em que o livro está: ");
    __fpurge(stdin);
    scanf("%d", &L->edicao);
    
    printf("\nDigite o nome do autor do livro: ");
    __fpurge(stdin);
    fgets(L->autor, 100, stdin);
    
    printf("\nDigite o nome da editora do livro: ");
    __fpurge(stdin);
    fgets(L->editora, 100, stdin);
    
    printf("\nDigite o volume do livro: ");
    __fpurge(stdin);
    scanf("%d", &L->volume);
    
    printf("\nDigite o numero de exemplares do livro: ");
    __fpurge(stdin);
    scanf("%i", &L->numExemplar);
    
    printf("\nDigite o dia da publicação: ");
    __fpurge(stdin);
    scanf("%d", &L->DATA_DE_PUB.dia);
    
    printf("\nDigite o mês da publicação: ");
    __fpurge(stdin);
    scanf("%d", &L->DATA_DE_PUB.mes);
    
    printf("\nDigite o ano da publicação: ");
    __fpurge(stdin);
    scanf("%d", &L->DATA_DE_PUB.ano);
}

void Cadastrar(TLivro L, TModuloLivro *mod) {

    if(mod->INDICE < 100){    
        system("clear");
        mod->livros[mod->INDICE] = L;
        mod->INDICE++;
        
        system("clear");
        printf("\n\nCadastro do livro efetuado com Sucesso !!!\n\n");
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();                    
        system("clear");        
    }else if(mod->INDICE = 100){
        system("clear");
        printf("\n\nVocê não pode cadastrar mais livros !!!\n\n");
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");
    }    
}

void LeituraISBN(int *ISBN){
    
    system("clear");
    printf("\n#########################################");
    printf("\n#             Lendo ISBN !!!            #");
    printf("\n#########################################\n\n");
    
    printf("Digite o ISBN(Código do livro): ");
    fflush(stdin);
    scanf("%d", ISBN);    
    system("clear");
}

void ImprimeLivro(TModuloLivro mod, int i, char op){

    if(mod.INDICE >= 0 && op == 'T'){
        
        printf("\n#########################################");
        printf("\n#          Dados do livro !!!           #");
        printf("\n#########################################\n\n");

        printf("ISBN(Código do livro): %d\n\n", mod.livros[i].ISBN);

        printf("Título do livro: %s\n", mod.livros[i].titulo);

        printf("Edição: %d\n\n", mod.livros[i].edicao);

        printf("Nome do autor: %s\n", mod.livros[i].autor);

        printf("Nome da editora: %s\n", mod.livros[i].editora);

        printf("Volume: %d\n\n", mod.livros[i].volume);

        printf("Numero de exemplares: %d\n\n", mod.livros[i].numExemplar);

        printf("Data da publicação: %d/%d/%d\n", mod.livros[i].DATA_DE_PUB.dia,
              mod.livros[i].DATA_DE_PUB.mes, mod.livros[i].DATA_DE_PUB.ano 
              );
                
    }else if(mod.INDICE >= 0 && op == 'F'){
        
        printf("\n#########################################");
        printf("\n#          Dados do livro !!!           #");
        printf("\n#########################################\n\n");

        printf("ISBN(Código do livro): %d\n\n", mod.livros[i].ISBN);

        printf("Título do livro: %s\n", mod.livros[i].titulo);

        printf("Edição: %d\n\n", mod.livros[i].edicao);

        printf("Nome do autor: %s\n", mod.livros[i].autor);

        printf("Nome da editora: %s\n", mod.livros[i].editora);

        printf("Volume: %d\n\n", mod.livros[i].volume);

        printf("Numero de exemplares: %d\n\n", mod.livros[i].numExemplar);

        printf("Data da publicação: %d/%d/%d\n", mod.livros[i].DATA_DE_PUB.dia,
              mod.livros[i].DATA_DE_PUB.mes, mod.livros[i].DATA_DE_PUB.ano 
              );
        
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");    
    }else {
        system("clear");
        printf("\n\nLivro não encontrado !!!\n\n");
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");                    
    }   
}

int Pesquisar(TLivro L, TModuloLivro *mod, int ISBN) {
    
    int aux;
    
    for(aux = 0; aux < mod->INDICE; aux++){
                
        if(mod->livros[aux].ISBN == ISBN){
//            printf("\n\t\t\tO indice do livro é: %d", aux);
//            __fpurge(stdin);
//            getchar();
            return aux;
        }
    }
    
    return -1;
}

void Alterar(TModuloLivro *mod, TLivro L, int i) {
    
    if(i != -1){
        system("clear");
        printf("\n\nOs dados estao corretos !!!\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");
        printf("\n\nAperte Enter para Alterar os dados.\n\n");
        __fpurge(stdin);
        getchar();
        LeituraDeDados(&L);
        system("clear");
        mod->livros[i] = L;
        printf("\n\nLivro Alterado.\n\n");
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");
    }else{
        system("clear");
        printf("\n\nLivro Não Encontrado.\n\n");
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");                    
    }    
         
}

void Excluir(TModuloLivro *mod, int i) {
     
    TLivro Livro;
    int j;
                                
    if(mod->INDICE >= 0){
        system("clear");
        printf("\n\nLivro encontrado !!!\n\n");
        printf("\n\nAperte Enter para Excluir o Livro.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");    
    
        mod->livros[i] = Livro;
    
        for(j = i; j < mod->INDICE; j++){
        
            mod->livros[j] = mod->livros[j+1];
        }
    
        mod->INDICE--;
       
        printf("\n\nLivro Excluido.\n\n");
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");
    }else{
        system("clear");
        printf("\n\nLivro Não Excluido.\n\n");
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");                    
    }
}

void Imprimir (TModuloLivro mod) {
    
    int i;
    
    if(mod.INDICE > 0){
       
        system("clear");        
        for(i = 0; i < mod.INDICE; i++){

            if(i < mod.INDICE){
                ImprimeLivro(mod, i, 'T');
            }
        }
    
        printf("\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");        
            
    }else{
        system("clear");
        printf("\n\nNão existe nenhum livro cadastrado.\n\n");                    
        printf("\n\nAperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");                    
    }
}

void Sair() {
    char op;
    system("clear");
    printf("\n\nDeseja realmente sair? s =  sim/ n = não: ");
    __fpurge(stdin);
    scanf("%c", &op);
    
    if(op == 's' || op == 'S'){
        
        system("clear");
        printf("\n\nObrigado pro utilizar nosso programa!!!");
        printf("\n\nAperte enter para sair.");
        __fpurge(stdin);
        getchar();    
   }else if(op == 'n' || op == 'N'){
        
        system("clear");
        printf("\n\nObrigado pro continuar no programa !!!");
        printf("\n\nAperte enter para voltar ao menu.");
        __fpurge(stdin);
        getchar();
        system("clear");
        menu();
    }else{
    
        system("clear");    
        printf("\n\nOpção incorreta Aperte enter e digite novamente !!!");
        __fpurge(stdin);
        getchar();
        system("clear");
        Sair();
    }    
}

void menuBiblioteca(){
    
    TModuloLivro ModL;
    TLivro L;    
    int op;
    int INDI;
    int ISBN;

do{    
    system("clear");
    printf("#################---Menu---######################\n");
    printf("#\t\t1 - Cadastrar\t\t\t#\n");
    printf("#\t\t2 - Pesquisar\t\t\t#\n");
    printf("#\t\t3 - Alterar\t\t\t#\n");
    printf("#\t\t4 - Imprimir\t\t\t#\n");
    printf("#\t\t5 - Excluir\t\t\t#\n");        
    printf("#\t\t0 - Voltar ao Menu\t\t#\n");
    printf("#################################################\n");
    printf("Digite a Opção: ");
    __fpurge(stdin);
    scanf("%i", &op);
    
    switch (op) {
        case 1:
            LeituraDeDados(&L);
            Cadastrar(L, &ModL);
        break;
        case 2:            
            LeituraISBN(&ISBN);
            INDI = Pesquisar(L, &ModL, ISBN);
            ImprimeLivro(ModL, INDI, 'F');
        break;
        case 3:
            LeituraISBN(&ISBN);
            INDI = Pesquisar(L, &ModL, ISBN);
            Alterar(&ModL, L, INDI);   
        break;
        case 4:
            Imprimir(ModL);
        break;
        case 5:
            LeituraISBN(&ISBN);
            INDI = Pesquisar(L, &ModL, ISBN); 
            Excluir(&ModL, INDI);
        break;
        case 0:
            menu();
        break;
        default:
            system("clear");
            printf("\n\nOpção Incorretar.\n\n");
            printf("\n\nAperte Enter para voltar ao menu.\n\n");
            __fpurge(stdin);
            getchar();
            menuBiblioteca();
            system("clear");
        break;    
    }
}while(op != 0);    
}
