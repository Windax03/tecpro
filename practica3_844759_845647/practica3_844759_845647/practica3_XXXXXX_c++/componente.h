//------------------------------------------------------------------------------
// File:   componente.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Clase abstracta base
class Componente
{
protected:
    string nom;
    double volumen;
    double peso;

public:
    Componente(const string &n, double v, double p) : nom(n), volumen(v), peso(p) {}

    virtual ~Componente() {}

    string nombre() const
    {
        return nom;
    }

    double getVolumen() const
    {
        return volumen;
    }

    virtual double getPeso() const
    {
        return peso;
    }

    virtual string getTipo() const
    {
        return "Carga Estandar";
    }

    virtual string to_string(int &nivel)
    {
        stringstream ss;
        ss << this->nom << " [" << this->volumen << " m3] [" << this->getPeso() << " kg]";
        return ss.str();
    }
};