//------------------------------------------------------------------------------
// File:   programa.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

#pragma once
#include "instruccion.h"

using InstruccionPtr = Instruccion *;

class Programa
{

public:
    Programa();

    virtual void ejecutarFinal(stack<int> &pila, int &contador) = 0;

    virtual void listarFinal() = 0;
};