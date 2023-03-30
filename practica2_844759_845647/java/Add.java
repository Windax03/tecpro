//------------------------------------------------------------------------------
// File:   add.java
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

import java.util.Stack;

public class Add extends Instruccion
{
    public void ejecutar(Stack<Integer> Pila, int contador){
        int num1 = Pila.peek();
        pila.pop();
        int num2 = Pila.peek();
        Pila.pop();
        Pila.push(num1 + num2);
        contador = contador + 1;
    }

    public void listar(){
        System.out.println("add");
    }
}