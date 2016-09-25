//Estrutura contendo a data de nascimento
typedef struct data
{
	int dia;
	int mes;
	int ano;
}TData;

//Estrutura com os dados da pessoa 
typedef struct item
{
	char nome[50];
	char sobrenome[50];
	int idade;
	char sexo[20];
	char identidade[50];
	TData data;	
}TipoItem;

//Estrutura de controle
typedef struct no {
	TipoItem item;
	struct no* prox;
}Tno;

//Inicia Lista
Tno* inicia_lista();
void insere_inicio_ordenado(Tno *lista, TipoItem item);
void intercalar_lista(Tno* lista, Tno* lista2);
void leitura(TipoItem* item);