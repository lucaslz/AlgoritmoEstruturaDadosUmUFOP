typedef struct produto
{
	char descricao_produto[100];
	int codigo_produto;
	int quantidade;
	float preco_unitario;
}TProduto;

typedef struct loja
{
	TProduto produto[5];
	int INDICE;
}TModuloLoja;

//Função para fazer a leitura das informações
void Leitura_Informacao(TProduto *produto);

//Função para inicializar o vetor
void Inicializar_Vetor(TModuloLoja *loja);

//Função para cadastrar um novo produto no estoque
void Cadastrar_Produto(TModuloLoja *loja, TProduto *produto);

//Funçao que calcula a quantidade de produtos em estoque
int Quantidade_Produto_Estoque(TModuloLoja loja);

//Função para imprimir os dados de um produto
void Imprimir_Dados_Produto(int id, TModuloLoja loja);

//Função para ler a descrição do produto
void Ler_Descricao_Produto(char *descricao);

//Função que pesquisa se um produto esta cadastrado no estoque ou não
int Pesquisar_Produto_Estoque(TModuloLoja loja);

//Função para ordenar os produtos do estoque em ordem decrecente de acordo com a quantidade
void Ordenar_Produtos_Estoque_Decrescente(TModuloLoja *loja, TProduto *produto, int e_exluido);

//Função que exclui um produto do vetor e reordena o mesmo
void Excluir_Produto_Reordenar_Estoque(TModuloLoja *loja, TProduto *produto);

//Menu do sistema
void Menu(TModuloLoja *loja, TProduto *produto);