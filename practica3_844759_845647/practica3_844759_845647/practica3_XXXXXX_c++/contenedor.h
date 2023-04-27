//------------------------------------------------------------------------------
// File:   contenedor.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   marzo 2023
// Coms:   Práctica 3 de TecPro
//------------------------------------------------------------------------------

#pragma once


template <typename T>
class Contenedor : public Carga, public Almacen<T>
{
public:
    Contenedor(int c) : Carga("Contenedor", double(c), 0.0), Almacen<T>(c) {}

    double getPeso() const override
    {
        double aux = 0.0;
        for (auto i : this->elementos)
        {
            aux += i->getPeso();
        }
        return aux;
    }

    string to_string(int& nivel) override
    {
        stringstream ss;
        ss << this->nombre() << " [" << this->getVolumen() << " m3] [" << this->getPeso() << " kg] de " << this->elementos.front()->getTipo() << "\n";;
        nivel++;
        for (auto i : this->elementos)
        {
            for(int i = 0; i != nivel; i++){
                ss << "  "; 
            }
            ss << i->to_string(nivel);
            if (i != this->elementos.back())
            {
                ss << "\n";
            }
        }
        nivel--;
        return ss.str();
    }

    friend ostream &operator<<(ostream &os, const Contenedor &item)
    {
        os << item.to_string();
        return os;
    }
};