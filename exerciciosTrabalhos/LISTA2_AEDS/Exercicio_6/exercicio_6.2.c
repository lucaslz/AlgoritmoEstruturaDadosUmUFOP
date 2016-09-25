#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio_6.1.h"

Tpilha* pilha_cria() {

	Tpilha* p = (Tpilha*)malloc(sizeof(Tpilha));

	if(p==NULL) {
		exit(1);
	}

	p->prim = NULL;

	return p;
}

void pilha_push(Tpilha* p, int v) {

	Tno* n = (Tno*)malloc(sizeof(Tno*));
	n->valor = v;
	n->prox = p->prim;
	p->prim = n;
}

int pilha_pop(Tpilha* p) {

	Tno* t;
	int v;

	t = p->prim;
	v = t->valor;

	p->prim = t->prox;

	free(t);

	return v;
}

void inserir_ordenado(Tpilha *p, int v){

	if(p->prim->valor < v) {
		pilha_push(p, v);
	}
}