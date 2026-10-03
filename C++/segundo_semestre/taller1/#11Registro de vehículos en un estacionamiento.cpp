#include<iostream>
#include<string>
using namespace std;

class Nodo {
public:
    string placa;
    string modelo;
    string horaEntrada;
    Nodo* siguiente;

    Nodo(string pl, string mod, string hora) {
        placa = pl;
        modelo = mod;
        horaEntrada = hora;
        siguiente = nullptr;
    }
};

class ListaVehiculos {
private:
    Nodo* cabeza;

public:
    ListaVehiculos() {
        cabeza = nullptr;
    }

    void registrarVehiculo(string placa, string modelo, string horaEntrada) {

        Nodo* nuevo = new Nodo(placa, modelo, horaEntrada);

        if (cabeza == nullptr) {
            cabeza = nuevo;
            cout << "Vehiculo registrado correctamente.\n";
            return;
        }

        Nodo* actual = cabeza;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;

        cout << "Vehiculo registrado correctamente.\n";
    }

    void mostrarVehiculos() {

        if (cabeza == nullptr) {
            cout << "No hay vehiculos dentro del estacionamiento.\n";
            return;
        }

        Nodo* actual = cabeza;

        cout << "\n===== VEHICULOS EN EL ESTACIONAMIENTO =====\n";

        while (actual != nullptr) {

            cout << "Placa: " << actual->placa << endl;
            cout << "Modelo: " << actual->modelo << endl;
            cout << "Hora de entrada: " << actual->horaEntrada << endl;
            cout << "-------------------------------------------\n";

            actual = actual->siguiente;
        }
    }

    void buscarVehiculo(string placa) {

        Nodo* actual = cabeza;

        while (actual != nullptr && actual->placa != placa) {
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "No se encontro un vehiculo con esa placa.\n";
        }
        else {
            cout << "\nVehiculo encontrado:\n";
            cout << "Placa: " << actual->placa << endl;
            cout << "Modelo: " << actual->modelo << endl;
            cout << "Hora de entrada: " << actual->horaEntrada << endl;
        }
    }

    void retirarVehiculo(string placa) {

        if (cabeza == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }

        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        while (actual != nullptr && actual->placa != placa) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual == nullptr) {
            cout << "No se encontro un vehiculo con esa placa.\n";
            return;
        }

        if (anterior == nullptr) {
            cabeza = actual->siguiente;
        }
        else {
            anterior->siguiente = actual->siguiente;
        }

        delete actual;

        cout << "Vehiculo retirado correctamente.\n";
    }
};

int main() {

    ListaVehiculos lista;

    int opcion;
    string placa;
    string modelo;
    string horaEntrada;

    do {

        cout << "\n===== REGISTRO DE ESTACIONAMIENTO =====\n";
        cout << "1. Registrar vehiculo\n";
        cout << "2. Mostrar vehiculos\n";
        cout << "3. Buscar vehiculo\n";
        cout << "4. Retirar vehiculo\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:

            cout << "Ingrese la placa: ";
            cin >> placa;
            cin.ignore();

            cout << "Ingrese el modelo: ";
            getline(cin, modelo);

            cout << "Ingrese la hora de entrada: ";
            getline(cin, horaEntrada);

            lista.registrarVehiculo(placa, modelo, horaEntrada);

            break;

        case 2:

            lista.mostrarVehiculos();

            break;

        case 3:

            cout << "Ingrese la placa que desea buscar: ";
            cin >> placa;

            lista.buscarVehiculo(placa);

            break;

        case 4:

            cout << "Ingrese la placa del vehiculo que desea retirar: ";
            cin >> placa;

            lista.retirarVehiculo(placa);

            break;

        case 5:

            cout << "Saliendo del sistema...\n";

            break;

        default:

            cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
    //por finnnn
}