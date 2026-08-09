#include<iostream>
using namespace std;
int main(){
float suma, promedio, calificacion;
int contador;
contador = 0;
suma = 0;
promedio = 0;
do
{
  cout << "\nCallifique desde el 1-5 (Use el -1 para salir)\n"
       << "Calificacion: ";
  cin   >> calificacion;
  if(calificacion >= 1 && calificacion <= 5){
    suma += calificacion;
    contador++;
  }
  else{
    if(calificacion != 1){
        cout<< "Calificacion Invalida"<<endl;
    }
  }
} while (calificacion != -1);

if(contador >0){
    promedio = suma / contador;
    cout << "El promedio de la calificacion es: "<<promedio<<endl;
}
else{
    cout << "No hay Calificaciones"<<endl;
}
}