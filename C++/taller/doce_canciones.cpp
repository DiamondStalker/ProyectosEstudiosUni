#include <iostream>
#include <string>

using namespace std;

int main() {

    string canciones[20];
    string buscar, nueva;
    int opcion;

    canciones[0] = "Lola - Jedis";
    canciones[1] = "Manifiestate - Dani y Magneto";
    canciones[2] = "Perreo en la Disco - Los Farandulay";
    canciones[3] = "Cuidado - Hector el Father";
    canciones[4] = "Sacala - Daddy Yankee";

    do {

        cout << "\n=== MENU ===\n";
        cout << "1. Mostrar Canciones Favoritas\n";
        cout << "2. Buscar Cancion\n";
        cout << "3. Agregar Cancion\n";
        cout << "4. Salir\n";
        cout << "Escoja una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {

        case 1:

            cout << "\nHA INGRESADO A LA OPCION 1: Mostrar Canciones Favoritas\n";

            for (int i = 0; i < 20; i++) {
                if (canciones[i] != "") {
                    cout << "Fav " << i + 1 << ": " << canciones[i] << endl;
                }
            }

            break;

        case 2: {

            cout << "\nHA INGRESADO A LA OPCION 2: Buscar Cancion\n";
            cout << "Nombre a buscar: ";
            getline(cin, buscar);

            bool encontrado = false;

            for (int i = 0; i < 20; i++) {
                if (canciones[i] == buscar) {
                    encontrado = true;
                    break;
                }
            }

            if (encontrado) {
                cout << "La cancion esta en tus favoritos.\n";
            }
            else {
                cout << "La cancion no se encontro en tus favoritos.\n";
            }

            break;
        }

        case 3:

            cout << "\nHA INGRESADO A LA OPCION 3: Agregar Cancion\n";
            cout << "Ingrese la cancion (Nombre - Autor): ";
            getline(cin, nueva);

            for (int i = 18; i >= 0; i--) {
                canciones[i + 1] = canciones[i];
            }

            canciones[0] = nueva;

            cout << "Cancion agregada correctamente.\n";

            break;

        case 4:

            cout << "Saliendo del programa...\n";
            break;

        default:

            cout << "Opcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}