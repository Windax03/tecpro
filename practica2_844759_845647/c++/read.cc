//------------------------------------------------------------------------------
// File:   read.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "read" de la práctica 2
//------------------------------------------------------------------------------
#include "read.h"

void Read::ejecutar(stack<int> &pila, int &contador) const
{
    int dato;
    cout << "? ";
    cin >> dato;
    pila.push(dato);
    contador++;
}

void Read::listar() const
{
    cout << "read" << endl;
}