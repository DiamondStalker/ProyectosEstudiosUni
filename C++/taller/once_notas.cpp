#include<iostream>
using namespace std;

const int n = 6;
int main(){
    
    int aprobaron;
    float mayor, menor;
    int dondeMayor, dondeMenor;
    aprobaron = 0;
    float notas[n];
    cout << "\nDigite las notas finales de los "<<n<< " Estudiantes: \n";
    for(int i = 0; i<n; i++){
        cout << "Estudiante: "<<i+1<<": ";
        cin >> notas[i];
    }

    mayor = notas[0];
    menor = notas[0];
    dondeMayor = 1;
    dondeMenor = 1;
    for(int i = 0; i<n; i++){
        if(notas[i]>mayor){
            mayor = notas[i];
            dondeMayor = i+1;
        }
        if(notas[i]<menor){
            menor = notas[i];
            dondeMenor = i+1;
        }
        if(notas[i]>=3)aprobaron++;
    }
    cout << "La nota mayor es: "<<mayor<<endl;
    cout << "Del estudiante: "<<dondeMayor<<endl;
    cout << "la nota menor es: "<<menor<<endl;
    cout << "Del estudiante: "<<dondeMenor<<endl;
    cout << "Aprobaron: "<<aprobaron<< " Estudiantes"<<endl;
}