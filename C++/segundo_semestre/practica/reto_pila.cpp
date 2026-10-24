
#include<iostream>
using namespace std;

class pila {
    private:
        int cima;
        static constexpr int tam = 5;
        int datos[tam];

    public:
        pila() {
            cima = -1;
        }

        void insertar(int valor) {
            if (cima == tam - 1) {
                cout << "La pila esta llena\n";
            }
            else {
                cima++;
                datos[cima] = valor;
            }
        }

        void eliminar() {
            if (cima == -1) {
                cout << "La pila esta vacia\n";
            }
            else {
                cout << "El valor: " << datos[cima]
                     << " sera eliminado\n";
                cima--;
                cout << "Eliminado correctamente\n";
            }
        }

        void mostrar() {
            if (cima == -1) {
                cout << "\n";
                cout << "       PILA DE DATOS\n";
                cout << "   +-------------------+\n";
                cout << "   |    PILA VACIA     |\n";
                cout << "   +-------------------+\n";
            }
            else {
                cout << "\n";
                cout << "       PILA DE DATOS\n\n";

                for (int i = cima; i >= 0; i--) {
                    cout << "   +-------------------+\n";

                    if (i == cima) {
                        cout << "   |      ^ CIMA       |\n";
                        cout << "   +-------------------+\n";
                    }

                    cout << "   |        " << datos[i]
                         << "         |\n";
                }

                cout << "   +-------------------+\n";
                cout << "         FONDO\n";
            }
        }

        void buscar(int buscar) {
            for (int i = cima; i >= 0; i--) {
                if (buscar == datos[i]) {
                    cout << "Elemento encontrado en la pila: "
                         << "posicion(" << i + 1 << ")\n";
                }
            }
        }

        int getTam() {
            return tam;
        }

        int getCim() {
            return cima;
        }
};

int main() {
    pila objeto;
    int datos;
    int opcion;
    int buscar;

    cout << "=== MENU ===\n";

    do {
        cout << "\n1. INSERTAR PILA\n"
             << "2. ELIMINAR\n"
             << "3. BUSCAR\n"
             << "4. MOSTRAR PILA\n"
             << "5. SALIR\n";

        cout << "Digite la opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                for (int i = 0; i < objeto.getTam(); i++) {
                    cout << "#" << i + 1 << ": ";
                    cin >> datos;
                    objeto.insertar(datos);
                }
                break;

            case 2:
                objeto.eliminar();
                break;

            case 3:
                cout << "ELEMENTO A BUSCAR: ";
                cin >> buscar;
                objeto.buscar(buscar);
                break;

            case 4:
                objeto.mostrar();
                break;

            case 5:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "ERROR: opcion no valida\n";
                break;
        }

    } while (opcion != 5);

    return 0;
}
