#include "emprestimoFuncoes.h"

void iniciarEmprestimo(TModoloEmprestimo *emprestimo){
    emprestimo->INDICE = 0;
}

void leituraMatriculaEmprestimo(int *matricula){
    
    system("clear");
    printf("\n########################################################");
    printf("\n#              Lendo Matricula Emprestimo!!!           #");
    printf("\n########################################################\n\n");
        
    printf("\nDigite a matricula: ");
    __fpurge(stdin);
    scanf("%i", matricula);
}

void leituraDadosEmprestimo(TEmprestimo *emprestimo){
    system("clear");
    printf("\n#######################################################");
    printf("\n#              Lendo Dados do Emprestimo!!!           #");
    printf("\n#######################################################\n\n");
        
    printf("Digite o ISBN: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->ISBN);
 
    printf("\nDigite a matricula: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->matricula);    
    
    printf("\nDia do Emprestimo: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->dataEmprestimo.dia);    

    printf("\nMês do Emprestimo: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->dataEmprestimo.mes);    

    printf("\nAno do Emprestimo: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->dataEmprestimo.ano);
    
    printf("\nDia da Entrega: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->dataEntrega.dia);
    
    printf("\nMês da Entrega: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->dataEntrega.mes);

    printf("\nAno da Entrega: ");
    __fpurge(stdin);
    scanf("%i", &emprestimo->dataEntrega.ano);    
}

void cadastroEmprestimo(TUsuario *usuario, TLivro *livro, TModoloEmprestimo *modoloE, TEmprestimo emprestimo, int resultado){
    
    if(resultado == 1){
        modoloE->emprestimo[modoloE->INDICE] =  emprestimo;
        modoloE->INDICE++;
        
        usuario->limite = usuario->limite + 1;
        livro->NumEmprestimos = livro->NumEmprestimos + 1;
        
        system("clear");
        printf("\n\nEmprestimo realizado com suscesso !!!");
        printf("\n\nAperte enter para voltar ao menu.");
        __fpurge(stdin);
        getchar();
    }else{
        system("clear");
        printf("\n\nEmprestimo não pode ser realizado !!!");
        printf("\n\nAperte enter para voltar ao menu.");
        __fpurge(stdin);
        getchar();        
    }
    
}

int pesquisaCadastroEmprestimo(TModoloUsuario modUs, TModuloLivro modLi,TModoloEmprestimo modoloE, int caso){

    int i;
    int j;
    
    for(i = 0; i <= modLi.INDICE; i++){        
        if(modLi.livros[i].ISBN == modoloE.emprestimo[i].ISBN){
            for(j = 0; j <= modUs.INDICE; j++){
                if(modUs.usuario[j].matricula == modoloE.emprestimo[i].matricula && modUs.usuario[j].limite < 3 && modoloE.emprestimo[j].status == 1){
                    if(caso == 2 || caso == 3 || caso == 4){
                        return i;
                    }
                    return 1;
                }
            }
        }
    }
    return -1;
}

void devolveEmprestimo(TLivro *livro, TUsuario *usuario, TModoloEmprestimo *modoloE, int matricula){

    int i;
    
    for(i = 0; i <= modoloE->INDICE; i++){
        
        if(matricula == modoloE->emprestimo[i].matricula){
            modoloE->emprestimo[i].status = 0;
            printf("A devolução foi feita com sucesso !!!");
        }
    }
}

void imprimirEmprestimo(TModoloEmprestimo modoloE, int indice){
    system("clear");
    printf("\n##################################################");
    printf("\n#              Imprimir  Emprestimo!!!           #");
    printf("\n##################################################\n\n");
        
    printf("Digite o ISBN: %i", modoloE.emprestimo[indice].ISBN);
 
    printf("\nData da devolução: %i/%i/%i", modoloE.emprestimo[indice].dataDevolucao.dia, modoloE.emprestimo[indice].dataDevolucao.mes, 
        modoloE.emprestimo[indice].dataDevolucao.ano);    
    
    printf("\nData do Emprestimo: %i/%i/%i", modoloE.emprestimo[indice].dataEmprestimo.dia, modoloE.emprestimo[indice].dataEmprestimo.mes,
        modoloE.emprestimo[indice].dataEmprestimo.ano);
    
    printf("\nData da Entrega: %i/%i/%i", modoloE.emprestimo[indice].dataEntrega.dia, modoloE.emprestimo[indice].dataEntrega.mes,
        modoloE.emprestimo[indice].dataEntrega.ano);
    
    printf("\nMatricula: %i", modoloE.emprestimo[indice].matricula);

    printf("\nMultaa: %d", modoloE.emprestimo[indice].multaEmprestimo);
    __fpurge(stdin);
    getchar();
}

void pagarMultaEmprestimo(TModoloEmprestimo *modoloE, TUsuario usuario, int mat){
    int i;
    
    for(i = 0; i <= modoloE->INDICE; i++){
        
        if(mat == modoloE->emprestimo[i].matricula){
            modoloE->emprestimo[i].status = 0;
            printf("A devolução foi feita com sucesso !!!");
        }
    }    
}

void menuCadastroEmprestimo(){
    
    int op;
    int resultado;
    int resultado2;
    TEmprestimo emprestimo;
    TUsuario usuario;
    TLivro livro;
    TModoloEmprestimo modoloE;
    TModoloUsuario modUs;
    TModuloLivro modLi;
    int matricula;
    
    do{    
    system("clear");
    printf("################-Controle de Emprestimo-#################\n");
    printf("#\t\t1 - Cadastrar Emprestimo\t\t#\n");
    printf("#\t\t2 - Pesquisar Emprestimo\t\t#\n");
    printf("#\t\t3 - Devolver Emprestimo\t\t\t#\n");
    printf("#\t\t4 - Pagar Multa\t\t\t\t#\n");
    printf("#\t\t0 - Voltar ao Menu\t\t\t#\n");
    printf("#########################################################\n");
    printf("Digite a Opção: ");
    __fpurge(stdin);
    scanf("%i", &op);

        switch (op) {
            case 1:
                leituraDadosEmprestimo(&emprestimo);
                resultado = pesquisaCadastroEmprestimo(modUs, modLi, modoloE, 0);
                cadastroEmprestimo(&usuario, &livro, &modoloE, emprestimo, resultado);                
            break;
            case 2:            
                leituraMatriculaEmprestimo(&matricula);
                resultado = pesquisaCadastroEmprestimo(modUs, modLi, modoloE, 2);
                imprimirEmprestimo(modoloE, resultado);
            break;
            case 3:
                leituraMatriculaEmprestimo(&matricula);
                resultado = pesquisaCadastroEmprestimo(modUs, modLi, modoloE, 3);               
                imprimirEmprestimo(modoloE, resultado);
            break;
            case 4:
                leituraMatriculaEmprestimo(&matricula);
                resultado = pesquisaCadastroEmprestimo(modUs, modLi, modoloE, 4);
                imprimirEmprestimo(modoloE, resultado);
            break;
            case 0:
                menu();    
            break;
            default:
                system("clear");
                printf("\n\n\t\t\tOpção Incorretar.\n\n");
                printf("\n\n\t\t\tAperte Enter para voltar ao menu.\n\n");
                __fpurge(stdin);
                getchar();
                menuCadastroEmprestimo();
                system("clear");
            break;    
        }   
    }while(op != 0);  
}