#include<iostream>
using namespace std;
int main(){
int pares, impares, positivos, negativos;
int vector[50];
pares = 0;
impares = 0;
positivos = 0;
negativos = 0;
cout << "\nDigite los valores del vector\n";
for(int i = 0; i<50; i++){
    cout << "Posicion "<<i+1<<" Valor: ";
    cin >> vector[i];
}
for(int i = 0; i<50; i++){
    if(vector[i]%2==0){

        pares++;

    }
    else{
        impares++;
    }
}

for(int i = 0; i <50; i++){
    if(vector[i]>0){
        positivos++;
    }

    else{
        if(vector[i]<0)negativos++;
    }
}
cout << "Hay: "<<pares<<" Pares"<<endl;
cout << "Hay: "<<impares<<" Pares"<<endl;
cout << "Hay: "<<positivos<<" positivos"<<endl;
cout << "Hay: "<<negativos<<" negativos"<<endl;

}