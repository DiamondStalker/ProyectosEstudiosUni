#include<iostream>
using namespace std;
int main(){
    int sensores[5][5];
    cout << "\nDigite las temperaturas\n";
    for(int i = 0; i<5;i++){
        for(int j = 0; j<5;j++){
            cout << "Posicion["<<i+1<<"]"<<"["<<j+1<<"]: ";
            cin >> sensores[i][j];
        }
    }
    int mayor = -1;
    int posicion_x, posicion_y;
    for(int i = 0; i<5;i++){
        for(int j = 0; j<5;j++){
            if(sensores[i][j]>mayor){
                mayor = sensores[i][j];
                posicion_x= i+1;
                posicion_y=j+1;
            }
        }
    }

    int promedio = 0;
    for(int i = 0; i<5;i++){
        for(int j = 0; j<5;j++){
      promedio += sensores[i][j];
        }
    }

    promedio /= 25;

    cout << "El promedio de las temperaturas fue de: "<<promedio<<endl;
    cout << "La temperatura mayor registrada fue de: "<<mayor<<"°C en la posicion"<<"["<<posicion_x<<"]"<<"["<<posicion_y<<"]"<<endl;
    
}