/* 
 * File:   main.c
 * Author: nobreack
 *
 * Created on 3 de Dezembro de 2015, 18:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Estrutura de usuario
 */

typedef struct usuario {
    //Nome do Usuario da rede social
    char nome[100];

    //E-mail do usuário da rede social
    char email[100];

    //Login do usuário da rede social
    char login[50];

    //Senha do usuário da rede social
    char senha[100];

    //Ano em que o usuário da rede social nasceu
    int ano_nascimento;

    //ID do usuário da rede social, com ele idetificamos o usuário ou indice
    int id_usuario;

    //Grava o id do usuario na lista de amigos
    int lista_amigos[100];

    //Indice para gravar um usuário na lista de amigos
    int INDICE;

} TUser;

/*
 * Estrutura que guarda a matriz de relacionamento dos usuários
 */

typedef struct m_relacionamento {
    //Matriz de relacionamento dos usuários
    int relacionamento;

} TMRelacionamento;

/*
 * Módulo para controlar o cadastro e o relacionamento dos usuários
 */

typedef struct rede {
    //Variável que alxilia no indice de cada usuário
    int INDICE;

    //Estrutura de cadastro do usuário
    TUser usuario[100];

    //Estrutura de cadastro de relacionamento de usuarios
    TMRelacionamento relaciona[10][10];

    // Dois usuário que não tenha amigos em comum
    int u1, u2;

} TModuloRede;

/*
 * Inicia o indice do Modulo, e o " n " da struct TMRelacionamento 
 */

void IniciarVariaveis(TModuloRede *rede) {

    rede->INDICE = 0;
}

/*
 * Função para ler os dados do usuário para cadastra-lo no sistema
 */

void leituraDados(TUser *usuario) {

    printf("\nNome: ");
    __fpurge(stdin);
    fgets(usuario->nome, 100, stdin);

    printf("\nE-mail: ");
    __fpurge(stdin);
    fgets(usuario->email, 100, stdin);

    printf("\nAno de nascimento: ");
    __fpurge(stdin);
    scanf("%i", &usuario->ano_nascimento);

    printf("\nLogin: ");
    __fpurge(stdin);
    fgets(usuario->login, 50, stdin);

    printf("\nSenha: ");
    __fpurge(stdin);
    fgets(usuario->senha, 20, stdin);

    printf("\nID do usuário: ");
    __fpurge(stdin);
    scanf("%d", &usuario->id_usuario);
}

/*
 * Função para cadastrar o usuário
 */

void cadastrarUsuario(TUser usuario, TModuloRede *rede) {

    //Inserindo o usuario no modulo
    rede->usuario[rede->INDICE] = usuario;

    //Incrementando o indice para cadastrar mais usuarios
    rede->INDICE++;
}

void digitarNome(char *nome1, char *nome2) {

    printf("\nDigite o nome do usuário: ");
    __fpurge(stdin);
    fgets(nome1, 100, stdin);

    printf("Digite o nome do usuário: ");
    __fpurge(stdin);
    fgets(nome2, 100, stdin);
}

void digitarNomeAux(char *nome1) {

    printf("\nDigite o nome do usuário: ");
    __fpurge(stdin);
    fgets(nome1, 100, stdin);
}

void relacionaAmizade(TModuloRede *rede, int indice1, int indice2) {

    rede->usuario[indice1].INDICE++;
    rede->usuario[indice2].INDICE++;

    int i;
    int j;

    if ((indice1 >= 0 && indice1 <= 50) || (indice2 >= 0 && indice2 <= 50)) {

        rede->relaciona[indice1][indice2].relacionamento = 1;
        rede->relaciona[indice2][indice1].relacionamento = 1;

        rede->usuario[indice1].lista_amigos[rede->usuario[indice1].INDICE] = indice2;
        rede->usuario[indice2].lista_amigos[rede->usuario[indice2].INDICE] = indice1;
    }
}

void procurarUsuario(TModuloRede *rede, char nome1[100], char nome2[100]) {

    int i;
    int indice1;
    int indice2;

    for (i = 0; i < rede->INDICE; i++) {

        if (strcmp(rede->usuario[i].nome, nome1)) {

            indice1 = i;

        } else if (strcmp(rede->usuario[i].nome, nome2)) {

            indice2 = i;
        }
    }

    relacionaAmizade(rede, indice1, indice2);
}

int procurarUsuarioAux(TModuloRede *rede, char *nome1) {

    int i;
    int indice1;
    int indice2;

    for (i = 0; i < rede->INDICE; i++) {

        if (!strcmp(rede->usuario[i].nome, nome1)) {

            return i;
        }
    }
}

void zerarMatriz(TModuloRede *rede) {

    int i;
    int j;

    for (i = 0; i <= 10; i++) {

        for (j = 0; j <= 10; j++) {

            rede->relaciona[i][j].relacionamento = 0;
        }
    }
}

void imprimirMatriz(TModuloRede *rede) {

    int i;
    int j;

    for (i = 0; i < rede->INDICE; i++) {

        for (j = 0; j < rede->INDICE; j++) {

            printf("%i", rede->relaciona[i][j].relacionamento);
        }

        printf("\n");
    }

    printf("Aperte enter para sair da matriz !!!");
    __fpurge(stdin);
    getchar();
}

