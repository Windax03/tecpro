//------------------------------------------------------------------------------
// File:   mul.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "mul" de la práctica 2
//------------------------------------------------------------------------------
#include "mul.h"

void Multi::ejecutar(stack<int> &pila, int &contador) const
{
    int n1 = pila.top();
    pila.pop();
    int n2 = pila.top();
    pila.pop();
    pila.push(n1 * n2);
    contador++;
}

void Multi::listar() const
{
    cout << "mul" << endl;
}