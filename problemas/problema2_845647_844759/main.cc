//------------------------------------------------------------------------------
// File:   main.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Fichero main del problema 2: Bancos con Herencia
//------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include "cuenta.h"
#include "corrientes.h"
#include "divisa.h"
#include "nomina.h"
#include "plazosF.h"

using namespace std;


double total(Cuenta* cuentas[], int n, int t)
{
	double sol = 0.0;
	for (int i=0; i<n; i++)
		sol += cuentas[i]->valor(t);
	return sol;
}

void mostrar_taes(Cuenta* cuentas[], int n)
{
	cout << "TAEs: ";
	for (int i=0; i<n; i++)
		cout << cuentas[i]->tae() << " ";
}

void actualizar_cuentas(Cuenta* cuentas[],int n){
	for(int i = 0; i < n; i++){
		cuentas[i]->actualiza();
	}
}

int main()
{
	Cuenta* cuentas[4];

	cuentas[0] = new Corrientes(1000, 1.2);
	cuentas[1] = new PlazosF(5000,60.0,12);
	cuentas[2] = new Nomina(2000, 2.5);      
	cuentas[3] = new Divisa(10000,0.8, cuentas[0]);  

	mostrar_taes(cuentas,4);
	cout << endl;

	cout << "Mes |  Valor cuentas                           |  Total      " << endl;
	cout << "=============================================================" << endl;
	for (int t=0; t<=24; t++)
	{
		cout << setw(3) << t;
		cout << " | ";
		for (int i=0; i<4; i++){
			cout << fixed << setw(10) << setprecision(2) << cuentas[i]->valor(t); 
		}
		cout << " | ";
		cout << fixed << setw(10) << setprecision(2) << total(cuentas,4,t);
		cout << " €" << endl;
	}

	cout << endl;
	cout << endl;
	mostrar_taes(cuentas,4);
	
	actualizar_cuentas(cuentas,4);
	
	cout << endl;
	cout << "CUENTAS ACTUALIZADAS" << endl;
	cout << "Mes |  Valor cuentas                           |  Total      " << endl;
	cout << "=============================================================" << endl;
	for (int t=0; t<=24; t++)
	{
		cout << setw(3) << t;
		cout << " | ";
		for (int i=0; i<4; i++){
			cout << fixed << setw(10) << setprecision(2) << cuentas[i]->valor(t); 
		}
		cout << " | ";
		cout << fixed << setw(10) << setprecision(2) << total(cuentas,4,t);
		cout << " €" << endl;
	}



	for (int i=0; i<4; i++)
		delete cuentas[i];

	return 0;
}

