//------------------------------------------------------------------------------
// File:   main.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 1 de TecPro
//         Compilar mediante:
//           make
//------------------------------------------------------------------------------
#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational a, b, r;
	int i;
	char op;

	init(a);
	init(b);
	while (true)
	{
		cout << "? " << flush;

		// Lectura racional a
		read(a, cin);
		// Lectura de entero i
		// cin >> i;

		if (cin.fail())
			break;

		cin >> op;

		// Lectura racional b
		read(b, cin);
		// Lectura de entero i
		// cin >> i;

		if (cin.fail())
			break;

		// Calculo del resultado
		if (op == '+')
		{
			r = add(a, b);
			// Operaciones con enteros
			// r = add(i, b);
			// r = add(a, i);
		}
		if (op == '-')
		{
			r = sub(a, b);
			// Operaciones con enteros
			// r = sub(i, b);
			// r = sub(a, i);
		}
		if (op == '*')
		{
			r = mul(a, b);
			// Operaciones con enteros
			// r = mul(i, b);
			// r = mul(a, i);
		}
		if (op == '/')
		{
			r = div(a, b);
			// Operaciones con enteros
			// r = div(i, b);
			// r = div(a, i);
		}

		// Escritura del resultado
		write(r, cout);
	}

	return 0;
}
