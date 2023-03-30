//------------------------------------------------------------------------------
// File:   read.java
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------
import java.util.Scanner;
import java.util.Stack;

public class Read extends Instruccion
{
    public void ejecutar(Stack<Integer> Pila, int contador){

        Scanner scanner = new Scanner(System.in);
        int dato;
        
        System.out.print("? ");
        dato = scanner.nextInt();
        pila.push(dato);
        contador = contador + 1;
    }

    public void listar(){
        System.out.println("read");
    }
}