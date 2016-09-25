/* 
 * File:   main.c
 * Author: informatica19
 *
 * Created on 20 de Novembro de 2015, 07:38
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int StrLen(char *string, int i) {
    
    if(*string){
        string++;
        i++;
        StrLen(string, i);
    }else{
        return i;
    }
}


int main(int argc, char** argv) {
    
    char nome[10] = "Leonardo";
    int valor = 0;
    
    valor = StrLen(nome, valor);
    
    printf("Numero de caracteres: %i", valor);

    return (EXIT_SUCCESS);
}