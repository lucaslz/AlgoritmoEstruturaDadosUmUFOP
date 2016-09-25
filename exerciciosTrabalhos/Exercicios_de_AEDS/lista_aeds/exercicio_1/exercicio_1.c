/**
 * Questão 1
 */

//Estrutura com os dados do autmóvel
typedef struct automovel
{
	char marca_automovel[100];
	char modelo_automovel[100];
	char cor[50];
	int ano_fabricacao;
	float tipo_motor;
	/*
	* Esse dado não foi pedido no exercicio
	* Mas foi necessário para controlar o 
	* modulo de cadastro do carro
	*/
	int ID;
}TAutomovel;

//Estrutura de controle dos automóvel
typedef struct fabrica
{
	TAutomovel automovel[100];
	int INDICE;

}TModuloFabrica;