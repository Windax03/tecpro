//------------------------------------------------------------------------------
// File:   producto.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#pragma once


class Producto : public Carga
{
public:
    Producto(const string &n, double v, double p) : Carga(n, v, p) {}

    virtual ~Producto() {}
};