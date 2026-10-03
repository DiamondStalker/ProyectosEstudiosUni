#include<iostream>
using namespace std;
class RegistroVentas{
protected:
    float arreglo[10];
    int n = 10;
    float promedio;
    int contador;
    float menor;
public:
    RegistroVentas(){
        for(int i = 0; i<n; i++){
            arreglo[i]= 0;
        }
        contador = 0;
        promedio = 0;
    }    
void Ingreso(int dato){
    if (contador<n)
    {
        arreglo[contador] = dato;
        contador++;
    }
    
}

void Mostrardatos(){
    cout << "===Ventas==="<<endl;
    for(int i = 0; i<n; i++){
        cout << "Dia #"<<i+1<<"Venta Total: "<<arreglo[i];
         cout << endl;
    }
    cout << endl;
}

virtual void datos(){
    menor = arreglo[0];
    for(int i = 0; i<n;i++){
        promedio+= arreglo[i];
        
    }

    cout << "\nLa suma de Ventas durante los 10 dias fue: "<<promedio;
    cout << "\nEl promedio de venta fue de: "<<promedio/n;
}



};

class AnalisisVentas: public RegistroVentas{
protected:
    float mayor;
    float menor;
    int n;
public:
    AnalisisVentas(){
        mayor = 0.0;
        n = 10;
        menor = RegistroVentas::menor;

    }
    
    
   void datos(){
    
    for(int i = 0; i<n; i++){
        if(arreglo[i]>mayor)mayor=arreglo[i];
        if(arreglo[i]<menor)menor=arreglo[i];
    }

    cout << "\nLa venta mayor fue de: "<<mayor<<endl;
    cout << "\nLa venta menor fue de: "<<menor<<endl;
   } 
};

int main(){
    int n = 10;
    float dato;

    RegistroVentas uno;
    AnalisisVentas Dos;
    cout << "\nINGRESE LAS VENTAS"<<endl;
    for(int i = 0; i<n; i++){
        cout << "Ingrese la venta Total del dia #"<<i+1<<": ";
        cin >> dato;
        uno.Ingreso(dato);
        Dos.Ingreso(dato);
        
    }
    cout << "\nArreglo: "<<endl;
    uno.Mostrardatos();
    cout << "\nDatos Basicos: "<<endl;
    uno.datos();
    cout << "\nDatos Avanzados: "<<endl;
    Dos.datos();


return 0;


}