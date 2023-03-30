//------------------------------------------------------------------------------
// File:   over.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "over" de la práctica 2
//------------------------------------------------------------------------------
#include "over.h"

void Over::ejecutar(stack<int> &pila, int &contador) const
{
    int n1 = pila.top();
    pila.pop();
    int n2 = pila.top();
    pila.pop();
    pila.push(n2);
    pila.push(n1);
    pila.push(n2);
    contador++;
}

void Over::listar() const
{
    cout << "over" << endl;
}