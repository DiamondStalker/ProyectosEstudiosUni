#include<iostream>
using namespace std;

int main(){

    int matriz[4][3];

    float promedio1 = 0;
    float promedio2 = 0;
    float promedio3 = 0;
    float promedio4 = 0;

    cout << "Programa Almacenar Notas" << endl;
    cout << "Ingrese los datos:" << endl;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            cout << "Estudiante [" << i + 1 << "] Materia #" << j + 1 << ": ";
            cin >> matriz[i][j];
        }
    }

    for(int j = 0; j < 3; j++){
        promedio1 += matriz[0][j];
    }
    promedio1 /= 3;

    for(int j = 0; j < 3; j++){
        promedio2 += matriz[1][j];
    }
    promedio2 /= 3;

    for(int j = 0; j < 3; j++){
        promedio3 += matriz[2][j];
    }
    promedio3 /= 3;

    for(int j = 0; j < 3; j++){
        promedio4 += matriz[3][j];
    }
    promedio4 /= 3;

    float promedios[4] = {promedio1, promedio2, promedio3, promedio4};

    float mayor = promedios[0];
    int donde = 0;

    for(int i = 1; i < 4; i++){
        if(promedios[i] > mayor){
            mayor = promedios[i];
            donde = i;
        }
    }

    cout << "\nEstudiante 1: " << promedio1 << endl;
    cout << "Estudiante 2: " << promedio2 << endl;
    cout << "Estudiante 3: " << promedio3 << endl;
    cout << "Estudiante 4: " << promedio4 << endl;

    cout << "\nEl estudiante con mayor promedio fue el estudiante "
         << donde + 1
         << " con un promedio de "
         << mayor << endl;

    return 0;
}