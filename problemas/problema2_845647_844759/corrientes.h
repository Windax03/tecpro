//------------------------------------------------------------------------------
// File:   corrientes.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "corrientes" del problema 2: Bancos con Herencia
//------------------------------------------------------------------------------
#pragma once
#include "cuenta.h"

class Corrientes : public Cuenta {
public:
    double interes;

    // Constructor
    Corrientes(double cap,double i) : Cuenta(cap), interes(i) {}

    double valor(int t) const{
		return capital*pow((1.0+(interes/100.0)),t);
	}

};