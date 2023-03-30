// ------------------------------------------------------------------------------
// File:   programaCuenta.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

#include "programaCuenta.h"
#include "add.h"
#include "read.h"
#include "write.h"
#include "dup.h"
#include "jumpif.h"
#include "push.h"

ProgramaCuenta::ProgramaCuenta()
{
    instruccion[0] = new Read;
    instruccion[1] = new Dup;
    instruccion[2] = new Write;
    instruccion[3] = new Push(-1);
    instruccion[4] = new Add;
    instruccion[5] = new Dup;
    instruccion[6] = new Jumpif(1);
};

void ProgramaCuenta::ejecutarFinal(stack<int> &pila, int &contador)
{
    cout << "Programa:" << endl;
    while (contador < n_operaciones)
    {
        instruccion[contador]->ejecutar(pila, contador);
    }
    cout << endl;
}

void ProgramaCuenta::listarFinal()
{
    cout << "Ejecución:" << endl;
    for (int i = 0; i < n_operaciones; i++)
    {
        cout << i << " ";
        instruccion[i]->listar();
    }
    cout << endl;
}