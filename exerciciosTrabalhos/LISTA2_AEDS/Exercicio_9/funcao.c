void deslocafila(Tfila *fila)
{
    if(vazia(fila)){
        printf("Fila vazia!\n\n");
        return ;
    }

    Tfila *tmp;
    tmp = fila->prox;
    while( tmp != NULL){
        if(tmp->valor<0){
            tmp->valor = "";
        }
        tmp = tmp->prox;
    }
    printf("\n\n");
}