//------------------------------------------------------------------------------
// File:   Ex_yaDirec.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:    Práctica 4 de TecPro   
//------------------------------------------------------------------------------

#pragma once

#include "arbol_ficheros_error.h"


class Ex_yaDirec : public arbol_ficheros_error{

    public:
        
        const char* what() const throw() override{
            return "La componente indicada ya es un directorio";
        }

};