//------------------------------------------------------------------------------
// File:   SerVivo.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------
#pragma once
#include <string>
#include <iostream>

using namespace std;

class SerVivo : public Elemento
{
public:
    SerVivo(const std::string &nombre_, double volumen_, double peso_) : Elemento(nombre_, volumen_, peso_) {}

    virtual ~SerVivo() {}

    virtual std::string getTipo() const override
    {
        return "Seres vivos";
    }
};