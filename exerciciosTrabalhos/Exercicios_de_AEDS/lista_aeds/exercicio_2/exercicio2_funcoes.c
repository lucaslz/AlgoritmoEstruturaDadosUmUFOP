/**
 * Questão 2
 */
//Função para fazer a leitura das informações
void Leitura_Informacao(TProduto *produto) {

	system("clear");
	printf("\n#########################################################\n");
	printf("#\t\tDados do Produto\t\t\t#");
	printf("\n#########################################################\n");

	printf("\n\tDescrição do produto: ");
	fgets(produto->descricao_produto, 100, stdin);
	
	printf("\n\tQuantidade: ");
	scanf("%i", &produto->quantidade);

	printf("\n\tPreço Unitário: ");
	scanf("%f", &produto->preco_unitario);
}

//Função para inicializar o vetor
void Inicializar_Vetor(TModuloLoja *loja) {

	//Inicializar o vetor
	loja->INDICE = 0;
}

int Verifica_Tamanho(TModuloLoja loja) {
	if(loja.INDICE <= 5 && loja.INDICE >= 0) {
		return 1;
	}else {
		return 0;
	}
}

//Função para cadastrar um novo produto no estoque
void Cadastrar_Produto(TModuloLoja *loja, TProduto *produto) {

	if(Verifica_Tamanho(*loja)) {

		//Chamando função para leitura dos dados
		Leitura_Informacao(produto);

		//Cadastrando infomações no vetor
		loja->produto[loja->INDICE] = *produto;
		
		//O INDICE também será o código do produto
		loja->produto[loja->INDICE].codigo_produto = loja->INDICE;

		//Incrementando o indice.
		loja->INDICE++;
	}else {
		printf("\n\tNão é possivel cadastrar mais produtos.");
	}
}

//Funçao que calcula a quantidade de produtos em estoque
int Quantidade_Produto_Estoque(TModuloLoja loja) {

	if(Verifica_Tamanho(loja)) {

		//Variáveis para ajudar a fazer o calculo.
		int i=0, Qtde=0;
		
		//Percorrendo todo o vetor e calculando a quantidade de produtos em estoque
		for(i; i < loja.INDICE; i++){

			//Calculando a quantidade
			Qtde = Qtde + loja.produto[i].quantidade;
		}

		//Quantidade a ser retornada
		return Qtde;
	}else {

		printf("\n\tNão é possivel calcular a quantidade de produtos em estoque.");
		//Retorna zero se não ouver produtos em esque, ou algum outro erro
		return 0;
	}
}

//Função para imprimir os dados de um produto
void Imprimir_Dados_Produto(int id, TModuloLoja loja) {

	system("clear");
	printf("\n#########################################################\n");
	printf("#\t\tImprimindo Dados\t\t\t#");
	printf("\n#########################################################\n");

	printf("\tDescrição do produto: %s", loja.produto[id].descricao_produto);
	printf("\n\tCódigo do produto: %i", loja.produto[id].codigo_produto);
	printf("\n\n\tQuantidade: %i", loja.produto[id].quantidade);
	printf("\n\n\tPreço Unitário: %f\n", loja.produto[id].preco_unitario);
	getchar();
}

//Função para ler a descrição do produto
void Ler_Descricao_Produto(char *descricao) {
	
	system("clear");
	printf("\n#########################################################\n");
	printf("#\t\t Procurando Produto \t\t\t#");
	printf("\n#########################################################\n");
	printf("\n\tDigite a Descrição do Produto: ");
	fgets(descricao, 100, stdin);	
}

//Função que pesquisa se um produto esta cadastrado no estoque ou não
int Pesquisar_Produto_Estoque(TModuloLoja loja) {

	int i;

	char descricao[100];

	//Pedindo o usuário para digitar a descrição do produto
	Ler_Descricao_Produto(descricao);

	//Percorrendo vetor e procurando o produto
	for(i = 0; i < loja.INDICE; i++) {

		//Verificando se o produto que o usuário digitou existe
		if(strcmp(descricao, loja.produto[i].descricao_produto) == 0){

			//So produto que o usuário digitou existir retornará o INDICE
			return i;
		}
	}
	//Caso não encontrar retorna um numero maior que o do vetor que cadastra os produtos
	//Ou seja um numero inválido
	return 6;
}

