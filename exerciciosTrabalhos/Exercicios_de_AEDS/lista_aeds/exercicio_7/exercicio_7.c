#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int h(int n) {

	if(n  = 0) {
		return 0;
	}

	if(n > 4) {
		return n;
	}

	if(n <= 4) {
		return h(2+h(2*n));
	}
}

int main(int argc, char** argv) {
	int resultado = h(4);
	printf("Resultado: %i\n", resultado);
}
