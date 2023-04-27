//------------------------------------------------------------------------------
// File:   camion.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------
#pragma once


class Camion : public Componente, public Almacen<Carga>
{
public:
    Camion(int c) : Componente("Camion", double(c), 0.0), Almacen<Carga>(c) {}

    string to_string(int& nivel) override
    {
        stringstream ss;
        ss << this->nombre() << " [" << this->getVolumen() << " m3] [" << this->getPeso() << " kg]\n";  
        for (auto i : this->elementos)
        {
            for(int i = 0; i!= nivel; i++){
                ss << "  " ;
            }
            ss << i->to_string(nivel);
            if (i != this->elementos.back())
            {
                ss << "\n";
            }
        }
        return ss.str();
    }
    
    double getPeso() const override
    {
        double aux = 0.0;
        for (auto i : elementos)
        {
            aux += i->getPeso();
        }
        return aux;
    }

    friend ostream &operator<<(ostream &os, Camion &a)
    {
        int nivel = 1;
        os << a.to_string(nivel);
        return os;
    }
};
