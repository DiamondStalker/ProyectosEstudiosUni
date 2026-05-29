#include<iostream>
using namespace std;
const int n = 150;
int main(){

    int suma, mayor, mayoresQ, posicion, j;

    

    int vec[n];
    int inverso[n];

    suma = 0;
    mayoresQ = 0;

    cout << "\nDigite el valor (" << n << " elementos)\n";

    for(int i = 0; i < n; i++){
        cout << "Posicion: " << i + 1 << " valor: ";
        cin >> vec[i];
    }

    mayor = vec[0];
    posicion = 0;

    for(int i = 0; i < n; i++){
        if(vec[i] > mayor){
            mayor = vec[i];
            posicion = i;
        }
    }

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            suma += vec[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(vec[i] > 80 && vec[i] < 120){
            mayoresQ++;
        }
    }

    j = n - 1;

    for(int i = 0; i < n; i++){
        inverso[i] = vec[j];
        j--;
    }

    cout << "\nVector original:\n";

    for(int i = 0; i < n; i++){
        cout << vec[i] << " ";
    }

    cout << "\n\n" << mayor
         << " es el numero mas grande del vector, encontrado en la posicion: "
         << posicion + 1 << endl;

    cout << "La suma de las posiciones pares es: " << suma << endl;

    cout << "Hay: " << mayoresQ
         << " numeros mayores que 80 y menores que 120" << endl;

    cout << "Vector invertido:\n";

    for(int i = 0; i < n; i++) cout << inverso[i] << " ";
    

    return 0;
}