#include<iostream>
using namespace std;

int main(){

    int filas, columnas;

    cout << "Digite el numero de filas: ";
    cin >> filas;

    cout << "Digite el numero de columnas: ";
    cin >> columnas;

    int matriz1[100][100];
    int matriz2[100][100];

    cout << "\nDigite los datos de la matriz 1:\n";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "[" << i << "][" << j << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "\nDigite los datos de la matriz 2:\n";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "[" << i << "][" << j << "]: ";
            cin >> matriz2[i][j];
        }
    }

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            int aux = matriz1[i][j];
            matriz1[i][j] = matriz2[i][j];
            matriz2[i][j] = aux;
        }
    }

    cout << "\nMatriz 1 despues del intercambio:\n";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << matriz1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz 2 despues del intercambio:\n";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << matriz2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}