//------------------------------------------------------------------------------
// File:   write.java
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------

import java.util.Stack;

public class Write extends Instruccion
{
    public void ejecutar(Stack<Integer> Pila, int contador){
        int dato = pila.peek();
        pila.pop();
        System.out.println(dato);
        contador = contador + 1;
    }

    public void listar(){
        System.out.println("write");
    }
}