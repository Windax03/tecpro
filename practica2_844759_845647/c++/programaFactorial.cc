// ------------------------------------------------------------------------------
// File:   programaCuenta.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

#include "programaFactorial.h"
#include "add.h"
#include "read.h"
#include "write.h"
#include "dup.h"
#include "jumpif.h"
#include "push.h"
#include "mul.h"
#include "swap.h"
#include "over.h"

ProgramaFactorial::ProgramaFactorial()
{
    instruccion[0] = new Push(1);
    instruccion[1] = new Read;
    instruccion[2] = new Swap;
    instruccion[3] = new Over;
    instruccion[4] = new Multi;
    instruccion[5] = new Swap;
    instruccion[6] = new Push(-1);
    instruccion[7] = new Add;
    instruccion[8] = new Dup;
    instruccion[9] = new Push(-2);
    instruccion[10] = new Add;
    instruccion[11] = new Jumpif(2);
    instruccion[12] = new Swap;
    instruccion[13] = new Write;
};

void ProgramaFactorial::ejecutarFinal(stack<int> &pila, int &contador)
{
    cout << "Programa:" << endl;
    while (contador < n_operaciones)
    {
        instruccion[contador]->ejecutar(pila, contador);
    }
    cout << endl;
}

void ProgramaFactorial::listarFinal()
{
    cout << "Ejecución:" << endl;
    for (int i = 0; i < n_operaciones; i++)
    {
        cout << i << " ";
        instruccion[i]->listar();
    }
    cout << endl;
}