#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int converterCadeiaNumerais(char *cadeia) {

	int i, qtde, num = 0;
	
	qtde = strlen(cadeia);

	for(i = 0; i < qtde; i++) {

		*(cadeia + i);

		// if((cadeia == '\n') && (cadeia == '\0')) {

			for(i = 0; i < qtde; i++) {
				
				if(i == 1) {
					num = *cadeia;
				}
				if(i+2){
					num = *cadeia * 10;	
				}
				if(i+3){
					num = *cadeia * 100;	
				}
				if(i+4){
					num = *cadeia * 1000;	
				}
				*(cadeia - i);
				
			}
		// }
	}
	return num;
}

int main(int argc, char** argv) {

	int num = converterCadeiaNumerais("1234");
	printf("Numero: %i\n", num);
}