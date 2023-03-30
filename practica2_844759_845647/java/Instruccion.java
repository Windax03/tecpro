//------------------------------------------------------------------------------
// File:   instruccion.java
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

import java.util.Stack;

abstract class Instruccion{

    public Instruccion(){}

    public abstract void ejecutar(Stack<Integer> Pila, int contador);

    public abstract void listar();

}

