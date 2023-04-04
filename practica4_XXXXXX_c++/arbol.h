//------------------------------------------------------------------------------
// File:   arbol.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:   Práctica 4 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <memory>


using namespace std;

class Arbol{

    protected:
        string name;

    public:

        //Constructor
        Arbol(string n) : name(n) {}

        //Función que devuelve el nombre de las componentes
        string nombre(){
            return name;
        }

        //Función que devuelve el tamaño de las componentes
        virtual int tamagno() = 0;

};