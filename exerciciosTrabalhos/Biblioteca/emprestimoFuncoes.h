/* 
 * File:   emprestimoFuncoes.h
 * Author: nobreack
 *
 * Created on 8 de Novembro de 2015, 00:16
 */

#ifndef EMPRESTIMOFUNCOES_H
#define	EMPRESTIMOFUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastroUsuario.h"
#include "cadastroBiblioteca.h"
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* EMPRESTIMOFUNCOES_H */

typedef struct dataEntrega {
  int dia;
  int mes;
  int ano;
  
}TDataEntrega;

typedef struct dataDevolucao {
  int dia;
  int mes;
  int ano;
  
}TDataDevolucao;

typedef struct dataEmprestimo {
  int dia;
  int mes;
  int ano;
  
}TDataEmprestimo;

typedef struct emprestimo {
    int ISBN;
    int matricula;
    TDataEntrega dataEntrega;
    TDataDevolucao dataDevolucao;
    TDataEmprestimo dataEmprestimo;
    int multaEmprestimo;
    int status;
    
}TEmprestimo;

typedef struct modoloEmprestimo {
    int INDICE;
    TEmprestimo emprestimo[100];
    
}TModoloEmprestimo;

void leituraDadosEmprestimo(TEmprestimo *emprestimo);
void leituraMatriculaEmprestimo(int *matricula);
void imprimirEmprestimo(TModoloEmprestimo modoloE, int indice);
void cadastroEmprestimo(TUsuario *usuario, TLivro *livro, TModoloEmprestimo *modoloE, TEmprestimo emprestimo, int resultado);
int pesquisaCadastroEmprestimo(TModoloUsuario modUs, TModuloLivro modLi,TModoloEmprestimo modoloE, int caso);
int pesquisaEmprestimo(TUsuario usuario, TModoloEmprestimo modoloE);
void devolveEmprestimo(TLivro *livro, TUsuario *usuario, TModoloEmprestimo *modoloE, int matricula);
void pagarMultaEmprestimo(TModoloEmprestimo *modoloE, TUsuario usuario, int mat);
void menuCadastroEmprestimo();