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
	Rational a, b, c, r;
	int i;
	char op;

	while (true)
	{
		// ==========================================
		// Parte de prueba que se sustituye
		// ==========================================

		/*a.read(cin);
		b.read(cin);
		c.read(cin);
		r = a.add(b.multi(c));
		r.write(cout);
		cout << endl;*/

		// ==========================================
		// Parte de prueba de operadores sobrescritos
		// ==========================================

		/*cout << "? " << flush;
		cin >> a >> b >> c;
		r = a + b * c;
		cout << r << endl;*/

		// ==========================================
		// Parte de prueba normal
		// ==========================================

		cout << "? " << flush;
		// Lectura racional a
		cin >> a;
		// Lectura de entero i
		//  cin >> i;

		if (cin.fail())
			break;

		cin >> op;
		// Lectura racional b
		cin >> b;
		// Lectura de entero i
		//  cin >> i;

		if (cin.fail())
			break;

		// Calculo del resultado
		if (op == '+')
		{
			r = a + b;
			// Operaciones con enteros
			// r = a + i;
			// r = i + b;
		}
		else if (op == '-')
		{
			r = a - b;
			// Operaciones con enteros
			// r = a - i;
			// r = i - b;
		}
		else if (op == '*')
		{
			r = a * b;
			// Operaciones con enteros
			// r = a * i;
			// r = i * b;
		}
		else if (op == '/')
		{
			r = a / b;
			// Operaciones con enteros
			// r = a / i;
			// r = i / b;
		}

		// Escritura del resultado
		cout << r;
	}

	return 0;
}
