int retorna_no (arvore r) {
   if (r == NULL) 
      return -1; // altura da árvore vazia
   else {
      int he = altura (r->esq);
      int hd = altura (r->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}