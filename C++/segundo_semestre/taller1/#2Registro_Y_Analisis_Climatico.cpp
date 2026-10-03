#include<iostream>
using namespace std;
class RegistroTemperaturas{
    private:
        int arreglo[7];
        float promedio;
        int contador;
        int mayor;
        int menor;
        int n = 7;


    public:

    RegistroTemperaturas(){
        for(int i = 0; i<n; i++)
        {
            arreglo[i]= 0;

        } 
        mayor = 0;
        contador = 0;
        promedio = 0;
    }

    void setAgregar(int temperaturas){
        if(contador < n){
            arreglo[contador] = temperaturas;
            contador++;
        }
        else cout << "Lleno"<<endl;


    }

    void mostrar(){
        cout << "Registro de la semana"<<endl;
        for(int i = 0; i<n;i++){
            cout << arreglo[i] << "°C ";
        }
        cout << endl;
    }

    void datos(){
        menor = arreglo[0];
        for(int i = 0; i<n; i++){
            promedio += arreglo[i];
            if(arreglo[i]>mayor)mayor = arreglo[i];
            if(arreglo[i]<menor)menor= arreglo[i];

        }
        
    cout << "La temperatura mas baja fue de: "<< menor << "°C"<<endl;
    cout << "La tempratura mas alta fue de: "<<mayor << "°C"<<endl;
    }
    float getPromedio(){
        return promedio/n;
    }
           

};

class AnalisisClimatico: public RegistroTemperaturas{
    public:
        
    void datosF(){
        cout << "Analisis Climatico"<<endl;

        RegistroTemperaturas::datos();

        cout << "La Media de las temperaturas es: " <<getPromedio()<<endl;
    }
        
    
};

int main(){
    int dato;
    int n = 7;
    RegistroTemperaturas inicio;
    AnalisisClimatico Analisis;
    cout << "REGISTRE LOS DATOS: "<<endl;
    for(int i = 0; i<n; i++){
        cout << "Dato #"<<i+1<<": ";
        cin >> dato;
        Analisis.setAgregar(dato);

    }
    Analisis.mostrar();
    Analisis.datosF();
    return 0;

    }