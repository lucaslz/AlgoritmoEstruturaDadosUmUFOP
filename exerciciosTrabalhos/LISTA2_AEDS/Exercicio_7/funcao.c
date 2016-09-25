void copia_valores(struct tpilha **topo , struct tpilha **topo2, int *status)
{
    struct tpilha *tmp; /* Pilha temporaria */
    struct tpilha *ptr; /* Ponteiro que percorrera a pilha A */
    struct tpilha *ptr2; /* Ponteiro que percorrera a pilha B */

    cria_pilha(&tmp);

    ptr = *topo;
    ptr2 = *topo2;

    if (*topo == NULL)
    {
            *status = 1;
    }
    else
    {
        if ( *topo2 == NULL)
        {
            tmp = malloc( sizeof(struct tpilha) );
            tmp->dados = ptr->dados;
            tmp->proximo = NULL;

            *topo2 = tmp;
            ptr = ptr->proximo;
        }

        /* Copia para pilha temporaria */
        while(ptr != NULL)
        {
            tmp = malloc( sizeof(struct tpilha) );
            tmp->dados = ptr->dados;

            tmp->proximo = *topo2;
            *topo2 = tmp;

            ptr = ptr->proximo;

        }

        printf("DEBUG: Mostra pilha intermediaria:\n");
        mostra_pilha(*topo2, 'C');

        ptr = NULL;
        ptr2 = NULL;
        /* Copia para a pilha B */
        while(*topo2 != NULL)
        {
            if (ptr == NULL)
            {
                ptr = *topo2; /* Copia primeiro valor do topo2 para ptr */
                *topo2 = (*topo2)->proximo; /* Desloca topo2 em 1 */
                ptr->proximo = NULL; /* Define NULL, pois se tornara o elemento mais recente da pilha */
            }
            else
            {
                ptr2 = *topo2;
                *topo2 = (*topo2)->proximo;
                ptr2->proximo = ptr;
                ptr = ptr2;
            }
        }

        *topo2 = ptr;

    }

}