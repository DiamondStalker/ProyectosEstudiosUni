#include <iostream>
using namespace std;

void mostrarMatriz(int matriz[100][100], int n);
bool matrizIdentidad(int matriz[100][100], int n);
bool matrizSimetrica(int matriz[100][100], int n);
int sumaElementos(int matriz[100][100], int n);
int sumaDiagonalPrincipal(int matriz[100][100], int n);
bool esNula(int matriz[100][100], int n);
void multiplicarPorEscalar(int matriz[100][100], int n, int escalar);

int main() {
    int matriz[100][100];
    int n, opcion, escalar;

    cout << "Digite el tamaño de la matriz cuadrada: ";
    cin >> n;

    cout << "\nDigite los elementos de la matriz:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Posicion [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Mostrar matriz\n";
        cout << "2. Verificar si es identidad\n";
        cout << "3. Verificar si es simetrica\n";
        cout << "4. Sumar todos los elementos\n";
        cout << "5. Sumar diagonal principal\n";
        cout << "6. Verificar si es nula\n";
        cout << "7. Multiplicar por escalar\n";
        cout << "8. Salir\n";
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                mostrarMatriz(matriz, n);
                break;

            case 2:
                if(matrizIdentidad(matriz, n)) {
                    cout << "La matriz es identidad.\n";
                } else {
                    cout << "La matriz no es identidad.\n";
                }
                break;

            case 3:
                if(matrizSimetrica(matriz, n)) {
                    cout << "La matriz es simetrica.\n";
                } else {
                    cout << "La matriz no es simetrica.\n";
                }
                break;

            case 4:
                cout << "La suma de los elementos es: "
                     << sumaElementos(matriz, n) << endl;
                break;

            case 5:
                cout << "La suma de la diagonal principal es: "
                     << sumaDiagonalPrincipal(matriz, n) << endl;
                break;

            case 6:
                if(esNula(matriz, n)) {
                    cout << "La matriz es nula.\n";
                } else {
                    cout << "La matriz no es nula.\n";
                }
                break;

            case 7:
                cout << "Digite el escalar: ";
                cin >> escalar;

                multiplicarPorEscalar(matriz, n, escalar);

                cout << "Matriz resultante:\n";
                mostrarMatriz(matriz, n);
                break;

            case 8:
                cout << "Programa finalizado.\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while(opcion != 8);

    return 0;
}

void mostrarMatriz(int matriz[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

bool matrizIdentidad(int matriz[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(i == j && matriz[i][j] != 1) {
                return false;
            }

            if(i != j && matriz[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool matrizSimetrica(int matriz[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(matriz[i][j] != matriz[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int sumaElementos(int matriz[100][100], int n) {
    int suma = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            suma += matriz[i][j];
        }
    }

    return suma;
}

int sumaDiagonalPrincipal(int matriz[100][100], int n) {
    int suma = 0;

    for(int i = 0; i < n; i++) {
        suma += matriz[i][i];
    }

    return suma;
}

bool esNula(int matriz[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(matriz[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

void multiplicarPorEscalar(int matriz[100][100], int n, int escalar) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matriz[i][j] = matriz[i][j] * escalar;
        }
    }
}