#include "vmp.h"
#include <cmath>
#include <iostream>

using namespace std;

VMP::VMP(int _id,double _x,double _y)
	: id(_id), x(_x), y(_y), estaEnBase(true), estaDisponible(true)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

int    VMP::identificador() const { return id; }
double VMP::distancia() const { return sqrt(x*x+y*y); }

bool   VMP::disponible() const { return estaDisponible; }
void   VMP::liberar()  { estaDisponible = true; }
void   VMP::bloquear() { estaDisponible = false; }

bool   VMP::aparcado() const { return estaEnBase; }

void   VMP::alquilar()
{
	cout << __PRETTY_FUNCTION__ << endl;
	estaDisponible = false;
	estaEnBase = false;
}

void   VMP::devolver()
{
	cout << __PRETTY_FUNCTION__ << endl;
	estaDisponible = true;
	estaEnBase = true;
}

VMPElectrico::VMPElectrico()
	: VMP(7,0,0), cargaBateria(100), estaCargando(true)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

double VMPElectrico::carga() const { return cargaBateria; }
void   VMPElectrico::carga(double c) { cargaBateria = c; }
bool   VMPElectrico::cargando() const { return estaCargando; }

void   VMPElectrico::alquilar()
{
	VMP::alquilar();
	cout << __PRETTY_FUNCTION__ << endl;
	estaCargando = false;
}

void   VMPElectrico::devolver()
{
	VMP::devolver();
	cout << __PRETTY_FUNCTION__ << endl;
	estaCargando = true;
}

double VMPElectrico::coste() const
{
	return VMPElectrico::precio;
}

Bicicleta::Bicicleta(int _id,double _x,double _y)
	: VMP(_id,_x,_y)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

double Bicicleta::coste() const
{
	return Bicicleta::precio;
}

BicicletaElectrica::BicicletaElectrica(int _id,double _x,double _y)
	: VMP(_id,_x,_y), Bicicleta(_id,_x,_y)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

double BicicletaElectrica::coste() const
{
	return Bicicleta::coste()+VMPElectrico::coste();
}

Patinete::Patinete(int _id,double _x,double _y)
	: VMP(_id,_x,_y)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

double Patinete::coste() const
{
	return Patinete::precio;
}

PatineteElectrico::PatineteElectrico(int _id,double _x,double _y)
	: VMP(_id,_x,_y), Patinete(_id,_x,_y)
{
	cout << __PRETTY_FUNCTION__ << endl;
}

double PatineteElectrico::coste() const
{
	return Patinete::coste()+VMPElectrico::coste();
}