//Função para ordenar os produtos do estoque em ordem decrecente de acordo com a quantidade
void Ordenar_Produtos_Estoque_Decrescente(TModuloLoja *loja, TProduto *produto, int e_excluido) {

	//Verificando se o INDICE está vazio	
	if(Verifica_Tamanho(*loja) && loja->INDICE >= 2) {
		
		int i, Qtde_Auxiliar;
		TProduto produto_aux;

		//Pecorrendo vetor
		for(i = 0; i < loja->INDICE; i++){

			//Verificando se o produto atual é maior que o proximo
			if(loja->produto[i].quantidade > loja->produto[i+1].quantidade) {

				//Guardando o produto atual dentro de uma tipo de dado auxiliar
				produto_aux = loja->produto[i];

				//Guardando o proximo produto em um tipo de dado auxiliar
				*produto = loja->produto[i+1];

				//Realizando a troca
				loja->produto[i] = *produto;
				loja->produto[i+1] = produto_aux;
			}
		}
		//Verificando se quem chamaou essa função foi a função de Excluir
		if(e_excluido == 1) {
			system("clear");
			printf("\n\tProdutos Ordenados com sucesso.");
			getchar();
		}	
	}
}

//Função que exclui um produto do vetor e reordena o mesmo
void Excluir_Produto_Reordenar_Estoque(TModuloLoja *loja, TProduto *produto) {
	
	//Verificando se o INDICE está vazio	
	if(Verifica_Tamanho(*loja)) {

		//Setando um tipo de dado NULO
		TProduto produtoNulo;

		int codigo_produto, i;

		//Chamando função de pesquiar para retornar o código do prodtuo
		codigo_produto = Pesquisar_Produto_Estoque(*loja);
		
		//Escluindo a descrição do produto, assim não será possivel acha-lo mais
		loja->produto[codigo_produto] = produtoNulo;

		//Jogando produto para ultima posição
		for(i = 0; i <= loja->INDICE; i++) {

			//Verificando se o proximo INDICE é maior que o INDICE de controle
			if((i+1) > loja->INDICE) {

				//Colocando produto excluido na ultima posição
				//Logo essa posição será sobreescrevida
				loja->produto[i+1] = loja->produto[codigo_produto];
			}
		}
		//Ordenando o vetor de acordo com o tamanho
		Ordenar_Produtos_Estoque_Decrescente(loja, produto, 1);

		system("clear");
		printf("\n\tProduto Excluido com sucesso.");
		getchar();		
	}
}


//Menu do sistema
void Menu(TModuloLoja *loja, TProduto *produto) {

	//variáveis de controle do menu
	int op, codigo_produto;

	do{

		system("clear");
		printf("\n#########################################################\n");
		printf("#\t\t Imprimindo Dados \t\t\t#");
		printf("\n#########################################################\n");
		printf("\n\t\t[1] Cadastrar");
		printf("\n\t\t[2] Pesquisar");
		printf("\n\t\t[3] Ordenar Produtos em Estoque");
		printf("\n\t\t[4] Excluir Produto");
		printf("\n\t\t[0] Sair");
		printf("\n\n\t\tDigite a opção desejada: ");
		scanf("%d", &op);
		getchar();

		switch(op){

			case 1: {
				Cadastrar_Produto(loja, produto);
				break;
			}
			case 2: {
				codigo_produto = Pesquisar_Produto_Estoque(*loja);
				if(codigo_produto < 6) {
					Imprimir_Dados_Produto(codigo_produto, *loja);
				}else {
					system("clear");
					printf("\n\tProduto não Encontrado.");
					getchar();
					system("clear");					
				}	
				break;							
			}
			case 3: {
				Ordenar_Produtos_Estoque_Decrescente(loja, produto, 0);
				break;			
			}
			case 4: {
				Excluir_Produto_Reordenar_Estoque(loja, produto);
				break;
			}			
			case 0: {
				system("clear");
				printf("\n\tObrigado por usar nosso Software!!!");
				getchar();
				system("clear");
				break;
			}
			default: {
				system("clear");
				printf("\n\tOpção Invalida, Aperte enter e digite novamente.");
				getchar();
				break;
			}
		}
	}while(op != 0);
}