int SomaElementosRecursive(Tno raiz)
{
   int soma;
   
   if (raiz != NULL){
		
		soma=SomaElementos(raiz.r)+SomaElementos(raiz.l)+raiz.item;
		return soma;
	}
	else{
		return 0;
	}
}