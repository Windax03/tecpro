#include <iostream>
#include <iomanip>
#include <sstream>

// Clase abstracta base
class Elemento
{
protected:
    std::string nom;
    double volumen;
    double peso;

public:
    Elemento(const std::string &nombre_, double volumen_, double peso_) : nom(nombre_), volumen(volumen_), peso(peso_) {}

    virtual ~Elemento() {}

    std::string nombre() const
    {
        return nom;
    }

    double getVolumen() const
    {
        return volumen;
    }

    virtual double getPeso() const
    {
        return peso;
    }

    virtual std::string getTipo() const
    {
        return "Carga Estandar";
    }

    virtual std::string to_string() const
    {
        std::stringstream ss;
        ss << nom << " [" << std::setprecision(4) << volumen << " m3] [" << std::setprecision(4) << peso << " kg]";
        return ss.str();
    }
};