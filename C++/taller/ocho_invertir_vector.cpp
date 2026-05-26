#include<iostream>
using namespace std;

int main(){

    int n, i, j;

    cout << "Digite la cantidad de elementos: ";
    cin >> n;

    int s[100];
    int invertido[100];

    
    for(i = 0; i < n; i++){
        cout << "Digite el elemento " << i + 1 << ": ";
        cin >> s[i];
    }

   
    j = n - 1;

    for(i = 0; i < n; i++){
        invertido[i] = s[j];
        j--;
    }

    
    cout << "\nVector original:\n";

    for(i = 0; i < n; i++){
        cout << s[i] << " ";
    }

    
    cout << "\nVector invertido:\n";

    for(i = 0; i < n; i++){
        cout << invertido[i] << " ";
    }

    return 0;
}