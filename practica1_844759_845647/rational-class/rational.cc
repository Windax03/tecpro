//------------------------------------------------------------------------------
// File:   rational.cc
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 1 de TecPro
//		   TAD de los racionales
//------------------------------------------------------------------------------

#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b)
{
	return (b == 0 ? a : mcd(b, a % b));
}

void Rational::reduce()
{
	int reductor = mcd(denominador, numerador);
	numerador = numerador / reductor;
	denominador = denominador / reductor;
}

// Constructor -----------------------
Rational::Rational()
{
	numerador = 0;
	denominador = 1;
}

Rational::Rational(int num, int den)
{
	denominador = den;
	numerador = num;
}

// Input/output ---------------------------------
void Rational::write(std::ostream &os) const
{
	os << "= " << numerador << "/" << denominador << std::endl;
}

void Rational::read(std::istream &is)
{
	char barra;
	is >> numerador >> barra >> denominador;
}

// ---------------------------
// Add -----------------------
Rational Rational::add(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.denominador;
	res.numerador = (this->numerador * that.denominador) + (that.numerador * this->denominador);

	res.reduce();

	return res;
}

Rational Rational::add(int i) const
{
	Rational res;

	res.denominador = this->denominador * 1;
	res.numerador = (this->numerador * 1) + (i * this->denominador);

	res.reduce();

	return res;
}

Rational add(int i, const Rational &r)
{
	return r.add(i);
}

// --------------------------------
// Subtract -----------------------
Rational Rational::sub(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.denominador;
	res.numerador = (this->numerador * that.denominador) - (that.numerador * this->denominador);

	res.reduce();

	return res;
}

Rational Rational::sub(int i) const
{
	Rational res;

	res.denominador = this->denominador * 1;
	res.numerador = (this->numerador * 1) - (i * this->denominador);

	res.reduce();

	return res;
}

Rational sub(int i, const Rational &r)
{
	Rational res;

	res = r.sub(i);
	return res.mul(-1);
}

// ----------------------------------
// Multiply -------------------------
Rational Rational::mul(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.denominador;
	res.numerador = this->numerador * that.numerador;

	res.reduce();

	return res;
}

Rational Rational::mul(int i) const
{
	Rational res;

	res.denominador = this->denominador * 1;
	res.numerador = (this->numerador * i);

	res.reduce();

	return res;
}

Rational mul(int i, const Rational &r)
{
	return r.mul(i);
}

// -------------------------------------
// Divide ------------------------------
Rational Rational::div(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.numerador;
	res.numerador = this->numerador * that.denominador;

	res.reduce();

	return res;
}

Rational Rational::div(int i) const
{
	Rational res;

	res.denominador = this->denominador * i;
	res.numerador = (this->numerador * 1);

	res.reduce();

	return res;
}

Rational div(int i, const Rational &r)
{
	Rational a = Rational(i, 1);
	return r.div(a);
}

// ====================================
// ====================================
// PARTE DE SOBRESCRITURA DE OPERADORES
// ====================================
// ====================================

std::ostream &operator<<(std::ostream &os, Rational &r)
{
	r.write(os);
	return os;
}

std::istream &operator>>(std::istream &is, Rational &r)
{
	r.read(is);
	return is;
}

// ---------------------------
// Add -----------------------
Rational Rational::operator+(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.denominador;
	res.numerador = (this->numerador * that.denominador) + (that.numerador * this->denominador);

	res.reduce();

	return res;
}

Rational Rational::operator+(int i) const
{
	Rational res;

	res.denominador = this->denominador * 1;
	res.numerador = (this->numerador * 1) + (i * this->denominador);

	res.reduce();

	return res;
}

Rational operator+(int i, const Rational &r)
{
	return r + i;
}

// --------------------------------
// Subtract -----------------------
Rational Rational::operator-(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.denominador;
	res.numerador = (this->numerador * that.denominador) - (that.numerador * this->denominador);

	res.reduce();

	return res;
}

Rational Rational::operator-(int i) const
{
	Rational res;

	res.denominador = this->denominador * 1;
	res.numerador = (this->numerador * 1) - (i * this->denominador);

	res.reduce();

	return res;
}

Rational operator-(int i, const Rational &r)
{
	Rational res;

	res = r - i;
	return res * (-1);
}

// ----------------------------------
// Multiply -------------------------
Rational Rational::operator*(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.denominador;
	res.numerador = this->numerador * that.numerador;

	res.reduce();

	return res;
}

Rational Rational::operator*(int i) const
{
	Rational res;

	res.denominador = this->denominador * 1;
	res.numerador = (this->numerador * i);

	res.reduce();

	return res;
}

Rational operator*(int i, const Rational &r)
{
	return r * i;
}

// -------------------------------------
// Divide ------------------------------
Rational Rational::operator/(const Rational &that) const
{
	Rational res;

	res.denominador = this->denominador * that.numerador;
	res.numerador = this->numerador * that.denominador;

	res.reduce();

	return res;
}

Rational Rational::operator/(int i) const
{
	Rational res;

	res.denominador = this->denominador * i;
	res.numerador = (this->numerador * 1);

	res.reduce();

	return res;
}

Rational operator/(int i, const Rational &r)
{
	Rational a = Rational(i, 1);
	return a / r;
}
