//------------------------------------------------------------------------------
// File:   rational.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 1 de TecPro
//         TAD de los racionales
//------------------------------------------------------------------------------

#pragma once

#include <iostream>

// Solucion con atributos privados.

class Rational
{
	// Miembros
	int numerador;
	int denominador;
	// Funciones auxiliares
	static int mcd(int a, int b);
	void reduce();

public:
	// Constructores
	Rational();
	Rational(int num, int den);

	// Entrada - salida
	void write(std::ostream &os) const;
	void read(std::istream &is);

	// Operadores aritmeticos
	Rational add(const Rational &that) const;
	Rational add(int i) const;
	Rational sub(const Rational &that) const;
	Rational sub(int i) const;
	Rational mul(const Rational &that) const;
	Rational mul(int i) const;
	Rational div(const Rational &that) const;
	Rational div(int i) const;

	// SOBRESCRITURA DE LOS OPERACIONES

	// Operadores aritmeticos
	Rational operator+(const Rational &that) const;
	Rational operator+(int i) const;
	Rational operator-(const Rational &that) const;
	Rational operator-(int i) const;
	Rational operator*(const Rational &that) const;
	Rational operator*(int i) const;
	Rational operator/(const Rational &that) const;
	Rational operator/(int i) const;
};

// Operadores aritmeticos
Rational add(int i, const Rational &r);
Rational sub(int i, const Rational &r);
Rational mul(int i, const Rational &r);
Rational div(int i, const Rational &r);

std::ostream &operator<<(std::ostream &os, Rational &r);
std::istream &operator>>(std::istream &is, Rational &r);

Rational operator+(int i, const Rational &r);
Rational operator-(int i, const Rational &r);
Rational operator*(int i, const Rational &r);
Rational operator/(int i, const Rational &r);
