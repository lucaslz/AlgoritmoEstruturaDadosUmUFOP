#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expoente(int num, int expo) {

	if((expo > 0) && (expo != 1)) {
		return num * expoente(num, expo - 1);
	}else {
		return num;
	}
}

int main(int argc, char** argv) {
	int resultado = expoente(2,3);
	printf("Resultado: %i\n", resultado);
}
