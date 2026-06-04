#include<iostream>
#include<string>
using namespace std;



int main(){
    int matriz[100][100];
    int n;
    int opcion;
    int escalar;
    cout<<"Digite el tamaño de la matriz cuadrada: ";
    cin >> n;
    cout <<"Digite los elementos de la matriz: "<<endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << "Posicion ["<<i+1<<"]"<<"["<<j+1<<"]: ";
            matriz[i][j];
        }
    }

    do{
        cout << "\n===MENU===\n"
         << "1. Mostrar Matriz\n"
         <<"2. Verificar si es identidad\n"
         <<"3. Verificar si es simetrica\n"
         <<"4. Sumar todos los elementos\n"
         <<"5. Sumas diagonal principal\n"
         <<"6. Verificar si es nula\n"
         <<"7. Multiplicar por escalar\n"
         <<"8. Salir\n";
         cin >> opcion;

    }while(opcion!=8);
    return 0;
}