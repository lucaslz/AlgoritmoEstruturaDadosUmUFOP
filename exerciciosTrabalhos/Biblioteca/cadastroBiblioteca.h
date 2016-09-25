/* 
 * File:   estruturas_funcoes.h
 * Author: nobreack
 *
 * Created on 4 de Novembro de 2015, 20:32
 */

#ifndef ESTRUTURAS_FUNCOES_H
#define	ESTRUTURAS_FUNCOES_H
#include <stdio.h>
#include <stdlib.h>

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ESTRUTURAS_FUNCOES_H */


/*
 * A struct informacao puxará da struct dataPublicacao a data da publicacao do
 * livro.
 * 
 * Montando a struct data Publicacao.
 */

typedef struct data{
    /*
     *  Dia da Publicação do livro valor inteiro
     */
    
    int dia;
    
    /*
     * Mês da Publicação do livro valor inteiro
     */
    
    int mes;
    
    /*
     * Ano da publicação do livro valor inteiro
     */
    
    int ano;
    
}TData;


/*
 * Struct que contém os dados dos livros
 */

typedef struct Livro{
    /*
     * Código do livro tipo inteiro
     */
    
    int ISBN;
    
    /*
     * Título do livro máximo de 100 caracteres
     */
    
    char titulo[100];
    
    /*
     * Edição em que o livro está, edição é o mesmo que revisão tipo inteiro
     */
    
    int edicao;
    
    /*
     * Nome do autor do livro Máximo de 50 caracteres
     */
    
    char autor[100];
    
    /*
     * Nome da editora do Livro Máximo de 100 caracteres
     */
    
    char editora[100];
    
    /*
     * Volume em que o livro esta, uma continuação do livro, tipo inteiro
     */
    
    int volume;
    
    /*
     * Numero de Exemplares do livro, ou quantos livros tem tipo inteiro
     */
    
    int numExemplar;
    
    /*
     * Numero de livro disponiveis
     */
    
    int NumEmprestimos;
    
    /*
     * Struct do tipo data definida logo acima
     */
    
    TData DATA_DE_PUB;
    
}TLivro;

typedef struct Modolo_livro {
    
    int INDICE;
    TLivro livros[100];
    
}TModuloLivro;


void Iniciar (TModuloLivro *mod);

void LeituraDeDados (TLivro *L);

void Cadastrar(TLivro L, TModuloLivro *mod);

void LeituraISBN(int *ISBN);

void ImprimeLivro(TModuloLivro mod, int i, char op);

int Pesquisar(TLivro L, TModuloLivro *mod, int ISBN);

void Alterar(TModuloLivro *mod, TLivro L, int i);

void Excluir(TModuloLivro *mod, int i);

void Imprimir (TModuloLivro mod);

void Sair();

void menuBiblioteca();