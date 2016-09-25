#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função para concatenar strings
void strCat(char *destino, char *origem) {

	//Percorrendo o ponteiro
	while((*destino != '\n') && (*destino != '\0')){
		
		destino++;
	}	
	
	//Setando o valor \0 no ponteiro
	*destino = '\0';
	
	//Enquanto o rigem for diferente de zero destino recebera origem
	while((*origem != '\0') && (*origem != '\0')) {
	
		*destino = *origem;
		destino++;
		origem++;
	}
}

//Função STRLEN retorna o tamanho de uma string
int strLen(char *string) {

	//string que vai conter o total de caracters
	int total = 0;

	//Percorrendo o ponteiro para somar quanto caracters ele tem
	while((*string != '\n') && (*string != '\0')){
		
		string++;
		total++;
	}
	return total;
}

//Função que compara uma string com outra
void strCmp(char *string1, char *string2) {
	
	//guarda o tamnho das strings
	int tamanho_1, tamanho_2, tamanho;

	//Verificando primeiramenteo tamanho das strings
	tamanho_1 = strLen(string1);
	tamanho_2 = strLen(string2);
	tamanho = 0;

	//Comparando o tamanho das strings se for diferetes elas não são iguais
	if(tamanho_1 != tamanho_2){

		printf("\n\t\tAs strings são Diferentes.");
		getchar();
	}else {

		while((*string1 != '\n') && (*string1 != '\0')){
			

			if(*string1 == *string2) {
				tamanho++;
			}
			string1++;
			string2++;
		}

		if(tamanho == tamanho_1){
			printf("\n\t\tAs strings são iguais.");
			getchar();
		}else{
			printf("\n\t\tAs strings são Diferentes.");
			getchar();
		}
	}
}

int main(int argc, char** argv) {

	//Declarando variáveis
	char p1[40], string[40];
	char p2[40];
	int i = 0, tamanho, decisao;


	do{
		system("clear");
		printf("\n\t1 - STRLEN \n\t2 - STRCAT \n\t3 - STRCMP\n\t0 - Sair\n\tDeseja usar qual função: ");
		scanf("%d", &decisao);
		getchar();

		system("clear");
		if(decisao != 0){
			//Digitando o primeiro nome
			printf("\tDigite uma palavra: ");
			fgets(p1, 40, stdin);
		}

		if(decisao != 1 && decisao != 0){
			//Digitando o segundo nome
			printf("\n\tDigite outra palavra: ");
			fgets(p2, 40, stdin);
		}	

		switch(decisao) {

			case 1: {
				system("clear");
				tamanho = strLen(p1);
				printf("\n\t\tO tamanho da string é: %d", tamanho);
				getchar();
				break;
			}
			case 2: {
				system("clear");
				strCat(p1, p2);
				printf("\n\t\tJuntando as string: %s", p1);
				getchar();
				break;
			}
			case 3:{
				system("clear");
				strCmp(p1, p2);
				getchar();				
			}
		}
	}while(decisao != 0);	
}