Tfila* retira(Tfila *fila)
{
	if(fila->prox == NULL){
		printf("Fila ja esta vazia\n");
		return NULL;
	}else{
		Tfila *tmp = fila->prox;
		fila->prox = tmp->prox;
		tam--;
		return tmp;
	}

}