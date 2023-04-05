//------------------------------------------------------------------------------
// File:   shell.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   abril 2023
// Coms:   Práctica 4 de TecPro
//------------------------------------------------------------------------------

#pragma once

#include "fichero.h"
#include "directorio.h"
#include "enlace.h"

class Shell{

    protected:
    
        list<shared_ptr<Directorio>> ruta;      //Ruta de directorios
        Directorio dir = Directorio("");        //Se crea el directorio raiz

    public:

        //Constructor que crea el directorio raiz.
        Shell(){
            ruta.push_back(make_shared<Directorio>(dir));
        }

        string pwd(){
            string rutaComp;

            //Se recorren todas los directorios de la ruta
            for (auto i : ruta){
                rutaComp = rutaComp + "/" + i->nombre();
            }

            return rutaComp;
        }

        string ls(){
            
            //Se muestran las componentes del directorio en el que se encuentra
            return ruta.back()->listComp();
        }

        string du(){
            //Se muestran el nombre y tamaño de todos los contenidos de la ruta actual.
            return ruta.back()->listRec();
        }

        void vi(string name, int size){

            shared_ptr<Arbol> comp = ruta.back()->EncontrarComp(name);

            //Si el fichero no existe se crea
            if(comp == nullptr){
                shared_ptr<Fichero> archivo = make_shared<Fichero>(name,size);
                ruta.back()->ayadirComp(archivo);
            }
            else{


                // Si el archivo existe se itera hasta llegar al ultimo enlace.
                while(dynamic_pointer_cast<Enlace>(comp) != nullptr){               //----------------------
                    
                    shared_ptr<Enlace> ptr =  dynamic_pointer_cast<Enlace>(comp);
                    //excepcion si el enlace apunta a un directorio
                    comp = ptr->enl();
                }

                //Se comprueba que sea un fichero
                if(dynamic_pointer_cast<Fichero>(comp) != nullptr){

                    shared_ptr<Fichero> ptr =  dynamic_pointer_cast<Fichero>(comp);
                    ptr->modTam(size);
                }
            }
        }

        void mkdir(string name){
            
            shared_ptr<Directorio> direc = make_shared<Directorio>(name);
            ruta.back()->ayadirComp(direc);
        }

};
