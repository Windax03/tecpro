//------------------------------------------------------------------------------
// File:   main.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//         Programa principal
//------------------------------------------------------------------------------

#include "programaSuma.h"
#include "programaCuenta.h"
#include "programaFactorial.h"

using namespace std;

int main()
{
    ProgramaSuma sum;
    ProgramaCuenta cont;
    ProgramaFactorial fac;

    stack<int> pila;

    int contador = 0;

    sum.listarFinal();
    sum.ejecutarFinal(pila, contador);

    contador = 0;
    cont.listarFinal();
    cont.ejecutarFinal(pila, contador);

    contador = 0;
    fac.listarFinal();
    fac.ejecutarFinal(pila, contador);

    return 0;
}