//------------------------------------------------------------------------------
// File:   logger.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Problema 4 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include <list>
#include "store.h"

template<typename T>
class Logger{
    private: 
        list<Store<T>*> lista;
        string identificador;
    public:
        Logger(string i, list<Store<T>*> l) : identificador(i), lista(l){}

        void push(list<T> v){

        }

	    void log(){
            cout << identificador << endl;
            for(int i = lista.begin(); i != lista.end(); i++){
                cout << i*->name() << ":" << i*->value() << endl;
            }
        }
    
};