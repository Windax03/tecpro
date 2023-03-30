// ------------------------------------------------------------------------------
// File:   programaSuma.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

#include "programaSuma.h"
#include "add.h"
#include "read.h"
#include "write.h"

ProgramaSuma::ProgramaSuma()
{
    instruccion[0] = new Read;
    instruccion[1] = new Read;
    instruccion[2] = new Add;
    instruccion[3] = new Write;
};

void ProgramaSuma::ejecutarFinal(stack<int> &pila, int &contador)
{
    cout << "Programa:" << endl;
    for (int i = 0; i < n_operaciones; i++)
    {
        instruccion[i]->ejecutar(pila, contador);
    }
    cout << endl;
}

void ProgramaSuma::listarFinal()
{
    cout << "Ejecución:" << endl;
    for (int i = 0; i < n_operaciones; i++)
    {
        cout << i << " ";
        instruccion[i]->listar();
    }
    cout << endl;
}