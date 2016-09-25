#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicio2_structs.h"
#include "exercicio2_funcoes.c"

int main(int argc, char** argv) {
	
	TProduto produto;
	TModuloLoja loja;

	Inicializar_Vetor(&loja);
	Menu(&loja, &produto);
}