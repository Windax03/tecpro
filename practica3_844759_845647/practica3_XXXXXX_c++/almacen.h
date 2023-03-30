//------------------------------------------------------------------------------
// File:   almacen.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#pragma once
#include <string>
#include <iostream>
#include <list>

using namespace std;

// Clase Almacen para gestionar una lista de elementos
template <typename T>
class Almacen
{
protected:
    int capacidad;
    std::list<T *> elementos;

public:
    Almacen(int capacidad_) : capacidad(capacidad_) {}

    virtual ~Almacen()
    {
        for (auto e : elementos)
        {
            delete e;
        }
    }

    int getCapacidad() const
    {
        return capacidad;
    }

    bool guardar(T *nuevo)
    {
        double vol = 0.0;
        for (auto e : elementos)
        {
            vol += e->getVolumen();
        }
        if ((vol + nuevo->getVolumen()) > capacidad)
        {
            return false;
        }
        elementos.push_back(nuevo);
        return true;
    }
};