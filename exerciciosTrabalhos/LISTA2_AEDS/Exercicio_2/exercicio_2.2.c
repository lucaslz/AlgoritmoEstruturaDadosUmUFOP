#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_2.1.h"

Tno* iniciarLista() {

	Tno* lista = (Tno*)malloc(sizeof(Tno));

	if(!lista) {
		printf("Sem memória disponível!!!\n");
		exit(1);
	}

	lista->prox = NULL;

	lista = lista->prox;

	return lista;
}

void inserir (Tno* lista, TipoItem item) {

	Tno* novo = (Tno*)malloc(sizeof(Tno));

	leitura(&item);


	if(!novo) {
		printf("Sem memória disponivel.\n");
		exit(1);
	}

	novo->item = item;
	novo->prox = lista->prox;	
	lista->prox = novo;
}

Tno* buscarElemento(Tno* lista, TipoItem item) {

	Tno* p;

	for(p = lista; p != NULL; p = p->prox) {

		if(p->item.nome == item.nome) {
			return p;
		}
	}
	return NULL;
}

void nomeRemover(TipoItem* item) {
	
	system("clear");
	printf("\t\t################ Buscando nome a remover ################\n\n");

	printf("\t\tDigite seu nome: ");
	fgets(item->nome, 50, stdin);
	__fpurge(stdin);

}

void removerElemento(Tno* lista, TipoItem item) {

	nomeRemover(&item);
	Tno *elemento = buscarElemento(lista, item);

	Tno *a, *p;

	a = elemento;
	p = elemento->prox;

	if(p != NULL) {

		a->prox = p->prox;
		free(p);
	}
}

void leitura(TipoItem* item) {

	system("clear");
	printf("\t\t################ Recolhendo os dados ################\n\n");

	printf("\t\tDigite seu nome: ");
	fgets(item->nome, 50, stdin);
	__fpurge(stdin);

	printf("\t\tDigite seu Sobrenome: ");
	fgets(item->sobrenome, 50, stdin);
	__fpurge(stdin);

	printf("\t\tDigite sua Idade: ");
	scanf("%d", &item->idade);
	__fpurge(stdin);

	printf("\t\tDigite o dia do seu Nascimento: ");
	scanf("%d", &item->data.dia);
	__fpurge(stdin);

	printf("\t\tDigite o mes do seu Nascimento: ");	
	scanf("%d", &item->data.mes);
	__fpurge(stdin);

	printf("\t\tDigite o ano do seu Nascimento: ");
	scanf("%d", &item->data.ano);
	__fpurge(stdin);

	printf("\t\tDigite o seu Sexo: ");
	fgets(item->sexo, 20, stdin);
	__fpurge(stdin);

	printf("\t\tDigite a Identidade: ");
	fgets(item->identidade, 50, stdin);
	__fpurge(stdin);
}