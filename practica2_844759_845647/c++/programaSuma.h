//------------------------------------------------------------------------------
// File:   programaSuma.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

#pragma once
#include "programa.h"

using namespace std;

class ProgramaSuma : public Programa
{
private:
    int n_operaciones = 4;
    InstruccionPtr *instruccion = new InstruccionPtr[n_operaciones];

public:
    ProgramaSuma();

    void ejecutarFinal(stack<int> &pila, int &contador) override;

    void listarFinal() override;
};