//------------------------------------------------------------------------------
// File:   nomina.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "nomina" del problema 2: Bancos con Herencia
//------------------------------------------------------------------------------

#pragma once
#include "cuenta.h"

class Nomina : public Cuenta{

public:
    double nomina;

    Nomina(double cap,double n) : Cuenta(cap),nomina(n) {}

    double valor(int t) const{
        return capital + t*nomina;
    }

};