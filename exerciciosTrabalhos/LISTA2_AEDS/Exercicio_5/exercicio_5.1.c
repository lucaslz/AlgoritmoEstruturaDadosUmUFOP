#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_5.1.h"

int main(int argc, char** argv) {
	
	Tno* lista;
	
	//Definindo os dados da lista
	TipoItem item;

	//Defininco a variável de controle do sistema
	int op, i;

	//Iniciando a lista
	lista = inicia_lista();

	do {

		system("clear");

		printf("\t\t################ Recolhendo os dados ################\n\n");
		printf("\t\t1 - Inserir na lista \n");
		printf("\t\t3 - Inverter Lista\n");				
		printf("\t\t0 - Sair da Lista\n\n");

		printf("\t\tDigite a opcao desejada: ");
		scanf("%i", &op);
		__fpurge(stdin);

		switch(op) {

			case 1: {

				//Inserindo o nome ordenadamente
				inserir(lista, item);
				break;
			}
			case 2: {

				//Verificar se as listas são igual
				inverter_lista(lista);
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