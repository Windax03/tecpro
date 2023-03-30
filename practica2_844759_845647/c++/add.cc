//------------------------------------------------------------------------------
// File:   add.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "add" de la práctica 2
//------------------------------------------------------------------------------
#include "add.h"

void Add::ejecutar(stack<int> &pila, int &contador) const
{
    int num1 = pila.top();
    pila.pop();
    int num2 = pila.top();
    pila.pop();
    pila.push(num1 + num2);
    contador++;
}

void Add::listar() const
{
    cout << "add" << endl;
}