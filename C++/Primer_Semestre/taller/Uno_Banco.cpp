#include <iostream>
using namespace std;
int main(){
 float retiro;
 int opcionn;
 float saldo = 500000;
 do
 {
    cout << "\n===MENU===\n";
    cout << "Saldo actual: "<< saldo;
    cout << "\n0. Salir\n"
         << "1. Retirar\n"
         << "Escoja la Opcion: ";
    cin >> opcionn; 
    
    switch (opcionn)
    {
    case 0:
     cout << "Gracias por usar el cajero"<<endl;
     break;
     case 1:
     cout << "Ingrese el valor a retirar: ";
     cin >> retiro;
     
     if(retiro <= saldo){
          saldo = saldo - retiro;
          cout << "Retiro Exitoso\n"
               << "Saldo restante: "<< saldo;
     }
     else{
          cout << "Saldo insuficiente"<<endl;
     }

     break;
    
    default:
    cout << "Opcion Invalida"<<endl;

     break;
    }
 } while (opcionn != 0 && saldo > 0);
 

}