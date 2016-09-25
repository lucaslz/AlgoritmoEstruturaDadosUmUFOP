#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_1.h"
/**
 * Inicializando a lista de nomes
 * @param  lista 
 * @return Tno
 */
Tno* iniciarLista() {

	Tno* lista = (Tno*)malloc(sizeof(Tno));

	lista->prox = NULL;

	return lista;
}

/**
 * Função para o usuario digitar o nome
 * @param lista
 */
void digitarNome(TDado* dado) {

	system("clear");
	printf("\t\t################ Recolhendo os dados ################\n\n");

	printf("\t\tDigite seu nome: ");
	fgets(dado->nome, 50, stdin);
	__fpurge(stdin);

	printf("\t\tDigite seu Sobrenome: ");
	fgets(dado->sobrenome, 50, stdin);
	__fpurge(stdin);

	printf("\t\tDigite sua Idade: ");
	scanf("%d", &dado->idade);
	__fpurge(stdin);

	printf("\t\tDigite o dia do seu Nascimento: ");
	scanf("%d", &dado->data->dia);
	__fpurge(stdin);

	printf("\t\tDigite o mes do seu Nascimento: ");	
	scanf("%d", &dado->data->mes);
	__fpurge(stdin);

	printf("\t\tDigite o ano do seu Nascimento: ");
	scanf("%d", &dado->data->ano);
	__fpurge(stdin);

	printf("\t\tDigite o seu Sexo: ");
	fgets(dado->sexo, 20, stdin);
	__fpurge(stdin);

	printf("\t\tDigite a Identidade: ");
	fgets(dado->identidade, 50, stdin);
	__fpurge(stdin);
}

/**
 * Função que ordena os nomes e os insere
 * @param lista [description]printf("Digite o dia do seu Nascimento: ");
 */
void ordernarNome(Tno *lista, TDado *dado) {
	
	//Chamando a funcao para ler os dados
	digitarNome(dado);
	
	//Alocando memória para a celula da lista
	Tno* nova = (Tno*)malloc(sizeof(Tno));

	//Alocando memoria para o anterior
	Tno* a = NULL;

	//Alocando memória para o proximo, que vai percorer a lista
	Tno* p;

	//Pegando tamanho da string
	int tamanhoString = strlen(dado->nome);

	//Insere no inicio da lista caso o primeiro prox for igual a NULL
	for(p = lista->prox; p != NULL; p = p->prox) {

		//Comparando as strigs para ver se são iguais
		if(strlen(p->dados->nome) == tamanhoString) {
			
			//As strings não iguais então é so inserir depois da outra
			nova->dados = dado;	
			nova->prox = lista->prox;	
			lista->prox = nova;
		}else if(strlen(p->dados->nome) < tamanhoString) {

			//Pegando o ponteiro atual e o proximo, pois é preciso inserir entre os dois
			a = p;
			p = p->prox;

			//Inserindo no meio da lista
			nova->dados = dado;
			nova->prox = a->prox;
			a->prox = nova; 
		}
	}
}