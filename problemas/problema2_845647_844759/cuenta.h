//------------------------------------------------------------------------------
// File:   cuenta.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "cuenta" del problema 2: Bancos con Herencia
//------------------------------------------------------------------------------

#pragma once
#include <cmath>

using namespace std;


// Solución usando punteros a métodos

class Cuenta
{
public:
	// Capital de la cuenta
	double capital;


	Cuenta(double cap) : capital(cap) {} 

	virtual double valor(int t) const{
		return capital;
	}

	virtual double tae() const{
		return 100.0 * (valor(12) / valor(0) - 1);
	}

	virtual void actualiza(){
		capital = valor(1);
	}
};
