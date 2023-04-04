//------------------------------------------------------------------------------
// File:   fichero.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:   Práctica 4 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include "arbol.h"

class Fichero: public Arbol{

    protected:
        int tam;

    public:

        //Constructor
        Fichero(string n, int t) : Arbol(n), tam(t) {}

        //Función que devuelve el tamaño del fichero
        int tamagno() override{
            return tam;
        }

        //Función que modifica el tamaño del fichero
        void modTam(int t){
            tam = t;
        }

};