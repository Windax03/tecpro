//------------------------------------------------------------------------------
// File:   enlace.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:   Práctica 4 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include "arbol.h"

class Enlace : public Arbol{

    protected:

        shared_ptr<Arbol> enlace;

    public:

        //Constructor
        Enlace(string n, shared_ptr<Arbol> e) : Arbol(n), enlace(e) {}


        //Función que devuelve el tamaño del enlace
        int tamagno() override{
            
            return enlace->tamagno();
        }

        //Devuelve el enlace
        shared_ptr<Arbol> enl(){
            return enlace;
        }

};