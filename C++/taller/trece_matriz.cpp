#include<iostream>
using namespace std;
int main(){
    int filas, columnas;
    int matriz[100][100];
    int mult;
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
cout << "\nCantidad a multiplicar: ";
cin >> mult;
for(int i = 0; i<filas; i++){
    for(int j=0; j<columnas; j++){
        matriz[i][j] = matriz[i][j] * mult;
    }
}
for(int i = 0; i<filas; i++){
    for(int j = 0; j<columnas; j++){
        cout << matriz[i][j]<<" ";
    }
    cout << endl;
}
return 0;
}
