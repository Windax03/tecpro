//------------------------------------------------------------------------------
// File:   serVivo.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------
#pragma once


class SerVivo : public Componente
{
public:
    SerVivo(const string &n, double v, double p) : Componente(n, v, p) {}

    virtual ~SerVivo() {}

    virtual string getTipo() const override
    {
        return "Seres Vivos";
    }
};