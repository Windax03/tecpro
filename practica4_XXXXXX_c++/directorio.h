//------------------------------------------------------------------------------
// File:   directorio.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:   Práctica 4 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include "arbol.h"

class Directorio : public Arbol {

    protected:

        list<shared_ptr<Arbol>> directorio;     //Lista con las componentes de un directorio

    public:

        //Constructor
        Directorio(string n) : Arbol(n) {}

        //Función que devuelve el tamaño del directorio
        int tamagno() override{
            int tam = 0;

            //Se recorren todas las componentes del directorio sumando sus tamaños
            for (auto i : directorio){
                tam = tam + i->tamagno();
            }

            return tam;
        }

        //Función que introduce en un flujo todas las componentes de un directorio
        string listComp(){

            stringstream ss;
            //Se recorren todas las componentes del directorio mostrandolas por terminal
            for (auto i : directorio){
                ss << i->nombre() << endl;
            }
            return ss.str();
        }

        //Función que introduce en un flujo el tamaño y nombre de las componentes del directorio.
        string listRec(){

            stringstream ss;
            // Se recorre los directorios del directorio acual mostrando el tamaño y el nombre
            for(auto i : directorio){  
                ss << i->nombre() << setw(15 + (to_string(i->tamagno()).length()) - i->nombre().length()) << i->tamagno() << endl; //-----------------
            }
            return ss.str();
        }


        shared_ptr<Arbol> EncontrarComp(string comp){
            //Se recorren todas las componentes del directorio
            for (auto i : directorio){
                
                //Si la componente a buscar se encuentra en el directorio se devuelve.
                if(comp == i->nombre()){
                    return i;
                }
            }
            //Si no se encuentra se devuelve vacia la componente.
            return nullptr;
        }

        //Función que añade una componente al directorio
        void ayadirComp(shared_ptr<Arbol> comp){
            directorio.push_back(comp);
        }

        //Función que borra una componente al directorio
        void borrarComp(shared_ptr<Arbol> comp){
            directorio.remove(comp);
        }


        

};