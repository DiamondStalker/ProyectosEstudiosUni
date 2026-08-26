#include <iostream>
using namespace std;

class Cmatriz {
public:
    int matriz[3][3];
    int suma;
    int multiplicar;

    
    Cmatriz() {

        suma = 0;
        multiplicar = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matriz[i][j] = 0;
            }
        }
    }

 
    void pedir() {
        cout << "Ingrese los datos de la matriz" << endl;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "[" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
        }
    }

    
    void mostrar() {
        for (int i = 0; i < 3; i++) {
            cout << endl;

            for (int j = 0; j < 3; j++) {
                cout << matriz[i][j] << " ";
            }
        }

        cout << endl;
    }


    int sumar() {

        suma = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                suma += matriz[i][j];
            }
        }

        return suma;
    }

    
    void multi() {

        cout << "Digite un numero a multiplicar: ";
        cin >> multiplicar;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matriz[i][j] = matriz[i][j] * multiplicar;
            }
        }
    }
};

int main() {

    int opcion;

    Cmatriz obj;

    do {
        cout << endl;
        cout << "=== MENU ===" << endl;
        cout << "1. Ingresar los valores de la matriz" << endl;
        cout << "2. Imprimir la matriz" << endl;
        cout << "3. Calcular y mostrar la suma de todos los elementos" << endl;
        cout << "4. Multiplicar la matriz por un numero" << endl;
        cout << "5. Salir" << endl;
        cout << "Indique una opcion: ";

        cin >> opcion;

        switch (opcion) {

        case 1:
            cout << "Haz ingresado a la opcion 1:" << endl;
            obj.pedir();
            break;

        case 2:
            cout << "Haz ingresado a la opcion 2:" << endl;
            obj.mostrar();
            break;

        case 3:
            cout << "Haz ingresado a la opcion 3:" << endl;
            cout << "La suma es: " << obj.sumar() << endl;
            break;

        case 4:
            cout << "Haz ingresado a la opcion 4:" << endl;
            obj.multi();
            break;

        case 5:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    } while (opcion != 5);

    return 0;
}