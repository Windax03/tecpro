//------------------------------------------------------------------------------
// File:   jumpif.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "jumpif" de la práctica 2
//------------------------------------------------------------------------------
#include "jumpif.h"

Jumpif::Jumpif(int linea)
{
    this->linea = linea;
}

void Jumpif::ejecutar(stack<int> &pila, int &contador) const
{
    int num = pila.top();
    pila.pop();
    if (num >= 0)
    {
        contador = linea;
    }
    else
    {
        contador++;
    }
}

void Jumpif::listar() const
{
    cout << "jumpif " << linea << endl;
}