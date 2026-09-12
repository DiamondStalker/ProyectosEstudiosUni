#include <iostream>
using namespace std;

class nodo {
public:
    int dato;
    nodo* siguiente;

    nodo(int valor) {
        dato = valor;
        siguiente = nullptr;
    }
};

class lista {
private:
    nodo* cabeza;

public:
    lista() {
        cabeza = nullptr;
    }

    void insertarMenorMayor(int valor) {
        nodo* nuevoNodo = new nodo(valor);

        if (cabeza == nullptr || valor < cabeza->dato) {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        }
        else {
            nodo* temp = cabeza;

            while (temp->siguiente != nullptr &&
                   temp->siguiente->dato < valor) {
                temp = temp->siguiente;
            }

            nuevoNodo->siguiente = temp->siguiente;
            temp->siguiente = nuevoNodo;
        }
    }

    void insertarMayorMenor(int valor) {
        nodo* nuevoNodo = new nodo(valor);

        if (cabeza == nullptr || valor > cabeza->dato) {
            nuevoNodo->siguiente = cabeza;
            cabeza = nuevoNodo;
        }
        else {
            nodo* temp = cabeza;

            while (temp->siguiente != nullptr &&
                   temp->siguiente->dato > valor) {
                temp = temp->siguiente;
            }

            nuevoNodo->siguiente = temp->siguiente;
            temp->siguiente = nuevoNodo;
        }
    }

    void mostrarDatos() {
        nodo* temp = cabeza;

        while (temp != nullptr) {
            cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }

        cout << "NULL" << endl;
    }

    int cantidadElementos() {
        nodo* temp = cabeza;
        int cantidad = 0;

        while (temp != nullptr) {
            cantidad++;
            temp = temp->siguiente;
        }

        return cantidad;
    }

    float promedio() {
        if (cabeza == nullptr) {
            return 0;
        }

        nodo* temp = cabeza;
        int suma = 0;

        while (temp != nullptr) {
            suma += temp->dato;
            temp = temp->siguiente;
        }

        return (float)suma / cantidadElementos();
    }

    void pedirDatos(lista &mayorMenor) {
        int valor;
        char continuar;

        do {
            cout << "Ingrese el elemento: ";
            cin >> valor;

            insertarMenorMayor(valor);
            mayorMenor.insertarMayorMenor(valor);

            cout << "Desea ingresar otro elemento? (s/n): ";
            cin >> continuar;

        } while (continuar == 's' || continuar == 'S');
    }
};

int main() {
    lista menorMayor;
    lista mayorMenor;

    menorMayor.pedirDatos(mayorMenor);

    cout << endl;

    cout << "Lista de menor a mayor:" << endl;
    menorMayor.mostrarDatos();

    cout << endl;

    cout << "Lista de mayor a menor:" << endl;
    mayorMenor.mostrarDatos();

    cout << endl;

    cout << "Cantidad de elementos: "
         << menorMayor.cantidadElementos() << endl;

    cout << "Promedio: "
         << menorMayor.promedio() << endl;

    return 0;
}

