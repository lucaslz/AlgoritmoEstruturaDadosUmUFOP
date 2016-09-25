#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_1.h"

int main(int argc, char** argv) {

	//Definindo a lista
	Tno* lista;

	//Definindo os dados da lista
	TDado dado;

	//Defininco a variável de controle do sistema
	int op, i;

	//Iniciando a lista
	lista = iniciarLista();

	do {

		system("clear");

		printf("\t\t################ Recolhendo os dados ################\n\n");
		printf("\t\t1 - Inserir novo cadastro na Lista\n");
		printf("\t\t2 - Pesquisando usuario na Lista\n");
		printf("\t\t0 - Sair da Lista\n\n");

		printf("\t\tDigite a opcao desejada: ");
		scanf("%i", &op);
		__fpurge(stdin);

		switch(op) {

			case 1: {

				//Inserindo o nome ordenadamente
				ordernarNome(lista, &dado);
				break;
			}
			case 2: {

				//Pesquisando o usuario na lista
				// i = pesquisandoUsuario(lista, &dado);

				if(i == 1) {
					system("clear");	
					printf("\n\t\tDados encontrados.\n\n");
					getchar();
				}else {
					system("clear");	
					printf("\n\t\tDados não encontrados.\n\n");
					getchar();
				}

				break;
			}
			case 0: {

				system("clear");	
				printf("\n\t\tObrigado por usar nossa lista.\n\n");
				getchar();
				break;
			}
			default: {

				system("clear");
				printf("\n\t\tOpcao errada, digite novamente.\n\n");
				getchar();
				break;
			}
		}	
	}while(op != 0);
}