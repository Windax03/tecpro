//------------------------------------------------------------------------------
// File:   carga.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------
#pragma once


// Clases derivadas de Componente
class Carga : public Componente
{
public:
    Carga(const string &n, double v, double p) : Componente(n, v, p) {}

    virtual ~Carga() {}
};