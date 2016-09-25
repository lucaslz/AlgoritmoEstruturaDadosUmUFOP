typedef struct no
{
	int valor;
	struct no *prox;
}Tno;

typedef struct pilha
{
	Tno* prim;
}Tpilha;

Tpilha* pilha_cria();
void pilha_push(Tpilha* p, int v);
int pilha_pop(Tpilha* p);