#include <iostream>
using namespace std;

int main()
{

    char letras[10] = {'A', 'B', 'C', 'D', 'E'};

    int n = 5;

    int opcion;
    char letra;
    int posicion;

    do
    {

        cout << "\n===== MENU =====\n";
        cout << "1. Mostrar vector\n";
        cout << "2. Buscar letra\n";
        cout << "3. Insertar al inicio\n";
        cout << "4. Insertar al final\n";
        cout << "5. Insertar en posicion especifica\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:

            cout << "El Vector Actual es: ";

            for (int i = 0; i < n; i++)
            {
                cout << letras[i] << " ";
            }

            cout << endl;

            break;

        case 2:

            cout << "Ingrese la letra a buscar: ";
            cin >> letra;

            for (int i = 0; i < n; i++)
            {

                if (letras[i] == letra)
                {

                    cout << "La letra " << letra
                         << " se encuentra en la posicion: "
                         << i + 1 << endl;

                    break;
                }

                else if (letras[i] != letra && i == n - 1)
                {

                    cout << "La letra "
                         << letra
                         << " no se encontro" << endl;
                }
            }

            break;

        case 3:

            if (n < 10)
            {

                for (int i = n; i > 0; i--)
                {

                    letras[i] = letras[i - 1];
                }

                cout << "Ingrese la letra a insertar al inicio: ";
                cin >> letra;

                letras[0] = letra;

                n++;
            }

            else
            {

                cout << "El vector esta lleno." << endl;
            }

            break;

        case 4:

            if (n < 10)
            {

                cout << "Ingrese la letra a insertar al final: ";
                cin >> letra;

                letras[n] = letra;

                n++;
            }

            else
            {

                cout << "El vector esta lleno." << endl;
            }

            break;

        case 5:

            if (n < 10)
            {

                cout << "Ingrese la letra a insertar: ";
                cin >> letra;

                cout << "Ingrese la posicion (1-" << n + 1 << "): ";
                cin >> posicion;

                if (posicion >= 1 && posicion <= n + 1)
                {

                    for (int i = n; i >= posicion; i--)
                    {

                        letras[i] = letras[i - 1];
                    }

                    letras[posicion - 1] = letra;

                    n++;
                }

                else
                {

                    cout << "Posicion invalida." << endl;
                }
            }

            else
            {

                cout << "El vector esta lleno." << endl;
            }

            break;

        case 6:

            cout << "Saliendo del programa..." << endl;

            break;

        default:

            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 6);

    return 0;
}
