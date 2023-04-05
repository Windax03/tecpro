//------------------------------------------------------------------------------
// File:   enlace.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:   Práctica 4 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include "arbol.h"

class Enlace : public Arbol{

    public:
    
        //El enlace esta en publico para que el shell pueda acceder a el y determinar el directorio que enlaza.
        shared_ptr<Arbol> enlace;

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