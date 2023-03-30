//------------------------------------------------------------------------------
// File:   push.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "push" de la práctica 2
//------------------------------------------------------------------------------
#pragma once
#include "instruccion.h"

class Push : public Instruccion
{
private:
    int num;

public:
    Push(int num);

    void ejecutar(stack<int> &pila, int &contador) const override;

    void listar() const override;
};