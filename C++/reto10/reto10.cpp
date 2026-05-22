#include <iostream>
using namespace std;

const int TAM = 8;


void pedirD(int V[]);
void mostrarVector(int V[]);
void ordenarBurbuja(int V[]);
void busquedaBinaria(int V[], int objetivo);

int main() {
    int opcion;
    int V[TAM];
    bool ordenado = false; 

    do {
        cout << "\n===MENU===\n"
             << "1. Pedir Datos\n"
             << "2. Mostrar el vector\n"
             << "3. Ordenar el vector\n"
             << "4. Realizar la busqueda binaria\n"
             << "5. Salir del programa\n"
             << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pedirD(V);
                ordenado = false; 
                break;
            case 2:
                mostrarVector(V);
                break;
            case 3:
                ordenarBurbuja(V);
                ordenado = true;
                break;
            case 4:
                if (!ordenado) {
                    cout << "Primero debe ordenar el vector (opcion 3).\n";
                } else {
                    int num;
                    cout << "Numero a buscar: ";
                    cin >> num;
                    busquedaBinaria(V, num);
                }
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n"; 
                break;                        
        }

    } while (opcion != 5);

    return 0;
}

void pedirD(int V[]) {          
    cout << "===OPCION 1: Pedir Datos===\n"
         << "Digite " << TAM << " numeros:\n"; 
    for (int i = 0; i < TAM; i++) { 
        cout << "V[" << i << "]: ";
        cin >> V[i];
    }
}

void mostrarVector(int V[]) {
    cout << "Vector: [ ";
    for (int i = 0; i < TAM; i++) {
        cout << V[i];
        if (i < TAM - 1) cout << ", ";
    }
    cout << " ]\n";
}

void ordenarBurbuja(int V[]) {
    int temp;
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1 - i; j++) {
            if (V[j] > V[j + 1]) {
                temp     = V[j];
                V[j]     = V[j + 1];
                V[j + 1] = temp;
            }
        }
    }
    cout << "Vector ordenado correctamente.\n";
}

void busquedaBinaria(int V[], int objetivo) {
    int inicio = 0, fin = TAM - 1, medio;
    bool encontrado = false;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        if (V[medio] == objetivo) { encontrado = true; break; }
        else if (V[medio] < objetivo) inicio = medio + 1;
        else fin = medio - 1;
    }

    if (encontrado)
        cout << "Elemento " << objetivo << " encontrado en indice [" << medio << "]\n";
    else
        cout << "Elemento " << objetivo << " NO encontrado.\n";
}