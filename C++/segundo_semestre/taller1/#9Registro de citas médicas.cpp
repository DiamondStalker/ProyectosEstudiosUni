
#include<iostream>
#include<string>
using namespace std;

class Nodo {
public:
    int id;
    string nombrePaciente;
    string fecha;
    Nodo* siguiente;

   
    Nodo(int identificacion, string nombre, string fechaCita) {
        id = identificacion;
        nombrePaciente = nombre;
        fecha = fechaCita;
        siguiente = nullptr;
    }
};

class ListaCitas {
private:
    Nodo* cabeza;

public:

    
    ListaCitas() {
        cabeza = nullptr;
    }

  
    void agregarCita(int id, string nombrePaciente, string fecha) {

        Nodo* nuevo = new Nodo(id, nombrePaciente, fecha);

        
        if (cabeza == nullptr || id < cabeza->id) {
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
            cout << "Cita agregada correctamente.\n";
            return;
        }

        Nodo* actual = cabeza;

        
        while (actual->siguiente != nullptr && actual->siguiente->id < id) {
            actual = actual->siguiente;
        }

   
        if (actual->id == id || (actual->siguiente != nullptr && actual->siguiente->id == id)) {
            cout << "Ya existe una cita con ese identificador.\n";
            delete nuevo;
            return;
        }

        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;

        cout << "Cita agregada correctamente.\n";
    }

    
    void mostrarCitas() {

        if (cabeza == nullptr) {
            cout << "No hay citas programadas.\n";
            return;
        }

        Nodo* actual = cabeza;

        cout << "\n--- CITAS MEDICAS ---\n";

        while (actual != nullptr) {
            cout << "Identificacion: " << actual->id << endl;
            cout << "Nombre: " << actual->nombrePaciente << endl;
            cout << "Fecha: " << actual->fecha << endl;
            cout << "----------------------\n";

            actual = actual->siguiente;
        }
    }

    
    void buscarCita(int id) {

        Nodo* actual = cabeza;

        while (actual != nullptr && actual->id != id) {
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "No se encontro una cita con ese identificador.\n";
        }
        else {
            cout << "\nCita encontrada:\n";
            cout << "Identificacion: " << actual->id << endl;
            cout << "Nombre: " << actual->nombrePaciente << endl;
            cout << "Fecha: " << actual->fecha << endl;
        }
    }

    
    void cancelarCita(int id) {

        if (cabeza == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }

        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        
        while (actual != nullptr && actual->id != id) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "No se encontro la cita que desea cancelar.\n";
            return;
        }

      
        if (anterior == nullptr) {
            cabeza = actual->siguiente;
        }
        else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual;

        cout << "Cita cancelada correctamente.\n";
    }
};

int main() {

    ListaCitas lista;

    int opcion, id;
    string nombre, fecha;

    do {
        cout << "\n===== REGISTRO DE CITAS MEDICAS =====\n";
        cout << "1. Agregar cita\n";
        cout << "2. Mostrar citas\n";
        cout << "3. Buscar cita\n";
        cout << "4. Cancelar cita\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            cout << "Ingrese el numero de identificacion: ";
            cin >> id;
            cin.ignore();

            cout << "Ingrese el nombre del paciente: ";
            getline(cin, nombre);

            cout << "Ingrese la fecha de la cita: ";
            getline(cin, fecha);

            lista.agregarCita(id, nombre, fecha);
            break;

        case 2:
            lista.mostrarCitas();
            break;

        case 3:
            cout << "Ingrese el identificador que desea buscar: ";
            cin >> id;

            lista.buscarCita(id);
            break;

        case 4:
            cout << "Ingrese el identificador de la cita que desea cancelar: ";
            cin >> id;

            lista.cancelarCita(id);
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