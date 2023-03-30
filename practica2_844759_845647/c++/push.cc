// File:   push.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "push" de la práctica 2
//------------------------------------------------------------------------------
#include "push.h"

Push::Push(int num)
{
    this->num = num;
}

void Push::ejecutar(stack<int> &pila, int &contador) const
{
    pila.push(num);
    contador++;
}

void Push::listar() const
{
    cout << "push " << num << endl;
}