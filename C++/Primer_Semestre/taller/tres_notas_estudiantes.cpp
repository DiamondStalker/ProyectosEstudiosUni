#include <iostream>
using namespace std;

int main(){
    float calificaciones, alta, baja, suma;
    float promedio;
    int contador;
    promedio = 0;
    contador = 0;
    suma = 0;

    do {
        cout << "\nPorfa Digite las calificaciones del estudiante del 0-5\n"
             << "Usar -1 para salir del programa\n"
             << "Calificacion: ";
        cin >> calificaciones;

        if (calificaciones >= 0 && calificaciones <= 5) {
            suma += calificaciones;
            contador++;

            if (contador == 1) {
                alta = calificaciones;
                baja = calificaciones;
            }
            if (calificaciones > alta) {
                alta = calificaciones;  
            }
            if (calificaciones < baja) {
                baja = calificaciones;  
            }
        }

    } while (calificaciones != -1);

    
    if (contador > 0) {
        promedio = suma / contador;
        cout << "\n--- Resultados ---\n"
             << "Calificaciones ingresadas: " << contador << "\n"
             << "Promedio:   " << promedio << "\n"
             << "Mas alta:   " << alta    << "\n"
             << "Mas baja:   " << baja    << "\n";
    } else {
        cout << "No se ingresaron calificaciones.\n";
    }
}