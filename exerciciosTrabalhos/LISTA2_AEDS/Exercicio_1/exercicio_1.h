/**
 * Estrutura contendo a data de nascimento
 */
typedef struct dataNascimento
{
	int dia;
	int mes;
	int ano;
}TDataNascimento;

/**
 * Estrutura com os dados da pessoa 
 */

typedef struct dado
{
	char nome[50];
	char sobrenome[50];
	int idade;
	char sexo[20];
	char identidade[50];
	TDataNascimento* data;	
}TDado;

/**
 * Estrutura de controle
 */
typedef struct no {
	TDado* dados;
	struct no* prox;
}Tno;

/**
 * Inicializando a lista de nomes
 * @param  lista 
 * @return Tno
 */
Tno* iniciarLista();

/**
 * Função para o usuario digitar o nome
 * @param lista
 */
void digitarNome(TDado* dado);

/**
 * Função que ordena os nomes e os insere
 * @param lista [description]
 */
void ordernarNome(Tno* lista, TDado* dado);

/**
 * Funcao que pega o nome do usuário para pesquisa-lo na lista
 * @param dado
 */
void digitarNomePesquisar(TDado* dado);

/**
 * Pesquisando usuario na lista
 * @param lista
 * @param dado
 */
// int pesquisandoUsuario(Tno* lista, TDado* dado);