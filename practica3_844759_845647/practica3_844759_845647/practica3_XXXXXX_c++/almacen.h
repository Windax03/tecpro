//------------------------------------------------------------------------------
// File:   almacen.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include <list>

// Clase Almacen para gestionar una lista de componentes
template <typename T>
class Almacen
{
protected:
    int capacidad;
    list<T *> elementos;
    
public:
    Almacen(int c) : capacidad(c) {}

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