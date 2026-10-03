
#include <iostream>
#include <string>
using namespace std;

class inventario {
private:
    string productos[5];
    float costos[5];
    int cantidad;

public:
    inventario() {
        cantidad = 0;

        for (int indice = 0; indice < 5; indice++) {
            productos[indice] = "";
            costos[indice] = 0;
        }
    }

    void setAgregarProducto(string producto, float costo) {
        if (cantidad >= 5) {
            cout << "ERROR: El inventario esta lleno." << endl;
            return;
        }

        if (costo < 0) {
            cout << "ERROR: El precio ingresado no es valido." << endl;
            return;
        }

        productos[cantidad] = producto;
        costos[cantidad] = costo;
        cantidad++;

        cout << "Producto registrado con exito." << endl;
    }

    void mostrarProductos() {
        if (cantidad == 0) {
            cout << "El inventario se encuentra vacio." << endl;
            return;
        }

        cout << "Listado de productos registrados" << endl;

        for (int indice = 0; indice < cantidad; indice++) {
            cout << "Producto: " << productos[indice] << endl;
            cout << "Costo: $" << costos[indice] << endl;
        }
    }

    float calcularValorTotal() {
        float sumaTotal = 0;

        for (int indice = 0; indice < cantidad; indice++) {
            sumaTotal += costos[indice];
        }

        return sumaTotal;
    }

    int getCantidad() {
        return cantidad;
    }
};

int main() {
    inventario inventarioActual;

    string nombreProducto;
    float precioProducto;
    int seleccion;

    do {
        cout << "\n********** INVENTARIO **********" << endl;
        cout << "1. Registrar un producto" << endl;
        cout << "2. Consultar productos" << endl;
        cout << "3. Consultar valor del inventario" << endl;
        cout << "4. Consultar cantidad de productos" << endl;
        cout << "5. Cerrar programa" << endl;
        cout << "********************************" << endl;

        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion) {
        case 1:
            cout << "Ingrese el nombre del producto: ";
            cin >> nombreProducto;

            cout << "Ingrese el precio: $";
            cin >> precioProducto;

            inventarioActual.setAgregarProducto(nombreProducto, precioProducto);
            break;

        case 2:
            inventarioActual.mostrarProductos();
            break;

        case 3:
            cout << "El costo total de los productos es: $"
                 << inventarioActual.calcularValorTotal() << endl;
            break;

        case 4:
            cout << "Numero de productos almacenados: "
                 << inventarioActual.getCantidad() << endl;
            break;

        case 5:
            cout << "El programa se cerrara..." << endl;
            break;

        default:
            cout << "ERROR: La opcion seleccionada no existe." << endl;
            break;
        }

    } while (seleccion != 5);

    return 10;
}

