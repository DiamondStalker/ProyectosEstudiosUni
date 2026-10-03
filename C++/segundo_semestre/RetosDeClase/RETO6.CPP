#include<iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo *siguiente;

    Nodo(int valor) {
        dato = valor;
        siguiente = NULL;
    }
};

class ListaCircular {
private:
    Nodo *cabeza;
    Nodo *ultimo;

public:

    ListaCircular() {
        cabeza = NULL;
        ultimo = NULL;
    }

    void insertarI(int valor) {
        Nodo* nuevo = new Nodo(valor);

        if(cabeza == NULL) {
            cabeza = nuevo;
            ultimo = nuevo;
            ultimo->siguiente = cabeza;
        }
        else {
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
            ultimo->siguiente = cabeza;
        }
    }

    void insertar(int valor) {

        Nodo *nuevo = new Nodo(valor);

        if(cabeza == NULL) {
            cabeza = nuevo;
            ultimo = nuevo;
            ultimo->siguiente = cabeza;
        }
        else {
            nuevo->siguiente = cabeza;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    void mostrar() {

        if(cabeza == NULL) {
            cout << "La lista esta vacia." << endl;
            return;
        }

        Nodo *temp = cabeza;

        do {
            cout << temp->dato<< "->";
            temp = temp->siguiente;

        } while(temp != cabeza);
        cout<<"Cabeza";
    }

    void buscar(int valor) {

        if(cabeza == NULL) {
            cout << "La lista esta vacia." << endl;
            return;
        }

        Nodo *temp = cabeza;

        do {
            if(temp->dato == valor) {
                cout << "Elemento encontrado." << endl;
                return;
            }

            temp = temp->siguiente;

        } while(temp != cabeza);

        cout << "Elemento no encontrado." << endl;
    }

void eliminar(int valor) {

    if(cabeza == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    Nodo *actual = cabeza;
    Nodo *anterior = ultimo;

    do {

        if(actual->dato == valor) {

            if(cabeza == ultimo) {

                cabeza = nullptr;
                ultimo = nullptr;
            }
            else if(actual == cabeza) {

                cabeza = cabeza->siguiente;
                ultimo->siguiente = cabeza;
            }
            else if(actual == ultimo) {

                ultimo = anterior;
                ultimo->siguiente = cabeza;
            }
            else {

                anterior->siguiente = actual->siguiente;
            }

            delete actual;

            cout << "Elemento eliminado correctamente." << endl;
            return;
        }

        anterior = actual;
        actual = actual->siguiente;

    } while(actual != cabeza);

    cout << "Elemento no encontrado." << endl;
}
};

int main() {

    ListaCircular lista;

    int opcion;
    int valor;
    bool ya;
    int val;
    ya = true;
    char que;

    do {

        cout << "\n========== TIENDA ==========\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar lista\n";
        cout << "4. Buscar elemento\n";
        cout << "5. Eliminar elemento\n";
        cout << "6. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

        case 1:

            do {

                cout << "Insertando valor al inicio" << endl;
                cout << "\nDigite el valor: ";
                cin >> valor;

                lista.insertarI(valor);

                cout << "\nDesea agregar otro valor? (S/N): ";
                cin >> que;

                if(que == 's' || que == 'S')
                    ya = true;
                else
                    ya = false;

            } while(ya);

            break;

        case 2:

            do {

                cout << "Insertando valor al final" << endl;
                cout << "\nDigite el valor: ";
                cin >> valor;

                lista.insertar(valor);

                cout << "\nDesea agregar otro valor? (S/N): ";
                cin >> que;

                if(que == 's' || que == 'S')
                    ya = true;
                else
                    ya = false;

            } while(ya);

            break;

        case 3:

            lista.mostrar();

            break;

        case 4:

            cout << "\nQue valor desea buscar: ";
            cin >> val;

            lista.buscar(val);

            break;

        case 5:

            cout << "\nQue valor desea eliminar: ";
            cin >> val;

            lista.eliminar(val);

            break;

        case 6:

            cout << "\nSaliendo...";
            break;

        default:

            cout << "\nOpcion invalida." << endl;
            break;
        }

    } while(opcion != 6);

    return 0;
}