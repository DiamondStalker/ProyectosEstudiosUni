#include <iostream>
using namespace std;

int main(){

    char vec[100];
    int n;

    cout << "Digite la cantidad de letras de su palabra u oracion: ";
    cin >> n;

    cout << "Digite su palabra u oracion:" << endl;

    for(int i = 0; i < n; i++){
        cout << "[" << i+1 << "]: ";
        cin >> vec[i];
    }

    cout << "\nEste es su palabra antes del arreglo: ";

    for(int i = 0; i < n; i++){
        cout << vec[i];
    }

    cout << "\n\nARREGLO\n";
    cout << "Toda M sera reemplazada por L\n";
    cout << "Toda N sera reemplazada por R\n";
    cout << "MM = M y NN = N\n\n";


    for(int i = 0; i < n-1; i++){

        if((vec[i]=='M' && vec[i+1]=='M') ||
           (vec[i]=='N' && vec[i+1]=='N')){

            for(int j = i+1; j < n-1; j++){
                vec[j] = vec[j+1];
            }

            n--;
            i--;
        }
    }


    for(int i = 0; i < n; i++){

        if(vec[i]=='M'){
            vec[i]='L';
        }

        if(vec[i]=='N'){
            vec[i]='R';
        }
    }


    cout << "Despues del arreglo: ";

    for(int i = 0; i < n; i++){
        cout << vec[i];
    }

    return 0;
}