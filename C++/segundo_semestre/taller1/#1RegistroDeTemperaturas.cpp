#include<iostream>
using namespace std;
class temperaturas{
private:
    int arreglo[7];
    int n = 7;
    int contador;
    float promedio;
    int mayor;
    int menor;
public:
    temperaturas(){
        for(int i = 0; i<n; i++){

            arreglo[i] = 0;

        }
        contador = 0;
        promedio = 0;
        mayor = 0;
        
    }
void registrarDatos(int dato){
    if(contador < n){
        arreglo[contador] = dato;
        contador++;
    }
    else cout << "Los datos estan llenos"<<endl;

}
void mostrar(){
    cout << "===TEMPERATURAS==="<<endl;
    for(int i = 0; i<n; i++){
        cout << arreglo[i]<<" °C"<<" ";
    }
    cout << endl;
}
void datosImpo(){
    menor = arreglo[0];
    for(int i = 0; i<n; i++){
        promedio += arreglo[i];
        if(arreglo[i]>mayor)mayor = arreglo[i];
        if(arreglo[i]<menor)menor = arreglo[i];
        
    }



    promedio /= n;
    cout << "La media de las temperaturas es: "<< promedio << "°C"<<endl;
    cout << "La temperatura mas baja fue de: "<< menor << "°C"<<endl;
    cout << "La tempratura mas alta fue de: "<<mayor << "°C"<<endl;
}
};

int main(){
    int n = 7;
    int temperaturass;
    temperaturas arregloTemps;
    cout << "Registre las temperaturas de la semana: "<<endl;
    for(int i = 0; i<n; i++){
        cout << "Dato #"<<i+1<<": ";
        cin >> temperaturass;
        arregloTemps.registrarDatos(temperaturass);
    }
    arregloTemps.mostrar();
    arregloTemps.datosImpo();
    return 0;
}