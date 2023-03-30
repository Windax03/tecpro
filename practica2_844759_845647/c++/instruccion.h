//------------------------------------------------------------------------------
// File:   instruccion.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

#pragma once
#include <string>
#include <stdlib.h>
#include <stack>
#include <iostream>

using namespace std;

class Instruccion
{

public:
    Instruccion(){};

    virtual void ejecutar(stack<int> &pila, int &contador) const = 0;

    virtual void listar() const = 0;
};