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

            //Cuando no se encuentra en el raiz, se elimina un "/" para que no se duplique.
            if (ruta.size() > 1){
                rutaComp = rutaComp.substr(1);
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

            //Se crea el directorio deseado
            shared_ptr<Directorio> direc = make_shared<Directorio>(name);
            //Se añade en la ubicación indicada
            ruta.back()->ayadirComp(direc);
        }

        void cd(string path){
            
            //En el caso que el path sea "." se queda en la ruta actual.
            if (path != "."){
                
                //En el caso que el path sea "/" se va al directorio raiz
                if (path == "/"){
                    
                    shared_ptr<Directorio> raiz =  ruta.front();  // Nos movemos al principio de la lista, es decir, el directorio raiz
                    ruta.clear();                                 // Limpiamos toda la dirección
                    ruta.push_back(raiz);                         // Añadimos el directorio raiz a la ruta
                }
                else if (path == ".."){          //En el caso que el path sea ".." se retrocede un directorio
                    
                    //Si nos encontramos en un directorio que no es el raiz, se retrocede uno.
                    if (ruta.size() > 1){
                        ruta.pop_back();
                    }
                }
                else if (static_cast<int>(path.find_last_of("/")) > -1){  //En el caso que el path sea una ruta compleja, se avanza hasta el final de ella.
                    //Se va avanzando paso a paso tal como se indique en el path.
                    if (path[0] == '/'){    //En el caso de que primero sea el directorio raiz se dirige ahi.
                        cd("/");
                    }
                    //Posteriormente se va avanzando por los directorios que indique el path.
                    char *comp = strtok((char *)path.c_str(),"/");
                    while (comp != nullptr){                    //Iteramos hasta el ultimo componente, avanzando en los directorios
                        cd(comp);
                        comp = strtok(nullptr, "/");
                    }
                }
                //-----------------------------------------------------------------------------------------------caso ../
                else{   //En los demás casos se indica un directorio especifico para avanzar a él.

                    //Se busca el directorio con el nombre que se indica en path
                    shared_ptr<Arbol> dir = ruta.back()->EncontrarComp(path);

                    //Se avanza al directorio especificado.
                    ruta.push_back(dynamic_pointer_cast<Directorio>(dir));
                    
                }
                
            }

        }

        void ln(string path, string name){              //-------------------------------------

            string rutaActual = pwd();          //Se extrae la ruta actual

            if(path == "."){  // Si el path es un punto, creamos un enlace con el directorio actual

                shared_ptr<Enlace> ln = make_shared<Enlace>(name, dynamic_pointer_cast<Arbol>(ruta.back()));
                ruta.back()->ayadirComp(ln);
            }
            else if(path == ".."){  // Si el path es "..", creamos un enlace con el directorio anterior a este
                
                cd("..");   // Nos movemos al directorio anterior
                shared_ptr<Enlace> ln = make_shared<Enlace>(name, dynamic_pointer_cast<Arbol>(ruta.back())); //Creamos el enlace
                cd(rutaActual);                 // Volvemos al directorio viejo
                ruta.back()->ayadirComp(ln);    // Añadimos a este directorio el enlace creado
            }
            else{   // En caso de ser una ruta simple o compuesta

                int pos = path.find_last_of("/");   // Encontramos el ultimo elemento de la ruta

                if(pos != -1){  // Si este no es el ultimo elemento

                    string dir_ln = path.substr(0,pos); // Cogemos la dirección donde queremos crear el enlace
                    path = path.substr(pos+1);

                    if(path == ".."){       // Si el path es ".."

                        pos = dir_ln.find_last_of("/");     // Avanzamos hacia atras y hacemos llamada recursiva
                        dir_ln = dir_ln.substr(0,pos);
                        ln(dir_ln,name);
                    }
                    else if(path == "."){   // Si es un punto, no hacemos nada y llamamos recursivamente
                        ln(dir_ln,name);
                    }
                    else{

                        cd(dir_ln); // Nos movemos al directorio con el archivo a enlazar
                        shared_ptr<Arbol> comp = ruta.back()->EncontrarComp(path);

                        if(comp != nullptr){
                            shared_ptr<Enlace> ln = make_shared<Enlace>(name,comp); // Creamos el enlace
                            cd(rutaActual);                                         // Nos movemos a la ruta vieja
                            ruta.back()->ayadirComp(ln);                            // Añadimos el enlace en el directorio donde lo creamos
                        }
                    }
                }
                else{

                    shared_ptr<Arbol> comp = ruta.back()->EncontrarComp(path);
                    // Si la componente existe
                    if(comp != nullptr){
                        shared_ptr<Enlace> ln = make_shared<Enlace>(name,comp); // Se crea un enlace de un enlace
                        ruta.back()->ayadirComp(ln);
                    }
                }
            }
        }


        int stat(string path){

            int ultimaComp = path.find_last_of("/");    //Se extrae el valor de la última componente para ver en que posición se esta.
            string rutaActual = pwd();                  //Se extrae la ruta actual
            string comp;

            //Se realizan los siguientes condicionales para localizarse en el directorio deseado
            
            if(ultimaComp == 0){                        //Si la última componente es cero nos encontramos en el directorio raiz
                string r = path.substr(0,1);
                cd(r);
                comp = path.substr(1);
            }

            else if(ultimaComp == -1){                  //Si la última componente indica -1 indica el directorio actual
                comp = path;
            }

            else{                                       //En los demás casos es un ruta compleja
                string r = path.substr(0, ultimaComp);
                cd(r);
                comp = path.substr(ultimaComp+1);
            }

            shared_ptr<Arbol> componente;
            
            //Se selecciona la componente de la que se quiere obtener el tamaño
            componente = ruta.back()->EncontrarComp(comp);

            //Volvemos a la ruta inicial
            cd (rutaActual);

            //Se devuelve el tamaño de la componente deseada
            return componente->tamagno();

        }


        void rm(string path){
            
            string rutaActual = pwd();                  //Se extrae la ruta actual
            int ultimaComp = path.find_last_of("/");    //Se extrae el valor de la última componente para ver en que posición se esta.

            if(ultimaComp != -1){
                string dir_rm = path.substr(0,ultimaComp);
                path = path.substr(ultimaComp+1);
                cd(dir_rm);
            }
            
            shared_ptr<Arbol> comp = ruta.back()->EncontrarComp(path);

            if(comp != nullptr){

                if(dynamic_pointer_cast<Fichero>(comp) != nullptr){
                    shared_ptr<Fichero> fich = dynamic_pointer_cast<Fichero>(comp);
                    ruta.back()->borrarComp(fich);
                }
                else if(dynamic_pointer_cast<Enlace>(comp) != nullptr){
                    shared_ptr<Enlace> ln = dynamic_pointer_cast<Enlace>(comp);
                    ruta.back()->borrarComp(ln);
                }
                else{
                    shared_ptr<Directorio> direc = dynamic_pointer_cast<Directorio>(comp);
                    ruta.back()->borrarComp(direc);
                }
            }
            cd(rutaActual);
            
        }

};
