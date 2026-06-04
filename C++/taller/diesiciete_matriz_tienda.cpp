#include<iostream>
using namespace std;
int main(){
int tienda[3][5];
int suma1=0;
int suma2=0;
int suma3=0;
int suma4=0;
int suma5=0;
cout << "Digite productos vendidos: "<<endl;
for(int i = 0; i<3; i++){
    for(int j = 0; j<5; j++){
        cout << "Dia: "<<j+1<<", Producto #"<<i+1<<": ";
        cin >> tienda[i][j];
    }
}
for(int i = 0; i<3; i++){
    suma1 += tienda[i][0];
}
for(int i = 0; i<3; i++){
    suma2 += tienda[i][1];
}
for(int i = 0; i<3; i++){
    suma3 += tienda[i][2];
}
for(int i = 0; i<3; i++){
    suma4 += tienda[i][3];
}
for(int i = 0; i<3; i++){
    suma5 += tienda[i][4];
}
cout << "El dia uno recaudo: $"<<suma1<<endl;
cout << "El dia dos recaudo: $"<<suma2<<endl;
cout << "El dia tres recaudo: $"<<suma3<<endl;
cout << "El dia cuatro recaudo: $"<<suma4<<endl;
cout << "El dia cinco recaudo: $"<<suma5<<endl;
suma1=0;
suma2=0;
suma3=0;
for(int i = 0; i<3; i++){
    suma1 += tienda[0][i];
}
for(int i = 0; i<3; i++){
    suma2 += tienda[1][i];
}
for(int i = 0; i<3; i++){
    suma3 += tienda[2][i];
}
cout << "El producto uno recaudo: $"<<suma1<<endl;
cout << "El producto dos recaudo: $"<<suma2<<endl;
cout << "El producto tres recaudo: $"<<suma3<<endl;
}