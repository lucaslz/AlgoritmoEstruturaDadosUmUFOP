#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MDC(int n, int m) {

	if((m <= n) && (n % m) == 0)  {
		return m;
	}else if( n < m) {
		return MDC(m, n);
	}else {
		return MDC(m, n % m);
	}
}

int main(int argc, char** argv) {
	int resultado = MDC(12,20);
	printf("Resultado: %i\n", resultado);
}
