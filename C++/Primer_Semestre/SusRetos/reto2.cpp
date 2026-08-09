#include <iostream>
using namespace std;

int main(){

    int n;
    int a = 0, b = 1, c;

    cout << "Digite el numero de Fibonacci: ";
    cin >> n;

    if(n == 1){
        cout << "Resultado: 1";
    }
    else if(n == 2){
        cout << "Resultado: 2";
    }
    else{

        a = 1;
        b = 2;

        for(int i = 3; i <= n; i++){
            c = a + b;
            a = b;
            b = c;
        }

        cout << "Resultado: " << b;
    }

    return 0;
}