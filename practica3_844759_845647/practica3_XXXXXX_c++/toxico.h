//------------------------------------------------------------------------------
// File:   toxico.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Toxico : public Elemento
{
public:
    Toxico(const std::string &nombre_, double volumen_, double peso_) : Elemento(nombre_, volumen_, peso_) {}

    virtual ~Toxico() {}

    virtual std::string getTipo() const override
    {
        return "Productos tóxicos";
    }
};