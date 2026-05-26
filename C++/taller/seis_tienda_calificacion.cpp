#include<iostream>
using namespace std;
int main(){
float promedio, suma;
int contador, calificacionn;
int i;
int valores[10];
promedio = 0;
suma = 0;
contador = 0;
for(i = 0; i <10; i++){
 cout << "\nCliente: "<< i+1 <<",Digite su calificacion del 1-5: ";
 cin >> calificacionn;
 if(calificacionn>=1 && calificacionn <= 5){
    valores[i] = calificacionn;
 }
 else{
    cout<<"\nNumero invalido\n";
 }

}

for(i=0;i<10;i++){
    suma += valores[i];
}
promedio = suma / 10;
for(i=0;i<10;i++){
    if(5==valores[i])contador++;
}

cout << "Nivel de satisfaccion: "<<endl;
for(i=0;i<10;i++){
    cout<< "Cliente: "<< i + 1<<"Calificacion: "<< valores[i]<<"\n";

}
cout << "El promedio es de: "<<promedio<< endl;
cout << contador << " personas pusieron 5 como maxima satisfaccion"<<endl;



}