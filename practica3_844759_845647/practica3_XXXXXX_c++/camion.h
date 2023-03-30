//------------------------------------------------------------------------------
// File:   toxico.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------
#pragma once
#include <string>
#include <iostream>

class Camion : public Elemento, public Almacen<Carga>
{
public:
    Camion(int capacidad) : Elemento("Camion", double(capacidad), 0.0), Almacen<Carga>(capacidad) {}

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << nombre() << " [" << std::setprecision(4) << getVolumen() << " m3] [" << std::setprecision(4) << peso() << " kg]\n";
        for (auto i : elementos)
        {
            ss << " " + i->to_string();
            if (i != elementos.back())
            {
                ss << "\n";
            }
        }
        return ss.str();
    }

    double peso() const
    {
        double aux = 0.0;
        for (auto i : elementos)
        {
            aux += i->getPeso();
        }
        return aux;
    }

    friend std::ostream &operator<<(std::ostream &os, const Camion &a)
    {
        os << a.to_string();
        return os;
    }
};
