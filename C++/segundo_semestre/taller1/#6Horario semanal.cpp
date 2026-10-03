#include<iostream>
#include<string>
using namespace std;
int main(){
    string horario[6][5];
    int filas = 6;
    int columnas = 5;
    cout << "CREAR HORARIO"<<endl;
    cout << "Ingrese las asignaturas"<<endl;
    for(int i = 0;i<filas;i++){
        for(int j = 0; j<columnas;j++){
            cout << "Dia #"<<i+1<<", Hora #"<<j+1<<": ";
            cin >> horario[i][j];
        }
    }
    cout << "===HORARIO==="<<endl;
    cout <<"          "<< "Lunes"<<"     "<<"Martes"<<"      "<<"Miercoles"<<"  "<<"Jueves"<<"     "<<"Viernes"<<endl;
    for(int i = 0; i<filas; i++){
        cout << "Hora"<<i+1;
        for(int j = 0; j<columnas;j++){
            cout << "     "<<horario[i][j]<<"     ";
        }
        cout << endl;
    }    

}
