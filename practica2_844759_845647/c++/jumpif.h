//------------------------------------------------------------------------------
// File:   jumpif.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "jumpif" de la práctica 2
//------------------------------------------------------------------------------
#pragma once
#include "instruccion.h"

class Jumpif : public Instruccion
{
private:
    int linea;

public:
    Jumpif(int linea);

    void ejecutar(stack<int> &pila, int &contador) const override;

    void listar() const override;
};