/* 
 * File:   cadastroUsuarioBibliotecaFuncoes.h
 * Author: nobreack
 *
 * Created on 5 de Novembro de 2015, 21:37
 */

#ifndef CADASTROUSUARIOBIBLIOTECAFUNCOES_H
#define	CADASTROUSUARIOBIBLIOTECAFUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* CADASTROUSUARIOBIBLIOTECAFUNCOES_H */
    
    typedef struct dataNascimento {

        int Dia;
        int Mes;
        int Ano;

    }TDataNascimento;

    typedef struct endereco {

        char NomeRua[100];
        int  NumRua;
        char NomeBairro[100];
        char PontoReferencia[100];

    }TEndereco;

    typedef struct usuario{

        char Nome[100];
        char SoNome[100];
        int  idade;
        char CPF[11];
        int matricula;
        int limite;
        TEndereco endereco;
        TDataNascimento DataNascimento;

    }TUsuario;

    typedef struct modoloUsuario {

        int INDICE;
        TUsuario usuario[100];

    }TModoloUsuario;

    
    void IniciarUsuario(TModoloUsuario *m);
    
    void leituraDadosUsuario(TUsuario *usua);
    
    void leituraNomeUsuario(char *nome[100]);
    
    void imprimeUsuario(TModoloUsuario mod, int INDICE, char op);
    
    void ImprimirU(TModoloUsuario mod);
    
    void cadastrarUsuario(TModoloUsuario *mod, TUsuario usua);
    
    int pesquisarUsuario(TModoloUsuario mod, char nome[100]);
    
    void alterarUsuario(TModoloUsuario *mod, TUsuario usua, int INDICE);
    
    void excluirUsuario(TModoloUsuario *mod, int INDICE);
    
    void menuCadastroUsuario();

