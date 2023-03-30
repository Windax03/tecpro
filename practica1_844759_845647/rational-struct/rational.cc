//------------------------------------------------------------------------------
// File:   rational.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 1 de TecPro
//		   TAD de los racionales
//------------------------------------------------------------------------------

#include "rational.h"

// Helper functions -----------------------
int mcd(int a, int b)
{
	return (b == 0 ? a : mcd(b, a % b));
}

void reduce(Rational &r)
{
	int reductor = mcd(r.denominador, r.numerador);
	r.numerador = r.numerador / reductor;
	r.denominador = r.denominador / reductor;
}

// Constructor -----------------------
void init(Rational &r)
{
	r.numerador = 0;
	r.denominador = 1;
}
void init(Rational &r, int num, int den)
{
	r.denominador = den;
	r.numerador = num;
}

// Input/output ---------------------------------
void write(const Rational &r, std::ostream &os)
{
	os << "= " << r.numerador << "/" << r.denominador << std::endl;
}

void read(Rational &r, std::istream &is)
{
	char barra;
	is >> r.numerador >> barra >> r.denominador;
}

// ---------------------------
// Add -----------------------
Rational add(const Rational &r1, const Rational &r2)
{
	Rational res;

	res.denominador = r1.denominador * r2.denominador;
	res.numerador = (r1.numerador * r2.denominador) + (r2.numerador * r1.denominador);

	reduce(res);

	return res;
}

Rational add(const Rational &r, int i)
{
	Rational res;

	res.denominador = r.denominador * 1;
	res.numerador = (r.numerador * 1) + (i * r.denominador);

	reduce(res);

	return res;
}

Rational add(int i, const Rational &r)
{
	Rational res;

	res.denominador = r.denominador * 1;
	res.numerador = (r.numerador * 1) + (i * r.denominador);

	reduce(res);

	return res;
}

// --------------------------------
// Subtract -----------------------
Rational sub(const Rational &r1, const Rational &r2)
{
	Rational res;

	res.denominador = r1.denominador * r2.denominador;
	res.numerador = (r1.numerador * r2.denominador) - (r2.numerador * r1.denominador);

	reduce(res);

	return res;
}
Rational sub(const Rational &r, int i)
{
	Rational res;

	res.denominador = r.denominador * 1;
	res.numerador = (r.numerador * 1) - (i * r.denominador);

	reduce(res);

	return res;
}
Rational sub(int i, const Rational &r)
{
	Rational res;

	res.denominador = r.denominador * -1;
	res.numerador = (r.numerador * 1) - (i * r.denominador);

	reduce(res);

	return res;
}

// ----------------------------------
// Multiply -------------------------
Rational mul(const Rational &r1, const Rational &r2)
{

	Rational res;

	res.denominador = r1.denominador * r2.denominador;
	res.numerador = r1.numerador * r2.numerador;

	reduce(res);

	return res;
}
Rational mul(const Rational &r, int i)
{
	Rational res;

	res.denominador = r.denominador * 1;
	res.numerador = r.numerador * i;

	reduce(res);

	return res;
}
Rational mul(int i, const Rational &r)
{
	Rational res;

	res.denominador = r.denominador * 1;
	res.numerador = r.numerador * i;

	reduce(res);

	return res;
}

// -------------------------------------
// Divide ------------------------------
Rational div(const Rational &r1, const Rational &r2)
{
	Rational res;

	res.denominador = r1.denominador * r2.numerador;
	res.numerador = r1.numerador * r2.denominador;

	reduce(res);

	return res;
}
Rational div(const Rational &r, int i)
{
	Rational res;

	res.denominador = r.denominador * i;
	res.numerador = r.numerador * 1;

	reduce(res);

	return res;
}
Rational div(int i, const Rational &r)
{
	Rational res;

	res.denominador = r.numerador * 1;
	res.numerador = r.denominador * i;

	reduce(res);

	return res;
}
