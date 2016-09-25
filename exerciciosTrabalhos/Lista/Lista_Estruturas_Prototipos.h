/* 
 * File:   Lista_Estruturas_Prototipos.h
 * Author: informatica19
 *
 * Created on 18 de Dezembro de 2015, 07:32
 */

#ifndef LISTA_ESTRUTURAS_PROTOTIPOS_H
#define	LISTA_ESTRUTURAS_PROTOTIPOS_H
#ifdef	__cplusplus
extern "C" {
#endif

/*
 * Estura TipoItem com todos os dados do carro
 */

typedef struct {

    int ano;
    char marca[100];
    char modelo[100];
    char chassi[100];
    char placa[100];
    
}TipoItem;

/*
 * Estutura do tipo Celula Onde criamos as celulas e o prox
 */

typedef struct celula {
    
    TipoItem item;
    struct celula *prox;
    
}Celula;

/*
 * Estrutura do tipo lista onde usamos o auxliar ultimo e primeiro para apontar
 * as listas
 */

typedef struct lista {
    
    Celula *primeiro;
    Celula *ultimo;
    int TAMANHO;
    
}Lista;

/*
 * Prototipo das funções que seram usadas
 */

/*
 * Função usada para inicializar uma Celula
 */
void FLVazia (Lista *lista);

/*
 * Funcção usada para inserir uma Celula
 */

void Inserir (Lista *lista, TipoItem item);

/*
 * Função que verifica se a Lista está vazria
 */

int VLVazia (Lista lista);

/*
 * Função para ler os dados antes de inserir
 */

void LeituraDados (TipoItem *item);

/*
 * Função para imprimir todos os dados
 */

void ImprimirDadosCarros (Lista lista);

/*
 * Retorna a quantidade de Celulas que existe em uma lista
 */

int QuantidadeDeCelulas (Lista lista);

/*
 * Pesquisa se um item existe e se encontraco retorna os dados dele
 */

Celula* Pesquisar (Lista lista, TipoItem item);

/*
 * Exclui uma Celular e o item que está dentro dela
 */

void Excluir (Lista * lista, Celula *aux, TipoItem *item);

/*
 * Libera a memória de uma lista
 */

void LiberaMemoria (Lista *lista);

/*
 * Retorna o tamanho de uma lista
 */

int Tamanho (Lista lista);

/*
 * Recebe duas lista, e copira a segunda lista para dentro da primeira
 */

void CopiarLista (Lista *lista1, Lista *lista2);

/*
 * Verifica se as listas que foram passadas são iguais
 */

int VerificaListaIguais (Lista lista1, Lista lista2);

/*
 * Lê o chassi do carro para fazer a pesquisa na lista
 */

void LeituraChassi (TipoItem *item);

#ifdef	__cplusplus
}
#endif

#endif	/* LISTA_ESTRUTURAS_PROTOTIPOS_H */

