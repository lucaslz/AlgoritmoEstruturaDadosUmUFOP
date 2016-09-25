#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_3.1.h"

Tno* inicia_lista() {

	Tno* lista = (Tno *) malloc(sizeof(Tno));

	if(!lista) {
		printf("Sem memória disponível.\n");
		exit(1);
	}

	lista->prox = NULL;

	return lista;
}

void insere_inicio_ordenado(Tno *lista, TipoItem item) {
	
	//Chamando a funcao para ler os dados
	leitura(&item);
	
	//Alocando memória para a celula da lista
	Tno* nova = (Tno*)malloc(sizeof(Tno));

	//Alocando memoria para o anterior
	Tno* a = NULL;

	//Alocando memória para o proximo, que vai percorer a lista
	Tno* p;

	//Pegando tamanho da string
	int tamanhoString = strlen(item.nome);

	//Insere no inicio da lista caso o primeiro prox for igual a NULL
	for(p = lista->prox; p != NULL; p = p->prox) {

		//Comparando as strigs para ver se são iguais
		if(strlen(p->item.nome) == tamanhoString) {
			
			//As strings não iguais então é so inserir depois da outra
			nova->item = item;	
			nova->prox = lista->prox;	
			lista->prox = nova;
		}else if(strlen(p->item.nome) < tamanhoString) {

			//Pegando o ponteiro atual e o proximo, pois é preciso inserir entre os dois
			a = p;
			p = p->prox;

			//Inserindo no meio da lista
			nova->item = item;
			nova->prox = a->prox;
			a->prox = nova; 
		}
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

void intercalar_lista(Tno* lista, Tno* lista2) {

	Tno *lista3, *aux, *aux2;

	lista3 = (Tno*)malloc(sizeof(Tno));

	for(aux = lista; aux != NULL; aux = aux->prox) {

		lista3->item = lista->item;

		for(aux2 = lista2; aux2 != NULL; aux2 = aux2->prox){

			lista3->prox = lista2->prox;
			lista2->prox = lista3;
		}

		lista3->item = lista2->prox->item;
		lista3->prox = lista2->prox->prox;
		lista2->prox = lista3;
	}
}