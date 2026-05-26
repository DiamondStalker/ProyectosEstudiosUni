#include<iostream>
using namespace std;

int main(){

    int i,j,k;
    int java[5];
    int c[5];
    int ambas[5];

    k = 0;

    cout << "\nCodigos de estudiantes que perdieron Lenguaje C\n";

    for(i=0; i < 5; i++){
        cout << "Digite el codigo #" << i + 1 << ": ";
        cin >> c[i];
    }

    cout << "\nCodigos de estudiantes que perdieron Lenguaje Java\n";

    for(i=0; i < 5; i++){
        cout << "Digite el codigo #" << i + 1 << ": ";
        cin >> java[i];
    }


    for(i=0; i<5; i++){
        for(j=0; j<5; j++){

            if(c[i] == java[j]){
                ambas[k] = c[i];
                k++;
            }

        }
    }

    cout << "\nEstudiantes que perdieron ambas materias:\n";

    if(k == 0){
        cout << "No hay estudiantes repetidos" << endl;
    }
    else{

        for(i=0; i<k; i++){
            cout << "\nEstudiante #" << i+1 << ": " << ambas[i];
        }

    }

    return 0;
}