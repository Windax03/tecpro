//------------------------------------------------------------------------------
// File:   mul.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "mul" de la práctica 2
//------------------------------------------------------------------------------
#pragma once
#include "instruccion.h"

class Multi : public Instruccion
{
public:
    void ejecutar(stack<int> &pila, int &contador) const override;

    void listar() const override;
};