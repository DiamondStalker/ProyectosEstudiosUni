#include <iostream>
#include <string>
using namespace std;

class inventario {
private:
    string nombresP[5];
    float preciosP[5];
    int contador;

public:
    inventario() {
        contador = 0;

        for (int i = 0; i < 5; i++) {
            nombresP[i] = "";
            preciosP[i] = 0;
        }
    }

    void setAgregarProducto(string nombre, float precio) {
        if (contador >= 5) {
            cout << "ERROR: No hay espacio para mas productos." << endl;
            return;
        }

        if (precio < 0) {
            cout << "ERROR: El precio no puede ser negativo." << endl;
            return;
        }

        nombresP[contador] = nombre;
        preciosP[contador] = precio;
        contador++;

        cout << "Producto agregado correctamente." << endl;
    }

    void mostrarProductos() {
        if (contador == 0) {
            cout << "No hay productos registrados." << endl;
            return;
        }

        cout << "Productos y sus precios" << endl;

        for (int i = 0; i < contador; i++) {
            cout << "Nombre: " << nombresP[i] << endl;
            cout << "Precio: $" << preciosP[i] << endl;
        }
    }

    float calcularValorTotal() {
        float total = 0;

        for (int i = 0; i < contador; i++) {
            total += preciosP[i];
        }

        return total;
    }

    int getCantidad() {
        return contador;
    }
};

int main() {
    inventario inv;

    string nom;
    float prec;
    int opcion;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Mostrar valor total del inventario" << endl;
        cout << "4. Mostrar cantidad de productos registrados" << endl;
        cout << "5. Salir del programa" << endl;
        cout << "===========================" << endl;

        cout << "Digite la opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Nombre: ";
            cin >> nom;

            cout << "Precio: $";
            cin >> prec;

            inv.setAgregarProducto(nom, prec);
            break;

        case 2:
            inv.mostrarProductos();
            break;

        case 3:
            cout << "El valor total del inventario es de: $"
                 << inv.calcularValorTotal() << endl;
            break;

        case 4:
            cout << "Cantidad de productos registrados: "
                 << inv.getCantidad() << endl;
            break;

        case 5:
            cout << "Saliendo del programaa..." << endl;
            break;

        default:
            cout << "ERROR: Opcion incorrectaaaaaaa." << endl;
            break;
        }

    } while (opcion != 5);

    return 10;
}