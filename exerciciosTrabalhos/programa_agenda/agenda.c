#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"
#include "agendaFuncoes.c"

int main(int argc, char** argv) {

	TAgenda* agenda;
	TData data;
	TEvento evento;
	int retorno, op;

	agenda = iniciarAgenda();
	retorno = verificaAgendaVazia(agenda);

	do{
		system("clear");
		printf("\t1 - Inserir Evento\n");
		printf("\t2 - Remover Evento\n");
		printf("\t3 - Remover Data\n");
		printf("\t4 - Imprimir Eventos de uma Data\n");
		printf("\t0 - Sair do Programa\n\n\n");

		printf("\tDigite o numero da opção desejada: ");
		scanf("%i", &op);

		switch(op) {

			case 1: {
				inserirDataOrdenado(agenda, data);
				inserirEvento(agenda, evento, data);
				break;
			}
			case 2: {
				removerEvento(agenda, evento);
				break;
			}
			case 3: {
				removerData(agenda, data);
				break;
			}
			case 4: {
				imprimirEventosData(agenda, data);
				break;
			}
			default: {
				printf("Opção errada, Digire novamente.\n");
				getchar();
			}
		}

	}while(op != 0);
}
