
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_Estruturas_Prototipos.h"

/*
 * Função usada para inicializar uma Celula
 */

void FLVazia(Lista *lista) {

    lista->primeiro = (Celula*) malloc(sizeof (Celula));
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
    lista->TAMANHO = 0;
}

/*
 * Função para ler os dados antes de inserir
 */

void LeituraDados(TipoItem *item) {

    system("clear");

    printf("\n-----------------------Leitura de Dados-----------------------\n");
    printf("\nDigite o Ano do carro: ");
    __fpurge(stdin);
    scanf("%d", &item->ano);

    printf("\nDigite a Marca do carro: ");
    __fpurge(stdin);
    fgets(item->marca, 100, stdin);

    printf("\nDigite o Modelo do carro: ");
    __fpurge(stdin);
    fgets(item->modelo, 100, stdin);

    printf("\nDigite o Chassi do carro: ");
    __fpurge(stdin);
    fgets(item->chassi, 100, stdin);

    printf("\nDigite a Placa do carro: ");
    __fpurge(stdin);
    fgets(item->placa, 100, stdin);

}

/*
 * Funcção usada para inserir uma Celula
 */

void Inserir(Lista *lista, TipoItem item) {

    lista->ultimo->prox = (Celula*) malloc(sizeof (Celula));
    lista->ultimo = lista->primeiro;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = item;
    lista->TAMANHO++;

    if (lista->TAMANHO > 0) {
        system("clear");
        printf("\nItem Inserido com sucesso !!!");
        printf("\nAperte Enter para voltar ao menu.");
        __fpurge(stdin);
        getchar();
    }
}

/*
 * Função que verifica se a Lista está vazria
 */

int VLVazia(Lista lista) {

    return (lista.primeiro == lista.ultimo);

}

/*
 * Função para imprimir todos os dados
 */

void ImprimirDadosCarros(Lista lista) {

    system("clear");

    if (!VLVazia(lista)) {

        Celula *aux;
        aux = lista.primeiro;
        
        while (aux->prox != NULL) {
            
            printf("\n\n-------------------Imprimindo Dados------------------\n");
            
            printf("Digite o Ano do carro:    %d\n", aux->prox->item.ano);

            printf("Digite a Marca do carro:  %s\n", aux->prox->item.marca);

            printf("Digite o Modelo do carro: %s\n", aux->prox->item.modelo);

            printf("Digite o Chassi do carro: %s\n", aux->prox->item.chassi);

            printf("Digite a Placa do carro:  %s\n", aux->prox->item.placa);
            
            aux = aux->prox;
        }
    }
    
    printf("\nAperte Enter para voltar ao menu.");
    __fpurge(stdin);
    getchar();
}

/*
 * Retorna a quantidade de Celulas que existe em uma lista
 */

int QuantidadeDeCelulas(Lista lista) {

    int i = 0;

    if (!VLVazia(lista)) {

        Celula *aux;

        aux = lista.primeiro;

        while (aux->prox != NULL) {
            i++;
            aux = aux->prox;
        }
    }

    return i;

}

/*
 * Pesquisa se um item existe e se encontraco retorna os dados dele
 */

Celula* Pesquisar(Lista lista, TipoItem item) {

    if (!VLVazia(lista)) {
        Celula *aux;

        for (aux = lista.primeiro; aux->prox != NULL; aux = aux->prox) {

            if (strcmp(aux->prox->item.chassi, item.chassi) == 0) {
    
                return aux;
            }
        }
    }else {
        return NULL;
    }
}

/*
 * Exclui uma Celular e o item que está dentro dela
 */

void Excluir(Lista * lista, Celula *aux, TipoItem *item) {

    if (!VLVazia(*lista) && aux != NULL) {

        Celula *aux2;
        aux2 = aux->prox;
        aux->prox = aux2->prox;

        *item = aux2->item;

        if (lista->ultimo == aux2) {

            lista->ultimo = aux;
            free(aux2);
            printf("Elemente Excluido !");

        }

        printf("Elemente não Excluido !");
    }
}

/*
 * Libera a memória de uma lista
 */

void LiberaMemoria(Lista *lista) {

    TipoItem item;

    while (!VLVazia(*lista)) Excluir(lista, lista->primeiro, &item);

    free(lista->primeiro);
}

/*
 * Retorna o tamanho de uma lista
 */

int Tamanho(Lista lista) {
    return lista.TAMANHO;
}

/*
 * Recebe duas lista, e copira a segunda lista para dentro da primeira
 */

void CopiarLista(Lista *lista1, Lista *lista2) {

    if (!VLVazia(*lista2)) {

        FLVazia(lista1);
        Celula *aux;

        for (aux = lista2->primeiro; aux->prox != NULL; aux = aux->prox) {

            Inserir(lista1, aux->prox->item);

        }
    }

}

/*
 * Verifica se as listas que foram passadas são iguais
 */

int VerificaListaIguais(Lista lista1, Lista lista2) {

    int n1 = Tamanho(lista1);
    int n2 = Tamanho(lista2);

    if (n1 == n2) {

        int i = 0;
        Celula *aux1, *aux2;
        aux1 = lista1.primeiro;
        aux2 = lista2.primeiro;

        while (aux1->prox != NULL) {

            if (strcmp(aux1->prox->item.chassi, aux2->prox->item.chassi)) i++;
            else return 0;

        }

        if (i == n1) return 1;
    }
}

/*
 * Lê o chassi do carro para fazer a pesquisa na lista
 */

void LeituraChassi(TipoItem *item) {

    system("clear");

    printf("\n----------------------Leitura de Chassi----------------------\n");
    printf("\nDigite o Chassi: ");
    __fpurge(stdin);
    fgets(item->chassi, 100, stdin);
}

/*
 * Imprimir dado do carro que a pesquisa retorna
 */

void ImprimirDados(Celula cell) {

    system("clear");
    printf("\n---------------------Dados Cadastrados---------------------\n\n");

    printf("Digite o Ano do carro:    %d\n\n", cell.prox->item.ano);

    printf("Digite a Marca do carro:  %s\n", cell.prox->item.marca);

    printf("Digite o Modelo do carro: %s\n", cell.prox->item.modelo);

    printf("Digite o Chassi do carro: %s\n", cell.prox->item.chassi);

    printf("Digite a Placa do carro:  %s\n", cell.prox->item.placa);

    printf("\nAperte Enter para voltar ao menu.");
    __fpurge(stdin);
    getchar();

}