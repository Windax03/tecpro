//------------------------------------------------------------------------------
// File:   programa.h
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

import java.util.Stack;

abstract class Programa
{
    public Programa(){};

    public abstract void ejecutarFinal(Stack<Integer> pila, int contador);

    public abstract void listarFinal();
};