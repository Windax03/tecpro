//------------------------------------------------------------------------------
// File:   write.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "read" de la práctica 2
//------------------------------------------------------------------------------
#include "write.h"

void Write::ejecutar(stack<int> &pila, int &contador) const
{
    int dato = pila.top();
    pila.pop();
    cout << dato << endl;
    contador++;
}

void Write::listar() const
{
    cout << "write" << endl;
}