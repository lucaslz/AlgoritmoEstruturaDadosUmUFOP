/* 
 * File:   main.c
 * Author: Lucaas Lima
 *
 * Created on 20 de Outubro de 2015, 13:37
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastroBiblioteca.h"
#include "cadastroUsuario.h"
#include "menu.h"
#include "emprestimoFuncoes.h"

int main(int argc, char** argv) {             
    
    int op;
    TModuloLivro mod;
    TModoloUsuario modu;
    TModoloEmprestimo modul;
    
    Iniciar(&mod);
    IniciarUsuario(&modu);
    iniciarEmprestimo(&modul);
    menu();
    return (EXIT_SUCCESS);
}