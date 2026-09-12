#include <iostream>
#include <string>

using namespace std;

class Inventario {
private:
    string noms[5];
    float precs[5];
    int cnt;

public:
    Inventario() {
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            noms[i] = "";
            precs[i] = 0;
        }
    }

    void anadir(string n, float p) {
        if (cnt >= 5) {
            cout << "Error: Inventario lleno.\n";
            return;
        }
        if (p < 0) {
            cout << "Error: Precio negativo.\n";
            return;
        }

        noms[cnt] = n;
        precs[cnt] = p;
        cnt++;

        cout << "Agregado.\n";
    }

    void mostrar() {
        if (cnt == 0) {
            cout << "Vacio.\n";
            return;
        }

        cout << "\n--- Lista ---\n";
        for (int i = 0; i < cnt; i++) {
            cout << noms[i] << " - $" << precs[i] << "\n";
        }
    }

    float total() {
        float t = 0;
        for (int i = 0; i < cnt; i++) {
            t += precs[i];
        }
        return t;
    }

    int getCnt() {
        return cnt;
    }
};

int main() {
    Inventario inv;
    string n;
    float p;
    int op;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar\n2. Mostrar\n3. Total\n4. Cantidad\n5. Salir\nOpcion: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "Nombre: ";
            cin >> n;
            cout << "Precio: $";
            cin >> p;
            inv.anadir(n, p);
            break;

        case 2:
            inv.mostrar();
            break;

        case 3:
            cout << "Total: $" << inv.total() << "\n";
            break;

        case 4:
            cout << "Cantidad: " << inv.getCnt() << "\n";
            break;

        case 5:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Error: Invalido.\n";
            break;
        }

    } while (op != 5);

    return 0;
}