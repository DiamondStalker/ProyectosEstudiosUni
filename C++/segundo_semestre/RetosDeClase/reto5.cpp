#include <iostream>
#include <string>
using namespace std;

class nodo {
public:
    string nombre;
    nodo* anterior;
    nodo* siguiente;

    nodo(string nombreInv) {
        nombre = nombreInv;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

class listaDoble {
private:
    nodo* cabeza;
    nodo* cola;

public:
    listaDoble() {
        cabeza = nullptr;
        cola = nullptr;
    }

    void registrarInvitado(string nombreInv) {
        nodo* nuevoNodo = new nodo(nombreInv);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else {
            nuevoNodo->anterior = cola;
            cola->siguiente = nuevoNodo;
            cola = nuevoNodo;
        }
    }

    void mostrarDesdeInicio() {
        cout << "\nLista de inicio a fin: ";

        nodo* temp = cabeza;

        while (temp != nullptr) {
            cout << temp->nombre << "<->";
            temp = temp->siguiente;
        }

        cout << "NULL" << endl;
    }

    void mostrarDesdeFinal() {
        nodo* actual = cola;

        if (actual == nullptr) {
            cout << "No hay invitados registrados." << endl;
            return;
        }

        cout << "\nLista de final a inicio: ";

        while (actual != nullptr) {
            cout << actual->nombre << "<->";
            actual = actual->anterior;
        }

        cout << "NULL" << endl;
    }

    void buscarInvitado(string nombreBuscado) {
        nodo* actual = cabeza;

        while (actual != nullptr) {
            if (actual->nombre == nombreBuscado) {
                cout << "\nEl invitado " << nombreBuscado
                     << " si esta registrado." << endl;
                return;
            }

            actual = actual->siguiente;
        }

        cout << "\nEl invitado " << nombreBuscado
             << " no esta registrado." << endl;
    }
};

int main() {
    listaDoble invitados;
    int opcion;
    string nombre;
    char continuar;

    do {
        cout << "\n";
        cout << "╔══════════════════════════════════════╗" << endl;
        cout << "║          LISTA DE INVITADOS          ║" << endl;
        cout << "╠══════════════════════════════════════╣" << endl;
        cout << "║                                      ║" << endl;
        cout << "║       [1] Registrar invitado         ║" << endl;
        cout << "║       [2] Mostrar desde el inicio    ║" << endl;
        cout << "║       [3] Mostrar desde el final     ║" << endl;
        cout << "║       [4] Buscar invitado            ║" << endl;
        cout << "║       [5] Salir                      ║" << endl;
        cout << "║                                      ║" << endl;
        cout << "╚══════════════════════════════════════╝" << endl;

        cout << "\n        ► Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {

            case 1:

                do {
                    cout << "\nIngrese el nombre del invitado: ";
                    getline(cin, nombre);

                    invitados.registrarInvitado(nombre);

                    cout << "Desea agregar otro invitado? (s/n): ";
                    cin >> continuar;
                    cin.ignore();

                } while (continuar == 's' || continuar == 'S');

                break;

            case 2:

                invitados.mostrarDesdeInicio();

                break;

            case 3:

                invitados.mostrarDesdeFinal();

                break;

            case 4:

                cout << "\nIngrese el nombre que desea buscar: ";
                getline(cin, nombre);

                invitados.buscarInvitado(nombre);

                break;

            case 5:

                cout << "\nPrograma finalizado." << endl;

                break;

            default:

                cout << "\nOpcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;
}