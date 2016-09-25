#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função STRLEN retorna o tamanho de uma string
int strLen(char *string) {

	//string que vai conter o total de caracters
	int total = 0;

	//Percorrendo o ponteiro para somar quanto caracters ele tem
	if((*string != '\n') && (*string != '\0')){
		
		return strLen(string);	
		string++;
		total++;

	}else {

		return total;
	}	
}

int main(int argc, char** argv) {

	int retorno = strLen("Lucas");

	printf("Retorno: %i", retorno);
}