//------------------------------------------------------------------------------
// File:   contenedor.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#pragma once
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Contenedor : public Carga, public Almacen<T>
{
public:
    Contenedor(int capacidad) : Carga("Contenedor", double(capacidad), 0.0), Almacen<T>(capacidad) {}

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << nombre() << " [" << std::setprecision(4) << getVolumen() << " m3] [" << std::setprecision(4) << peso() << " kg] de " << this->elementos.front()->getTipo() << "\n";
        for (auto &i : this->elementos)
        {
            ss << "   " + i->to_string();
            if (i != this->elementos.back())
            {
                ss << "\n";
            }
        }
        return ss.str();
    }

    double peso() const
    {
        double aux = 0.0;
        for (auto &i : this->elementos)
        {
            aux += i->getPeso();
        }
        return aux;
    }

    friend std::ostream &operator<<(std::ostream &os, const Contenedor &a)
    {
        os << a.to_string();
        return os;
    }
};