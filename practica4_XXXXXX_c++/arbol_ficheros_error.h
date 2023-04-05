//------------------------------------------------------------------------------
// File:   arbol_ficheros_error.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:    Fichero que almacena la clase que gestiona las excepciones
//          Práctica 4 de TecPro
//------------------------------------------------------------------------------

#pragma once


class arbol_ficheros_error{
       
    public:

        virtual const char* what() const throw() = 0;

};