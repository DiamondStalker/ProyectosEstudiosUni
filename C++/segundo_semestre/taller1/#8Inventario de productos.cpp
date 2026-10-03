
#include<iostream>
#include<string>
using namespace std;


class Nodo {
private:
    int codigo;
    string nombre;
    float precio;
    Nodo* siguiente;

public:

    
    Nodo(int cod, string nom, float pre) {
        codigo = cod;
        nombre = nom;
        precio = pre;
        siguiente = nullptr;
    }

    
    int getCodigo() {
        return codigo;
    }

    string getNombre() {
        return nombre;
    }

    float getPrecio() {
        return precio;
    }

    Nodo* getSiguiente() {
        return siguiente;
    }

    
    void setSiguiente(Nodo* sig) {
        siguiente = sig;
    }
};


class Lista {
private:
    Nodo* cabeza;

public:

    
    Lista() {
        cabeza = nullptr;
    }

   
    void insertarProducto(int codigo, string nombre, float precio) {

        Nodo* nuevo = new Nodo(codigo, nombre, precio);

        // Si la lista esta vacia o el codigo es menor al primero
        if(cabeza == nullptr || codigo < cabeza->getCodigo()) {
            nuevo->setSiguiente(cabeza);
            cabeza = nuevo;
        }
        else {
            Nodo* actual = cabeza;

            while(actual->getSiguiente() != nullptr &&
                  actual->getSiguiente()->getCodigo() < codigo) {

                actual = actual->getSiguiente();
            }

            nuevo->setSiguiente(actual->getSiguiente());
            actual->setSiguiente(nuevo);
        }

        cout << "\nProducto insertado correctamente.\n";
    }

    
    void mostrarInventario() {

        if(cabeza == nullptr) {
            cout << "\nEl inventario esta vacio.\n";
            return;
        }

        Nodo* actual = cabeza;

        cout << "\n========== INVENTARIO ==========\n";

        while(actual != nullptr) {

            cout << "\nCodigo: " << actual->getCodigo();
            cout << "\nNombre: " << actual->getNombre();
            cout << "\nPrecio: $" << actual->getPrecio();
            cout << "\n--------------------------------\n";

            actual = actual->getSiguiente();
        }
    }

    void buscarProducto(int codigo) {

        Nodo* actual = cabeza;

        while(actual != nullptr) {

            if(actual->getCodigo() == codigo) {

                cout << "\nProducto encontrado:\n";
                cout << "Codigo: " << actual->getCodigo() << endl;
                cout << "Nombre: " << actual->getNombre() << endl;
                cout << "Precio: $" << actual->getPrecio() << endl;

                return;
            }

            actual = actual->getSiguiente();
        }

        cout << "\nNo se encontro el producto.\n";
    }

   
    void eliminarProducto(int codigo) {

        if(cabeza == nullptr) {
            cout << "\nEl inventario esta vacio.\n";
            return;
        }

        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while(actual != nullptr && actual->getCodigo() != codigo) {

            anterior = actual;
            actual = actual->getSiguiente();
        }

        if(actual == nullptr) {
            cout << "\nNo se encontro el producto.\n";
            return;
        }

        
        if(anterior == nullptr) {
            cabeza = actual->getSiguiente();
        }
        else {
            anterior->setSiguiente(actual->getSiguiente());
        }

        delete actual;

        cout << "\nProducto eliminado correctamente.\n";
    }

    
    ~Lista() {
        Nodo* actual = cabeza;

        while(actual != nullptr) {
            Nodo* auxiliar = actual;
            actual = actual->getSiguiente();
            delete auxiliar;
        }
    }
};


int main() {

    Lista lista;

    int opcion;
    int codigo;
    string nombre;
    float precio;

    do {
        cout << "\n========== TIENDA ==========\n";
        cout << "1. Insertar producto\n";
        cout << "2. Mostrar inventario\n";
        cout << "3. Buscar producto\n";
        cout << "4. Eliminar producto\n";
        cout << "5. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                cout << "\nIngrese el codigo: ";
                cin >> codigo;

                cin.ignore();

                cout << "Ingrese el nombre: ";
                getline(cin, nombre);

                cout << "Ingrese el precio: ";
                cin >> precio;

                lista.insertarProducto(codigo, nombre, precio);
                break;

            case 2:
                lista.mostrarInventario();
                break;

            case 3:
                cout << "\nIngrese el codigo a buscar: ";
                cin >> codigo;

                lista.buscarProducto(codigo);
                break;

            case 4:
                cout << "\nIngrese el codigo a eliminar: ";
                cin >> codigo;

                lista.eliminarProducto(codigo);
                break;

            case 5:
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while(opcion != 5);
//que ejercicio tan maluco
    return 0;
}