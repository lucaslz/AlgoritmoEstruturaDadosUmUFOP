/* 
 * File:   main.c
 * Author: nobreack
 *
 * Created on 30 de Novembro de 2015, 15:18
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * calculo MDC
 */
int MDC (int n, int m) {
    
    if(m <= n && n % m == 0) {
        return m;
    }else if ( n < m) {
        return MDC(m,n);
    }else {
        return MDC(m,n%m);
    }
}

int main(int argc, char** argv) {

    int retorno;
    
    retorno = MDC(10, 5);
    
    printf("Retorno: %i", retorno);
    return (EXIT_SUCCESS);
}