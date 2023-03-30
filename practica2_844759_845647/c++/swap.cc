//------------------------------------------------------------------------------
// File:   swap.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "swap" de la práctica 2
//------------------------------------------------------------------------------
#include "swap.h"

void Swap::ejecutar(stack<int> &pila, int &contador) const
{
    int n1 = pila.top();
    pila.pop();
    int n2 = pila.top();
    pila.pop();
    pila.push(n1);
    pila.push(n2);
    contador++;
}

void Swap::listar() const
{
    cout << "swap" << endl;
}