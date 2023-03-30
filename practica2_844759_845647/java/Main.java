//------------------------------------------------------------------------------
// File:   Main.java
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

import java.util.Stack;

public class Main
{
	public static void main(String[] args)
	{
        ProgramaSuma sum = new ProgramaSuma();

        Stack<Integer> pila = new Stack<Integer>();

        int contador = 0;

        sum.listarFinal();
        sum.ejecutarFinal(pila, contador);
    }

}