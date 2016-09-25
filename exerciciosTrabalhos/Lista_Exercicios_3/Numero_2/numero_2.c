#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

	int v[8] = {1,2,3,4,5,6,7,8};
	int cont = 0, conte = 0, i = 0, j = 0;
	int v_impar[4], v_par[8], v_aux[8], aux;

	while(cont < 8) {

		if((v[cont]%2) != 0) {
			
			v_impar[i] = v[cont];
			i++;
		}
		cont++;
	}

	for(i= 0; i < 4; i++) {
		
		for(j= 0; j < 4; j++) {
			
			if(v_impar[i] < v_impar[j]) {

				aux = v_impar[i];
				v_impar[i] = v_impar[j];
				v_impar[j] = aux;

			}
		}		
	}

	for(i = 0; i < 4; i++) {
		v_aux[i] = v_impar[i];
	}	
	
	j = 0;
	while(conte < 8) {
		
		if((v[conte]%2) == 0) {
			v_par[j] = v[conte];
			j++;
		}
		conte++;
	}

	for(i= 0; i < 4; i++) {
		
		for(j= 0; j < 4; j++) {
			
			if(v_par[i] > v_par[j]) {

				aux = v_par[i];
				v_par[i] = v_par[j];
				v_par[j] = aux;

			}
		}		
	}

	j=4;
	for(i = 0; i < 4; i++) {

		v_aux[j] = v_par[i];
		j++;
	}

	for (i = 0; i < 8; i++){
		
		printf("%i, ", v_aux[i]);
	}

	printf("\n");

}