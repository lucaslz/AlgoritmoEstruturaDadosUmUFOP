#include <structprototipo.h>
#include <time.h>
#include <windows.h>
//#include <stdio.h>
//#include <stdlib.h>

//Fazendo Pista Vazia

void pistaVazia(Lista *lista1, Lista *lista2) {

    lista1->primeiro = (Celula*) malloc(sizeof (Celula));
    lista1->ultimo = lista1->primeiro;
    lista1->ultimo->proximo = NULL;
    lista1->TAMANHO1 = 0;
    lista1->TAMANHO2 = 0;

    lista2->primeiro = (Celula*) malloc(sizeof (Celula));
    lista2->ultimo = lista2->primeiro;
    lista2->ultimo->proximo = NULL;
    lista2->TAMANHO1 = 0;
    lista2->TAMANHO2 = 0;
}

//Verificando Tamanho da Fila

int verificaTamanhoFila(Lista *lista = NULL, Lista *lista2 = NULL) {

    if (lista != NULL) {
        if (lista->TAMANHO1 > lista->TAMANHO2) {
            return 2;
            lista->TAMANHO2++;

        } else if (lista->TAMANHO2 > lista->TAMANHO1) {
            return 1;
            lista->TAMANHO1++;

        } else {
            return 1;
            lista->TAMANHO1++;
        }

    } else {
        if (lista->TAMANHO1 > lista->TAMANHO2) {
            return 2;
            lista->TAMANHO2++;

        } else if (lista->TAMANHO2 > lista->TAMANHO1) {
            return 1;
            lista->TAMANHO1++;

        } else {
            return 1;
            lista->TAMANHO1++;
        }
    }
}

//Verifica em qual fila o avião vai entrar

void pesquisarFilaAviao(Lista lista) {

    Celula aux;
    int dados[2];

    for (aux = lista->primeiro; aux->proximo != NULL; aux = aux->proximo) {

        if (aux->proximo == NULL) {
            dados[1] = aux->item->fila;
            dados[2] = aux->item->aviao;
            return dados;
        } else {
            return 0;
        }
    }
}

//Cadastrando o tipoItem

void cadastrarTipoItem(Lista lista, tipoItem *item) {

    int pista = verificaTamanhoFila(lista);
    int dados = pesquisarFilaAviao(lista);

    if (pista > 0 && dados > 0) {
        item->aviao = dados[2]++;
        item->tempoEspera = 20;
        item->fila = pista;
    }
}

//Enfileirando o avião para Decolar ou Aterrissar

void EnfileirarAviao(Lista *lista, tipoItem item) {

    lista->ultimo->proximo = (Celula*) malloc(sizeof (Celula));
    lista->ultimo = lista->ultimo->proximo;
    lista->ultimo->proximo = NULL;
    lista->ultimo->item = item;
}

//Imprimindo a pista de Aterrissar

void imprimePistaAterrisar(Lista lista) {

    system("cls");
    printf("\n\n\n\t\t\t ___________________________");
    printf("\n\t\t\t|______ PISTA DE POUSO______| \n ");

    Celula aux;

    for (aux = lista.primeiro; aux.proximo != NULL; aux = aux.proximo) {

        if (aux.proximo == NULL) {
            printf("\n\t\t\tAviao: %d\n", aux.proximo.item.aviao);
            printf("\n\t\t\tTempo de Espera\n: %d", aux.proximo.item.tempoEspera);
            printf("\n\t\t\tFila de Espera\n: %d", aux.proximo.item.fila);

        }
    }
}

//Imprimindo a pista de Decolar

void imprimePistaDecolar(Lista lista) {

    system("cls");
    printf("\n\n\n\t\t\t ___________________________");
    printf("\n\t\t\t|__ PISTA DE DECOLAGEM__| \n ");

    Celula aux;

    for (aux = lista.primeiro; aux.proximo != NULL; aux = aux.proximo) {

        if (aux.proximo == NULL) {
            printf("\n\t\t\tAviao: %d\n", aux.proximo.item.aviao);
            printf("\n\t\t\tTempo de Espera\n: %d", aux.proximo.item.tempoEspera);
            printf("\n\t\t\tFila de Espera\n: %d", aux.proximo.item.fila);

        }
    }
}

//Imprimindo o avião que está com a gasolina acabando
//A pista auxiliar ou pista de emergência é a que esta vazia no momento

void imprimePistaEmergencia(Lista lista) {

    system("cls");
    printf("\n\n\n\t\t\t ___________________________");
    printf("\n\t\t\t|____ PISTA AUXILIAR ____| \n ");

    Celula aux;

    for (aux = lista.primeiro; aux.proximo != NULL; aux = aux.proximo) {

        if (aux.proximo == NULL) {
            printf("\n\t\t\tAviao: %d\n", aux.proximo.item.aviao);
            printf("\n\t\t\tTempo de Espera\n: %d", aux.proximo.item.tempoEspera);
            printf("\n\t\t\tFila de Espera\n: %d", aux.proximo.item.fila);

        }
    }
}

//Função para calcular o tempo de espera de aviao

int contagemTempoAvioes() {

    int TEMPO_ESPERA = 20000; //em milisegundos

    clock_t inicio, espera;
    
    espera = (TEMPO_ESPERA / 20000) * CLK_TCK;

    inicio = clock();

    while ((clock() - inicio) < espera) {
        system("cls");
        printf("Contagem do Tempo: %d", (clock() - inicio) < espera);
    }

    return 0;
}

//Vrifica qual pista está mais vazia para fazer pouso de emergência

int verificaPistaPousoEmergencia(Lista *lista, Lista *lista2) {

    int fila1_2, fila3;

    fila1_2 = verificaTamanhoFila(lista, NULL);
    fila3 = verificaTamanhoFila(NULL, lista2);

    if (lista->TAMANHO1 > lista->TAMANHO2) {

        if (lista->TAMANHO1 > lista2->TAMANHO1) {

            return "pista 3";

        } else {

            return "pista 1";
        }

    } else {
        if (lista->TAMANHO2 > lista2->TAMANHO1) {

            return "pista 3";

        } else {

            return "pista 1";
        }
    }
}