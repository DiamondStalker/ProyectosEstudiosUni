#include <iostream>
using namespace std;

int main(){

    char vec[100];
    int n;
    bool palindromo = true;

    cout << "Digite la cantidad de letras: ";
    cin >> n;

    cout << "Digite la palabra: ";

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }


    for(int i = 0; i < n/2; i++){

        if(vec[i] != vec[n-1-i]){
            palindromo = false;
        }

    }


    if(palindromo){
        cout << "Es palindromo";
    }
    else{
        cout << "No es palindromo";
    }


    return 0;
}