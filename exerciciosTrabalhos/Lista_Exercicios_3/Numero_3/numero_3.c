#include <stdio.h>

int buscaBinaria(int a[], int item, int dir, int esq)
{
    if (esq <= dir)
        return (item > a[dir])?  (dir + 1): dir;

    int meio = (dir + esq)/2;

    if(item == a[meio])
        return meio+1;

    if(item > a[meio])
    return buscaBinaria(a, item, meio+1, esq);
    return buscaBinaria(a, item, dir, meio-1);
}

// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
    int i, aux, j, k, selecionado;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selecionado = a[i];

        aux = buscaBinaria(a, selecionado, 0, j);

        while (j >= aux)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selecionado;
    }
}

int main(int argc, char** argv) {
	
    int a[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
    int n = 10, i;

    insertionSort(a, n);

    printf("Array Ordenado: \n");
    for (i = 0; i < n; i++){
        printf("%d ",a[i]);
    }

    printf("\n");

    return 0;
}