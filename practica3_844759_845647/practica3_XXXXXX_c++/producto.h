//------------------------------------------------------------------------------
// File:   producto.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Producto : public Carga
{
public:
    Producto(const std::string &nombre_, double volumen_, double peso_) : Carga(nombre_, volumen_, peso_) {}

    virtual ~Producto() {}
};