void excluirUsuario(TModuloRede *rede, int indice1) {

    rede->usuario[indice1].id_usuario = -1;

    int i;
    int j;

    for (i = 0; i <= 100; i++) {

        for (j = 0; j <= 100; j++) {

            if (rede->relaciona[j][indice1].relacionamento == 1 || rede->relaciona[indice1][j].relacionamento == 1) {

                rede->relaciona[indice1][j].relacionamento = 0;

            } else if (rede->relaciona[i][indice1].relacionamento == 1 || rede->relaciona[indice1][i].relacionamento == 1) {

                rede->relaciona[i][indice1].relacionamento = 0;
            }
        }
    }
}

void usuarios2AmigosComun(TModuloRede *rede) {

    int i, j, n, k, count;

    for (i = 0; i < n; n - 1) {
        for (j = i + 1; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (rede->relaciona[i][k].relacionamento == 1 && rede->relaciona[j][k].relacionamento == 1) {
                    count = 1;
                }
                if (count == 0) {
              
                    rede->u1 = i;
                    rede->u2 = j;
                    printf("2 Usuarios sem amigos em como !!!\n\n");
                    printf("ID usuario 1: %i", rede->u1);
                    printf("ID usuario 2: %i", rede->u2);
                    __fpurge(stdin);
                    getchar();
                    return;
                }
            }
        }
    }
}

void Usuario1AmigoComum(TModuloRede rede) {

    int i, j, n, k, count;

    for (i = 0; i < n; n - 1) {
        for (j = i + 1; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (rede.relaciona[i][k].relacionamento == 1 && rede.relaciona[j][k].relacionamento == 1) {
                    
                    printf("1 Usuarios sem amigos em como !!!\n\n");
                    printf("ID usuario: %i", k);
                    __fpurge(stdin);
                    getchar();                    
                    break;
                }
            }
        }
    }
}

int usuarioMaiorNumeroAmigos(TModuloRede rede, int valor) {

    int i, j, id;

    for (i = 0; i < rede.INDICE; i++) {

        for (j = 0; j < rede.INDICE; j++) {

            if (rede.usuario[i].lista_amigos[j] > rede.usuario[i].lista_amigos[j + 1]) {

                id = i;
            }
        }
    }
    return id;
}

int quantosAmigos(TModuloRede rede, int indice) {

    int i, j, quantidade = 0;

    for (i = 0; i < rede.INDICE; i++) {

        for (j = 0; j < rede.INDICE; j++) {

            if (rede.usuario[i].lista_amigos[j] != 0) {

                quantidade = quantidade + 1;
            }
        }
    }
    return quantidade;
}

int main(int argc, char** argv) {

    TMRelacionamento relacionamento;
    TModuloRede rede;
    TUser usuario;
    char opcao;
    char nome1[100];
    char nome2[100];
    char nome3[100];
    char nome4[100];
    int valor;
    int valor2;
    int resultado1;
    int resultado2;

    IniciarVariaveis(&rede);
    zerarMatriz(&rede);

    while (opcao != '0') {

        system("clear");
        printf("#######################---Menu---########################\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Relacionar Amizade\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Dois usuarios sem amigos em comum\n");
        printf("5 - Um usuario sem amigo em comum\n");
        printf("6 - Usuario com maior numero de amigos\n");
        printf("7 - Quantos amigos um usuario tem\n");
        printf("#########################################################\n");
        printf("Digite a Opção: ");
        __fpurge(stdin);
        scanf("%c", &opcao);

        switch (opcao) {
            case '1':
            {
                leituraDados(&usuario);
                cadastrarUsuario(usuario, &rede);
                break;

            }
            case '2':
            {
                digitarNome(nome1, nome2);
                procurarUsuario(&rede, nome1, nome2);
                imprimirMatriz(&rede);
                break;
            }
            case '3':
            {
                digitarNomeAux(nome3);
                valor = procurarUsuarioAux(&rede, nome3);
                excluirUsuario(&rede, valor);
                imprimirMatriz(&rede);
                break;
            }
            case '4':
            {
                usuarios2AmigosComun(&rede);
            }
            case '5':
            {
                Usuario1AmigoComum(rede);
            }
            case '6':
            {
                resultado1 = usuarioMaiorNumeroAmigos(rede, valor2);
                system("clear");
                printf("Id do usuário com maior numero de amigos: %i", resultado1);
                __fpurge(stdin);
                getchar();
            }
            case '7':
            {
                digitarNomeAux(nome4);
                valor2 = procurarUsuarioAux(&rede, nome4);
                resultado1 = usuarioMaiorNumeroAmigos(rede, valor2);
                system("clear");
                printf("Quantidade de amigos que o usuario tem: %i", resultado2);
                __fpurge(stdin);
                getchar();
            }
            case '0':
            {
                system("clear");
                printf("\nObrigado !!!");
                __fpurge(stdin);
                getchar();
                system("clear");
                break;
            }
            default:
            {

                system("clear");
                printf("\n\n\t\t\tOpção Incorretar.\n\n");
                printf("\n\n\t\t\tAperte Enter para voltar ao menu.\n\n");
                __fpurge(stdin);
                getchar();
                system("clear");
                break;
            }
        }
    }
    return (EXIT_SUCCESS);
}