#include<iostream>
#include<string>
using namespace std;

class Nodo {
public:
    int ISBN;
    string titulo;
    string autor;
    Nodo* siguiente;

   
    Nodo(int isbn, string tit, string aut) {
        ISBN = isbn;
        titulo = tit;
        autor = aut;
        siguiente = nullptr;
    }
};

class ListaLibros {
private:
    Nodo* cabeza;

public:

    
    ListaLibros() {
        cabeza = nullptr;
    }

    
    void agregarLibro(int ISBN, string titulo, string autor) {

        Nodo* nuevo = new Nodo(ISBN, titulo, autor);

        // Si la lista esta vacia o el ISBN es menor al primero
        if (cabeza == nullptr || ISBN < cabeza->ISBN) {
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
            cout << "Libro agregado correctamente.\n";
            return;
        }

        Nodo* actual = cabeza;

        
        while (actual->siguiente != nullptr && actual->siguiente->ISBN < ISBN) {
            actual = actual->siguiente;
        }

        
        if (actual->ISBN == ISBN || (actual->siguiente != nullptr && actual->siguiente->ISBN == ISBN)) {
            cout << "Ya existe un libro con ese ISBN.\n";
            delete nuevo;
            return;
        }

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;

        cout << "Libro agregado correctamente.\n";
    }

    
    void mostrarLibros() {

        if (cabeza == nullptr) {
            cout << "La biblioteca no tiene libros registrados.\n";
            return;
        }

        Nodo* actual = cabeza;

        cout << "\n===== COLECCION DE LIBROS =====\n";

        while (actual != nullptr) {
            cout << "ISBN: " << actual->ISBN << endl;
            cout << "Titulo: " << actual->titulo << endl;
            cout << "Autor: " << actual->autor << endl;
            cout << "-----------------------------\n";

            actual = actual->siguiente;
        }
    }


    void buscarLibro(int ISBN) {

        Nodo* actual = cabeza;

        while (actual != nullptr && actual->ISBN != ISBN) {
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "No se encontro un libro con ese ISBN.\n";
        }
        else {
            cout << "\nLibro encontrado:\n";
            cout << "ISBN: " << actual->ISBN << endl;
            cout << "Titulo: " << actual->titulo << endl;
            cout << "Autor: " << actual->autor << endl;
        }
    }


    void eliminarLibro(int ISBN) {

        if (cabeza == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }

        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        
        while (actual != nullptr && actual->ISBN != ISBN) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "No se encontro el libro que desea eliminar.\n";
            return;
        }

       
        if (anterior == nullptr) {
            cabeza = actual->siguiente;
        }
        else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual;

        cout << "Libro eliminado correctamente.\n";
    }
};

int main() {

    ListaLibros lista;

    int opcion, ISBN;
    string titulo, autor;

    do {

        cout << "\n===== GESTION DE LIBROS =====\n";
        cout << "1. Agregar libro\n";
        cout << "2. Mostrar libros\n";
        cout << "3. Buscar libro\n";
        cout << "4. Eliminar libro\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            cout << "Ingrese el ISBN del libro: ";
            cin >> ISBN;
            cin.ignore();

            cout << "Ingrese el titulo del libro: ";
            getline(cin, titulo);

            cout << "Ingrese el autor del libro: ";
            getline(cin, autor);

            lista.agregarLibro(ISBN, titulo, autor);
            break;

        case 2:
            lista.mostrarLibros();
            break;

        case 3:
            cout << "Ingrese el ISBN que desea buscar: ";
            cin >> ISBN;

            lista.buscarLibro(ISBN);
            break;

        case 4:
            cout << "Ingrese el ISBN del libro que desea eliminar: ";
            cin >> ISBN;

            lista.eliminarLibro(ISBN);
            break;

        case 5:
            cout << "Saliendo del sistema...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}