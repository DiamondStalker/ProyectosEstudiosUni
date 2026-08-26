import java.util.Scanner;

public class Main {

    // Variable miembro - global
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        // Variables locales
        String name;
        float nP1, nP2, nP3, nEF, nTF, nF = 0;

        // Entrada
        System.out.print("Ingrese el nombre del estudiante: ");
        name = sc.nextLine();

        System.out.print("Ingrese la nota del parcial 1: ");
        nP1 = sc.nextFloat();

        System.out.print("Ingrese la nota del parcial 2: ");
        nP2 = sc.nextFloat();

        System.out.print("Ingrese la nota del parcial 3: ");
        nP3 = sc.nextFloat();

        System.out.print("Ingrese la nota del parcial final: ");
        nEF = sc.nextFloat();

        System.out.print("Ingrese la nota del trabajo final: ");
        nTF = sc.nextFloat();

        // Proceso
        nF = (nP1 + nP2 + nP3) / 3 * 0.55f
                + nEF * 0.3f
                + nTF * 0.15f;

        // Salida
        System.out.println("Nombre: " + name + " Nota definitiva: " + nF);
    }
}