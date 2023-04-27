//------------------------------------------------------------------------------
// File:   elemento.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

// Clase abstracta base
class Elemento
{
protected:
    string nom;
    double volumen;
    double peso;

public:
    Elemento(const string &nombre_, double volumen_, double peso_) : nom(nombre_), volumen(volumen_), peso(peso_) {}

    virtual ~Elemento() {}

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

    virtual string to_string() const
    {
        stringstream ss;
        ss << nom << " [" << setprecision(4) << volumen << " m3] [" << setprecision(4) << peso << " kg]";
        return ss.str();
    }
};