#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_3.1.h"

int main(int argc, char** argv) {

	Tno* lista;
	Tno* lista2;

		//Definindo os dados da lista
	TipoItem item;

	//Defininco a variável de controle do sistema
	int op, i;

	//Iniciando a lista
	lista = inicia_lista();
	lista2 = inicia_lista();

	do {

		system("clear");

		printf("\t\t################ Recolhendo os dados ################\n\n");
		printf("\t\t1 - Inserir na lista 1\n");
		printf("\t\t2 - Inserir na lista 2\n");
		printf("\t\t3 - Intercarlar as listas\n");				
		printf("\t\t0 - Sair da Lista\n\n");

		printf("\t\tDigite a opcao desejada: ");
		scanf("%i", &op);
		__fpurge(stdin);

		switch(op) {

			case 1: {

				//Inserindo o nome ordenadamente
				insere_inicio_ordenado(lista, item);
				break;
			}
			case 2: {

				//Inserindo o nome ordenadamente
				insere_inicio_ordenado(lista2, item);
				break;
			}
			case 3: {

				//Inserindo o nome ordenadamente
				intercalar_lista(lista, lista2);
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