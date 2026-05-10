#include <iostream>
using namespace std;
int main(){
    int n = 5;
    char letras[10] = {'A','B','C','D','E'};
    int opcion;
    char letra;
    int posicion;
    int i;

    do
    {
        cout << "\n==========MENU==========\n"
             << "1. Mostrar Vector\n"
             << "2. Buscar letra\n"
             << "3. Insertar elemento al inicio\n"
             << "4. Insertar elemento al final\n"
             << "5. Insertar elemento en posicion especifica\n"
             << "6. Salir del programa\n"
             << "\nIngrese la Opcion: ";
        cin >> opcion;

        switch(opcion){

        case 1:
            cout << "haz Ingresado a la opcion 1\n"
                 << "\nEl Vector actual es: ";
            for(i = 0; i < n; i++){
                cout << letras[i] << " ";
            }
            cout << endl;
            break;

        case 2:
            cout << "haz Ingresado a la opcion 2\n"
                 << "Ingrese la letra a buscar: ";
            cin >> letra;
            {
                bool encontrada = false;
                for(int i = 0; i < n; i++)
                {
                    if(letras[i] == letra)
                    {
                        cout << "La letra " << letra
                             << " se encuentra en la posicion: "
                             << i + 1 << endl;
                        encontrada = true;
                        break;
                    }
                }
                if(!encontrada)
                {
                    cout << "La letra " << letra
                         << " no se encontro" << endl;
                }
            }
            break;

        case 3:
            cout << "Haz Ingresado a la opcion 3\n"
                 << "Insertar elemento Al Inicio\n"
                 << "Que letra desea Agregar: ";
            cin >> letra;

            if(n < 10){
                for(i = n; i > 0; i--){
                    letras[i] = letras[i-1];
                }
                letras[0] = letra;
                n++;
            } else {
                cout << "Conjunto lleno" << endl;
            }
            break;

        case 4:
            cout << "Haz Ingresado a la opcion 4\n"
                 << "Insertar elemento Al Final\n"
                 << "Que letra desea Agregar: ";
            cin >> letra;

            if(n < 10){
                letras[n] = letra;
                n++;
                cout << "Letra insertada al final." << endl;
            } else {
                cout << "Conjunto lleno" << endl;
            }
            break;

        case 5:
            cout << "Haz Ingresado a la opcion 5\n"
                 << "Insertar elemento en posicion especifica\n"
                 << "Que letra desea Agregar: ";
            cin >> letra;
            cout << "Ingrese la posicion (1-" << n + 1 << "): ";
            cin >> posicion;

            if(n < 10){
                if(posicion >= 1 && posicion <= n + 1){
                    for(i = n; i >= posicion; i--){
                        letras[i-1] = letras[i];
                    }
                    letras[posicion - 1] = letra;
                    n++;
                } else {
                    cout << "Posicion invalida." << endl;
                }
            } else {
                cout << "Conjunto lleno" << endl;
            }
            break;

        case 6:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
        }

    } while(opcion != 6);

    return 0;
}