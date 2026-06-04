#include<iostream>
using namespace std;
int main(){
    int filas, columnas;
    int matriz[100][100];
    int mult;
    int menor, mayor;
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
mayor = matriz[0][0];
menor = matriz[0][0];

for(int i = 0; i<filas; i++){
    for(int j = 0; j<columnas;j++){
        if(matriz[i][j]>mayor)mayor = matriz[i][j];
        if(matriz[i][j]<menor)menor = matriz[i][j];
    }
}

cout << "El Numero mayor de la matriz es: "<<mayor<<endl;
cout << "El Numero menor de la mtriz es: "<<menor<<endl;
return 0;
}