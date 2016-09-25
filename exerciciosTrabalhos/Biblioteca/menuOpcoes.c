#include "menu.h"

void menu(){
    int op;
    
    system("clear");    
    printf("#######################---Menu---########################\n");
    printf("#\t\t1 - Cadastrar Livro\t\t\t#\n");
    printf("#\t\t2 - Cadastrar Usuario\t\t\t#\n");    
    printf("#\t\t3 - Emprestimo de Livros\t\t#\n");
    printf("#\t\t4 - Sair do Programa\t\t\t#\n");         
    printf("#########################################################\n");
    printf("Digite a Opção: ");
    __fpurge(stdin);
    scanf("%i", &op);
 
    switch (op) {
        case 1:
            menuBiblioteca();
        break;
        case 2:            
            menuCadastroUsuario();
        break;
        case 3:
            menuCadastroEmprestimo();
        break;    
        case 4:
            Sair();
        break;
        default:
            system("clear");
            printf("\n\n\t\t\tOpção Incorretar.\n\n");
            printf("\n\n\t\t\tAperte Enter para voltar ao menu.\n\n");
            __fpurge(stdin);
            getchar();
            system("clear");
            menu();
        break;    
    }
}