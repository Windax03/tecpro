//------------------------------------------------------------------------------
// File:   programaSuma.java
// Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
// Date:   febrero 2023
// Coms:   Práctica 2 de TecPro
//------------------------------------------------------------------------------
import java.util.Stack;

public class ProgramaSuma extends Programa {
    
    private int n_operaciones = 4;
    private Instruccion[] instruccion = new Instruccion[n_operaciones];

    public ProgramaSuma() {
        instruccion[0] = new Read();
        instruccion[1] = new Read();
        instruccion[2] = new Add();
        instruccion[3] = new Write();
    }

    public void ejecutarFinal(Stack<Integer> pila, int contador) {
        System.out.println("Programa:");

        for (int i = 0; i < n_operaciones; i++) {
            instruccion[i].ejecutar(pila, contador);
        }

        System.out.println();
    }

    public void listarFinal() {
        System.out.println("Ejecución:");

        for (int i = 0; i < n_operaciones; i++) {
            System.out.print(i + " ");
            instruccion[i].listar();
        }

        System.out.println();
    }
}
