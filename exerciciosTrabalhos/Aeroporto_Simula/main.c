
/* 
 * File:   main.c
 * Author: Lucas
 *
 * Created on 13 de Janeiro de 2016, 18:32
 */

#include <structprototipo.h>
#include <funcoes.c>
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
//#include <windows.h>
#include <string.h>

//Função Main

int main(int argc, char *argv[]) {

    int aterrissagem, decolagem, cont_ate = 0, cont_dec = 0, cont_prog = 0, total_de_avioes, pista;
    Lista lista, lista2;
    tipoItem item;

    pistaVazia(lista, lista2);

    system("cls");
    printf("\n\t\t\t###############################");
    printf("\n\t\t\t# CONTROLE DE TRAFEGO AEREO #");
    printf("\n\t\t\t###############################");
    printf("\n\t\t\tDigite o numero de aviões de Aterrissagem: ");
    __fpurge(stdin);
    scanf("%d", &aterrissagem);
    printf("\n\t\t\tDigite o numero de aviões de Decolagem: ");
    __fpurge(stdin);
    scanf("%d", &decolagem);
    system("cls");

    total_de_avioes = aterrissagem + decolagem;

    while (total_de_avioes < cont_prog) {

        cont_prog++;

        if (aterrissagem > 0) {

            while (cont_ate < aterrissagem) {

                cont_ate++;

                cadastrarTipoItem(lista, &item);
                EnfileirarAviao(&lista, item);
            }

            if (decolagem > 0) {

                while (cont_dec < decolagem) {

                    cont_ate++;

                    cadastrarTipoItem(lista2, &item);
                    EnfileirarAviao(&lista2, item);

                }
            }

        }

        if (aterrissagem > 2 && cont_prog < 2) {

            contagemTempoAvioes();
            imprimePistaAterrisar(lista);

        } else if (decolagem == 2 && cont_prog > 2) {

            contagemTempoAvioes();
            imprimePistaDecolar(lista2);

        } else {

            contagemTempoAvioes();
            pista = verificaPistaPousoEmergencia(&lista, &lista2);

            if (strcmp(pista, "pista 3") == 0) {

                imprimePistaEmergencia(lista2);

            } else {

                imprimePistaEmergencia(lista);
            }
        }
    }
}