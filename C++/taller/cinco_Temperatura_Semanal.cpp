#include<iostream>
using namespace std;
int main(){
    float suma, promedio, buscar;
    int contador, diasSuperior, i;
    int temperaturas[7];
    suma = 0;
    diasSuperior = 0;

    for(i = 0; i<7; i++){
        cout << "\nIngrese la temperatura del dia "<<i + 1<<": ";
        cin >> temperaturas[i];
        suma += temperaturas[i];
    }

    promedio = suma/7;

    cout << "\n------------------------------------------\n"
         << "El promedio semanal es: "<< promedio<<endl;
    for(i=0;i<7;i++){
        if(temperaturas[i]>promedio)diasSuperior = diasSuperior +1;
    } 
    
    cout << "Dias por encima del promedio: "<< diasSuperior<<endl;

    cout << "\n------------------------------------------\n"
         << "Ingrese la temperatura que desea buscar: ";
    cin >> buscar;
    
    contador = 0;


    for(i = 0; i<7; i++){
        if(temperaturas[i] == buscar){
            cout << "La temperatura fue encontrada en el dia "<<i+1;
            contador = contador +1;
        }
    }

    if(contador == 0) cout << "la tepmeratura no fue encontrada"<<endl;




}