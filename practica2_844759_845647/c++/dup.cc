//------------------------------------------------------------------------------
// File:   dup.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "dup" de la práctica 2
//------------------------------------------------------------------------------
#include "dup.h"

void Dup::ejecutar(stack<int> &pila, int &contador) const
{
    int num = pila.top();
    pila.pop();
    pila.push(num);
    pila.push(num);
    contador++;
}

void Dup::listar() const
{
    cout << "dup" << endl;
}