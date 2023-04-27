//------------------------------------------------------------------------------
// File:   toxico.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------
#pragma once


class Toxico : public Componente
{
public:
    Toxico(const string &n, double v, double p) : Componente(n, v, p) {}

    virtual ~Toxico() {}

    virtual string getTipo() const override
    {
        return "Productos Tóxicos";
    }
};