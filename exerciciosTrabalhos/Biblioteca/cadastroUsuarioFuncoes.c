#include "cadastroUsuario.h"

void IniciarUsuario(TModoloUsuario *mod){
    
    mod->INDICE = 0;
}

void leituraDadosUsuario(TUsuario *usua){
    
    system("clear");
    printf("\n####################################################");
    printf("\n#              Lendo Dados do Usuário!!!           #");
    printf("\n####################################################\n\n");
        
    printf("Digite seu nome: ");
    __fpurge(stdin);
    fgets(usua->Nome, 100, stdin);
 
    printf("\nDigite seu sobre nome: ");
    __fpurge(stdin);
    fgets(usua->SoNome, 100, stdin);
    
    printf("\nDigite sua idade: ");
    __fpurge(stdin);
    scanf("%i", &usua->idade);
    
    printf("\nDigite seu CPF: ");
    __fpurge(stdin);
    fgets(usua->CPF, 11, stdin);
    
    printf("\nDigite o numero da sua matricula: ");
    __fpurge(stdin);
    scanf("%i", &usua->matricula);
}

leituraNomeUsuario(char *nome[100]){

    system("clear");
    printf("\n#########################################\n");
    printf("#          Buscando Usuario !!!         #");
    printf("\n#########################################\n\n");    
    
    printf("Digite seu nome: ");
    __fpurge(stdin);
    fgets(nome, 100, stdin);
}

void imprimeUsuario(TModoloUsuario mod, int INDICE, char op){
    
    if(INDICE >= 0 && op == 'F'){
        
        system("clear");
        printf("\n####################################################");
        printf("\n#           Imprimindo Dados do Usuário!!!         #");
        printf("\n####################################################\n\n");    
        
        printf("Nome: %s\n",mod.usuario[INDICE].Nome);
    
        printf("Sobre Nome: %s\n",mod.usuario[INDICE].SoNome);
    
        printf("Idade: %i\n\n",mod.usuario[INDICE].idade);
    
        printf("CPF: %s\n",mod.usuario[INDICE].CPF);
    
        printf("Matricula: %i\n",mod.usuario[INDICE].matricula);
    
        printf("\nAperte Enter para voltar ao menu!!!");
        __fpurge(stdin);
        getchar();
    }else if(INDICE >= 0 && op == 'T'){

        printf("\n####################################################");
        printf("\n#           Imprimindo Dados do Usuário!!!         #");
        printf("\n####################################################\n\n");    
        
        printf("Nome: %s\n",mod.usuario[INDICE].Nome);
    
        printf("Sobre Nome: %s\n",mod.usuario[INDICE].SoNome);
    
        printf("Idade: %i\n\n",mod.usuario[INDICE].idade);
    
        printf("CPF: %s\n",mod.usuario[INDICE].CPF);
    
        printf("Matricula: %i\n",mod.usuario[INDICE].matricula);            
    }else{
        system("clear");
        printf("\n\nLivro não encontrado !!!\n\n");
        printf("Aperte Enter para voltar ao menu.\n\n");
        __fpurge(stdin);
        getchar();
        system("clear");   
    }
}

void cadastrarUsuario(TModoloUsuario *mod, TUsuario usua){
    
    mod->usuario[mod->INDICE] = usua;
    mod->INDICE++;
    
    system("clear");
    printf("\n\nUsuario cadastrado com sucesso !!!");
    printf("\n\nAperte Enter para voltar ao menu !!!");    
    __fpurge(stdin);
    getchar();
    system("clear");
}

int pesquisarUsuario(TModoloUsuario mod, char nome[100]){
    
    int i;
    
    for(i = 0; i < mod.INDICE; i++){
        if(strcmp(mod.usuario[i].Nome, nome) == 0){
            return i;
        }
    }
    return -1;
}

void alterarUsuario(TModoloUsuario *mod, TUsuario usua, int INDICE){
    
    if(INDICE >= 0){
        leituraDadosUsuario(&usua);
        mod->usuario[INDICE] = usua;
        printf("\n\nUsuario Alterado com sucesso.");
        printf("\n\nAperte Enter para voltar ao menu !!!");
        __fpurge(stdin);
        getchar();
    }else{
        printf("\n\nUsuario não auterado.");
        printf("\n\nAperte Enter para voltar ao menu !!!");        
        __fpurge(stdin);
        getchar();
    }
}

void excluirUsuario(TModoloUsuario *mod, int INDICE){
    
    int i;
    i = INDICE;
    
    for(i; i <= mod->INDICE; i++){
        
        mod->usuario[i] = mod->usuario[i+1];
    }
    
    mod->INDICE--;
    
    printf("\n\nUsuario Excluido com sucesso.");
    printf("\n\nAperte Enter para voltar ao menu !!!");        
    __fpurge(stdin);
    getchar();    
}

void ImprimirU(TModoloUsuario mod){
    
    int i;
    
    if(mod.INDICE > 0){
        system("clear");
        for(i = 0; i < mod.INDICE; i++){
            imprimeUsuario(mod , i, 'T');
        }
        printf("\n\nAperte Enter para voltar ao menu !!!");
        __fpurge(stdin);
        getchar();
    }else{
        printf("\n\nNão existe usuário cadastrados!!!!");        
        printf("\n\nAperte Enter para voltar ao menu !!!");
        __fpurge(stdin);
        getchar();        
    }
}

void menuCadastroUsuario(){
    
    int op;
    char nome[100];
    int resultado;
    TModoloUsuario ModUsuario;
    TUsuario usuario;
do{    
    system("clear");
    printf("#################-Controle de Usuario-###################\n");
    printf("#\t\t1 - Cadastrar Usuario\t\t\t#\n");
    printf("#\t\t2 - Pesquisar Usuario\t\t\t#\n");
    printf("#\t\t3 - Alterar Usuario\t\t\t#\n");
    printf("#\t\t4 - Imprimir Usuario\t\t\t#\n");
    printf("#\t\t5 - Excluir Usuario\t\t\t#\n");
    printf("#\t\t0 - Voltar ao Menu\t\t\t#\n");
    printf("#########################################################\n");
    printf("Digite a Opção: ");
    __fpurge(stdin);
    scanf("%i", &op);

    switch (op) {
        case 1:
            leituraDadosUsuario(&usuario);
            cadastrarUsuario(&ModUsuario, usuario);
        break;
        case 2:            
            leituraNomeUsuario(&nome);
            resultado = pesquisarUsuario(ModUsuario, nome);
            imprimeUsuario(ModUsuario, resultado, 'F');
        break;
        case 3:
            leituraNomeUsuario(&nome);
            resultado = pesquisarUsuario(ModUsuario, nome);
            alterarUsuario(&ModUsuario, usuario, resultado);
        break;
        case 4:
            ImprimirU(ModUsuario);
        break;
        case 5:
            leituraNomeUsuario(&nome);
            resultado = pesquisarUsuario(ModUsuario, nome);
            excluirUsuario(&ModUsuario, resultado);
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
            menuCadastroUsuario();
            system("clear");
        break;    
    }   
}while(op != 0);
}

