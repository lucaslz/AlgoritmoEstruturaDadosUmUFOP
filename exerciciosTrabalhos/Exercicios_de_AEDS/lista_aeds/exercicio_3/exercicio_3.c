#include <stdio.h>
#include <stdlib.h>
int main() {
	float *alpha, *beta, *gama, delta;
	beta = (float*) malloc(sizeof(float));
	*beta = 7.987;
	// delta = 3.14;
	// beta = &delta;
	*alpha = *beta;
	return 0;
}

//O ponteiro alpha não foi inicializado
//Ao receber delta beta deixa um célula de memória perdida
