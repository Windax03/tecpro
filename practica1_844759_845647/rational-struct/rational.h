//------------------------------------------------------------------------------
// File:   rational.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 1 de TecPro
//         TAD de los racionales
//------------------------------------------------------------------------------
#pragma once

#include <iostream>

// Solucion con atributos publicos.

struct Rational
{
   // componentes
   int numerador;
   int denominador;
};

int mcd(int a, int b);
void reduce(Rational &r);

void init(Rational &r);
void init(Rational &r, int num, int den);

// Entrada - salida
void write(const Rational &r, std::ostream &os);
void read(Rational &r, std::istream &is);

// Operaciones aritmeticas

Rational add(const Rational &r1, const Rational &r2);
Rational add(const Rational &r, int i);
Rational add(int i, const Rational &r);

// sub
Rational sub(const Rational &r1, const Rational &r2);
Rational sub(const Rational &r, int i);
Rational sub(int i, const Rational &r);
// mul
Rational mul(const Rational &r1, const Rational &r2);
Rational mul(const Rational &r, int i);
Rational mul(int i, const Rational &r);
// div
Rational div(const Rational &r1, const Rational &r2);
Rational div(const Rational &r, int i);
Rational div(int i, const Rational &r);
