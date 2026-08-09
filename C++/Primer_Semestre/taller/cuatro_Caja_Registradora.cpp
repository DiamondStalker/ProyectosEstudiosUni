#include <iostream>
using namespace std;
int main(){
    int opcionn, contador;
    float suma, venta;
    contador = 0;
    suma = 0;

    do
    {
        cout << "\n===MENU===\n"
             << "1. Registrar nueva venta\n"
             << "2. Mostrar total recaudado\n"
             << "3. Mostrar cantidad de ventas realizadas\n"
             << "4. Salir\n"
             << "Escoja una Opcion: ";
        cin  >> opcionn;     
switch (opcionn)
{
case 1:
    cout << "\nHaz Escogido la opcion: REGISTRAR NUEVA VENTA\n"
         << "Ingrese la venta: ";
    cin  >> venta;
    suma += venta;
    contador ++;      
    break;
case 2:
    cout << "\nHaz Escogido la opcion: MOSTRAR TOTAL RECAUDADO\n" 
         << "El total recaudado es de: $"<<suma<<endl;
         break;
case 3: 
    cout << "\nHaz Escogido la opcion: MOSTRAR CANTIDAD DE VENTAS RECAUDADAS\n"   
         << "Hubieron: "<<contador<< " ventas"<<endl;
        break;
case 4:
    cout << "Saliendo del Sistema..."<<endl;  
    break;                

default:
    cout << "Opcion No valida"<<endl;
    break;
}
    } while (opcionn != 4);
    
}