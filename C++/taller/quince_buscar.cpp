#include<iostream>
using namespace std;
int main(){
    int filas, columnas;
    int matriz[100][100];
    int buscar;
    cout << "Digite El numero de filas: ";
    cin  >> filas;
cout << "\nDigite el numero de columnas: ";
cin  >> columnas;
cout << "Digite los valores de la matriz: "<<endl;
for(int i = 0; i<filas; i++){
    for(int j = 0; j<columnas; j++){
        cout << "["<<i<<"]"<<"["<<j<<"]"<<": ";
        cin >> matriz[i][j];
    }
}

cout << "Matriz Original"<<endl;
for(int i = 0; i<filas; i++){
    for(int j= 0; j<columnas;j++){
        cout << matriz[i][j]<<" ";
    }
    cout << endl;
}
cout << "\nElemento a buscar en la matriz: ";
cin >> buscar;
bool encontrado = false;
int posicion_x;
int posicion_y;
for(int i = 0; i<filas; i++){
    for(int j = 0; j<columnas; j++){
        if(matriz[i][j]==buscar){
            encontrado = true;
            posicion_x = i;
            posicion_y = j;
            break;
        }
        break;
    }
}
if(encontrado){
    cout << "El numero ha sido encontrado en la posicion:"<<"["<<posicion_x<<"]"<<"["<<posicion_y<<"]"<<endl;
}
else {
    cout << "No fue encontrado"<<endl;
}
}
