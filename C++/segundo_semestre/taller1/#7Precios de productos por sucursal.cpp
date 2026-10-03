#include<iostream>
#include<string>
using namespace std;

int main(){

    float arreglo[5][3];

    // 5 productos
    // 3 sucursales

    int filas = 5;
    int columnas = 3;
    float promedio = 0.0;

    cout << "Ingrese el precio de cada producto: " << endl;

    
    for(int i = 0; i < filas; i++){

        for(int j = 0; j < columnas; j++){

            cout << "Producto #" << i + 1
                 << ", Sucursal #" << j + 1 << ": ";

            cin >> arreglo[i][j];
        }
    }


    cout << "\n=== DATOS ===" << endl;


   
    for(int j = 0; j < columnas; j++){

        cout << "   Sucursal #" << j + 1;

    }

    cout << endl;


    
    for(int i = 0; i < filas; i++){

        cout << "Producto #" << i + 1;

        promedio = 0.0;

        for(int j = 0; j < columnas; j++){

            cout << "   " << arreglo[i][j] << "   ";

            promedio += arreglo[i][j];

        }

        promedio /= columnas;

        cout << "Promedio #" << i + 1 << ": " << promedio;

        cout << endl;
    }


   
    cout << "\n=== PROMEDIO POR SUCURSAL ===" << endl;

    for(int j = 0; j < columnas; j++){

        promedio = 0.0;

        for(int i = 0; i < filas; i++){

            promedio += arreglo[i][j];

        }

        promedio /= filas;

        cout << "Promedio Sucursal #" << j + 1
             << ": " << promedio << endl;
    }

    return 0;
}