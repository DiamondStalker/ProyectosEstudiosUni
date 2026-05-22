#include <iostream>
#include <string>
using namespace std;

int main(){
    int suma  = 0;
    int sumaD = 0;
    int sumaS = 0;
    int mayor;
    string dias[4]     = {"Dia 1", "Dia 2", "Dia 3", "Dia 4"};
    string Sucursal[3] = {"Sucursal 1", "Sucursal 2", "Sucursal 3"};
    int ventas[3][4];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            cout << Sucursal[i] << ", " << dias[j] << ", Valor venta: ";
            cin  >> ventas[i][j];
            cout << endl;
        }
    }

    cout << "\nLa Matriz es:\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++)
            cout << ventas[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            suma += ventas[i][j];
    cout << "\nLa suma de las ventas es: " << suma << endl;

    cout << "\n=== Sumatoria de Dias ===" << endl;
    for (int j = 0; j < 4; j++){
        sumaD = 0;
        for (int i = 0; i < 3; i++)
            sumaD += ventas[i][j];
        cout << "La suma del " << dias[j] << " es: " << sumaD << endl;
    }

    cout << "\n=== Sumatoria de Sucursales ===" << endl;
    for (int i = 0; i < 3; i++){
        sumaS = 0;
        for (int j = 0; j < 4; j++)
            sumaS += ventas[i][j];
        cout << "La suma de " << Sucursal[i] << " es: " << sumaS << endl;
    }

    cout << "\n=== Mayor venta por Sucursal ===" << endl;
    for (int i = 0; i < 3; i++){
        mayor = 0;
        for (int j = 0; j < 4; j++){
            if (mayor < ventas[i][j])
                mayor = ventas[i][j];
        }
        cout << "La venta mayor de " << Sucursal[i] << " es: " << mayor << endl;
    }

    cout << "\n=== Mayor venta por Dia ===" << endl;
    for (int j = 0; j < 4; j++){
        mayor = ventas[0][j];
        for (int i = 0; i < 3; i++){
            if (mayor < ventas[i][j])
                mayor = ventas[i][j];
        }
        cout << "La venta mayor de " << dias[j] << " es: " << mayor << endl;
    }

    return 0;
}