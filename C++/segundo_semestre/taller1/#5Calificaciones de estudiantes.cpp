#include<iostream>
#include<string>
using namespace std;
int main(){
    int matriz[4][3];
    int filas = 4;
    int columnas = 3;
    float promedio;
    cout << "INGRESE LAS CALIFICACIONES DE LO ESTUDIANTES"<<endl; 
    for(int i = 0; i<filas; i++){
        for(int j = 0; j<columnas; j++){
            cout << "Estudiante #"<<i+1<<" Nota Examen: #"<<j+1<<": ";
            cin >> matriz[i][j];
        }
    }
    cout << "TABLA COMPLETA" << endl;

cout << "              ";
for(int j = 0; j < columnas; j++){
    cout << "Nota " << j+1 << "     ";
}
cout << endl;

for(int i = 0; i < filas; i++){
    cout << "Estudiante " << i+1 << ": ";
    promedio = 0.0;
    for(int j = 0; j < columnas; j++){
        cout << matriz[i][j] << "          ";
        promedio += matriz[i][j];
    }
    promedio/=3;
    cout << "Promedio: "<<promedio;
    cout << endl;
}
return 0;
  }  
