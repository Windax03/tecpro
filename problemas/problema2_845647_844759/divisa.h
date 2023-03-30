//------------------------------------------------------------------------------
// File:   divisa.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "divisa" del problema 2: Bancos con Herencia
//------------------------------------------------------------------------------

#pragma once
#include "cuenta.h"

class Divisa : public Cuenta{

public:
    double factor;
    Cuenta* cuenta;

    Divisa(double cap,double r,Cuenta* cuent) : Cuenta(cap),factor(r), cuenta(cuent) {}

    double valor(int t) const{
        return cuenta->valor(t)*factor;
    }

};