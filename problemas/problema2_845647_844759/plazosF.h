//------------------------------------------------------------------------------
// File:   plazosF.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero "plazosF" del problema 2: Bancos con Herencia
//------------------------------------------------------------------------------

#pragma once
#include "cuenta.h"

class PlazosF : public Cuenta{

public:
    double interes;
    int plazos;
    // Constructor
    PlazosF(double capital,double i,int p) : Cuenta(capital), interes(i), plazos(p) {}

    double valor(int t) const
    {
	    return (t<plazos ? capital : capital*(1+(interes/100.0)));
    }

    double tae() const{
        double c12 = valor(0) + 12*((valor(plazos)-valor(0))/plazos);
		return ((c12/valor(0))-1)*100;
	}

    void actualiza(){
        if (plazos > 0){
            plazos--;
        }
        else if (plazos == 0){
            capital = capital * (1+interes/100.0);
        }
    }
};