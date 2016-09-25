#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_4.1.h"

Tno* inicia_lista() {

	Tno* lista = (Tno *) malloc(sizeof(Tno));

	if(!lista) {
		printf("Sem memória disponível.\n");
		exit(1);
	}

	lista->prox = NULL;

	return lista;
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

void verifica_igual(Tno* lista1, Tno* lista2) {

	Tno *aux, *aux2;

	aux = lista1->prox;
	aux2 = lista2->prox;

	//Percorrendo a lista 1
	while(aux != NULL) {
		//Percorrendo a lista 2 e comparando
		while(aux2 != NULL) {

			//Verificando se cada componete da lista e igual ao da outra
			if(strcmp(aux->item.nome, aux2->item.nome) != 0) {

				printf("Não são iguais.\n");
				exit(1);
			}
		}

		aux = aux->prox;
		aux2 = aux2->prox;
	}
}