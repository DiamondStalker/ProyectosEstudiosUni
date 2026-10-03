
#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
    string dato;
    Nodo* anterior;
    Nodo* siguiente;

    Nodo(string nombre) {
        dato = nombre;
        anterior = nullptr;
        siguiente = nullptr;
    }
};

class Lista {
private:
    Nodo* primero;
    Nodo* ultimo;

public:
    Lista() {
        primero = nullptr;
        ultimo = nullptr;
    }

    void agregar(string nombre) {
        Nodo* nuevo = new Nodo(nombre);

        if (primero == nullptr) {
            primero = nuevo;
            ultimo = nuevo;
        }
        else {
            nuevo->anterior = ultimo;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    void mostrarInicio() {
        cout << "\nLista de inicio a fin: ";

        Nodo* actual = primero;

        while (actual != nullptr) {
            cout << actual->dato << " <-> ";
            actual = actual->siguiente;
        }

        cout << "NULL" << endl;
    }

    void mostrarFinal() {
        Nodo* actual = ultimo;

        if (actual == nullptr) {
            cout << "\nNo hay invitados registrados." << endl;
            return;
        }

        cout << "\nLista de final a inicio: ";

        while (actual != nullptr) {
            cout << actual->dato << " <-> ";
            actual = actual->anterior;
        }

        cout << "NULL" << endl;
    }

    void buscar(string nombre) {
        Nodo* actual = primero;

        while (actual != nullptr) {
            if (actual->dato == nombre) {
                cout << "\nEl invitado " << nombre
                     << " si esta registrado." << endl;
                return;
            }

            actual = actual->siguiente;
        }

        cout << "\nEl invitado " << nombre
             << " no esta registrado." << endl;
    }
};

int main() {
    Lista invitados;

    int opcion;
    string nombre;
    char respuesta;

    do {
        cout << "\nMENU" << endl;
        cout << "1. Registrar invitado" << endl;
        cout << "2. Mostrar lista de inicio a fin" << endl;
        cout << "3. Mostrar lista de final a inicio" << endl;
        cout << "4. Buscar invitado" << endl;
        cout << "5. Salir" << endl;

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {

        case 1:

            do {
                cout << "\nIngrese el nombre del invitado: ";
                getline(cin, nombre);

                invitados.agregar(nombre);

                cout << "Desea agregar otro invitado? (s/n): ";
                cin >> respuesta;
                cin.ignore();

            } while (respuesta == 's' || respuesta == 'S');

            break;

        case 2:

            invitados.mostrarInicio();

            break;

        case 3:

            invitados.mostrarFinal();

            break;

        case 4:

            cout << "\nIngrese el nombre que desea buscar: ";
            getline(cin, nombre);

            invitados.buscar(nombre);

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

