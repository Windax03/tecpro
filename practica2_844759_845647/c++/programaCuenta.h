//------------------------------------------------------------------------------
// File:   programaCuenta.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

#pragma once
#include "programa.h"

using namespace std;

class ProgramaCuenta : public Programa
{
private:
    int n_operaciones = 7;
    InstruccionPtr *instruccion = new InstruccionPtr[n_operaciones];

public:
    ProgramaCuenta();

    void ejecutarFinal(stack<int> &pila, int &contador) override;

    void listarFinal() override;
};