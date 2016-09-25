/* 
 * File:   main.c
 * Author: Lucas Teotõnio Lima
 *
 * Created on 17 de Dezembro de 2015, 10:07
 * 
 * Title: Programa que guarda dados de um carro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista_Estruturas_Prototipos.h"

int main(int argc, char** argv) {

    int opcao;
    int igual;
    char chassi[100];
    Lista lista, lista2;
    TipoItem item;
    Celula * retPesquisa;

    FLVazia(&lista);
    FLVazia(&lista2);

    while (opcao != 0) {
        system("clear");
        printf("\n----------------------------Menu----------------------------");
        printf("\n1 - Incluir");
        printf("\n2 - Pesquisar");
        printf("\n3 - Imprimir");
        printf("\n4 - Excluir");
        printf("\n5 - Copiar uma Lista para Outra e Verificar se é igual");
        printf("\n------------------------------------------------------------");
        printf("\n\nDigite a Opção Desejada: ");
        __fpurge(stdin);
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
            {
                LeituraDados(&item);
                Inserir(&lista, item);
                break;
            }
            case 2:
            {
                LeituraChassi(&item);
                
                retPesquisa = Pesquisar(lista, item);
                
                if (&retPesquisa != NULL) {
                    ImprimirDados(retPesquisa);
                } else {
                    system("clear");
                    printf("\nNão Existe carros com esse Chassi !");
                    printf("\nAperte Enter para voltar ao menu.");
                    __fpurge(stdin);
                    getchar();
                }
                break;
            }
            case 3:
            {
                ImprimirDadosCarros(lista);
                break;
            }
            case 4:
            {
                LeituraChassi(&item);
                retPesquisa = Pesquisar(lista, item);
                Excluir(&lista, retPesquisa, &item);
                break;
            }
            case 5:
            {
                CopiarLista(&lista2, &lista);
                igual = VerificaListaIguais(lista2, lista);

                if (igual == 1) {
                    printf("As listas são Iguais !!!");
                } else {
                    printf("As listas são diferentes !!!");
                }
                break;
            }
            default:
            {

                break;
            }
        }
    }
    TipoItem aux;
    return (EXIT_SUCCESS);
}

