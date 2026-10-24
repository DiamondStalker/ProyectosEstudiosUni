
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

class Nodo {
public:
    string url;
    Nodo* siguiente;

    Nodo(string direccion) {
        url = direccion;
        siguiente = nullptr;
    }
};

class url {
private:
    Nodo* cima;

public:
    url() {
          cima = nullptr;
    }

    bool pilaVacia() {
    return cima == nullptr;
    }
    void push(string direccion) {
        if (pilaVacia() || cima != nullptr) {
            Nodo* nuevo = new Nodo(direccion);
            nuevo->siguiente = cima;
            cima = nuevo;

            cout << "Buscando..." << endl;
            Sleep(1000);//todo esto es lo mismo que hice en tipo Arreglo.
            cout << "Redirigiendo..." << endl;
            Sleep(1000);//Simular barra de progreso;
        }
    }


    void pop() {
        string nada;

        if (pilaVacia()) {
            system("cls");//para limpiar la consola y q solo me muestre una cosa y no todo apilado.
            cout << "============================================================\n";
            cout << "|                       POLI BROWSER                       |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|                   NO HAY PESTANAS ABIERTAS               |\n";
            cout << "|                                                          |\n";
            cout << "|             No hay paginas para restablecer              |\n";
            cout << "|__________________________________________________________|\n";
        }
        else if (cima->siguiente == nullptr) {
            system("cls");
            cout << "============================================================\n";
            cout << "|                       POLI BROWSER                       |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|                 NO HAY PAGINA ANTERIOR                   |\n";
            cout << "|                                                          |\n";
            cout << "|  Solo tienes una pagina abierta:                         |\n";
            cout << "|  " << cima->url << "                                     |\n";
            cout << "|__________________________________________________________|\n";
        }
        else {
            system("cls");
            cout << "============================================================\n";
            cout << "|                       POLI BROWSER                       |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|                  RESTABLECIENDO PAGINA                   |\n";
            cout << "|                                                          |\n";
            cout << "|  Cerrando pestana actual...                              |\n";
            cout << "|  [..........                    ]                        |\n";

            Sleep(1000);//barra de progreso.

            Nodo* aux = cima;
            cima = cima->siguiente;
            delete aux;

            cout << "|  [.....................         ]                        |\n";
            Sleep(700);

            cout << "|  [------------------------------]                        |\n";
            cout << "|                                                          |\n";
            cout << "|                  PAGINA RESTABLECIDA                     |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|  URL actual: " << cima->url << "\n";
            cout << "|__________________________________________________________|\n";
        }

        cout << "Ingrese una letra y un enter para regresar al menu: ";
        cin >> nada;
    }

    void mostrar() {
        string vacio;

        system("cls");

        if (pilaVacia()) {
            cout << "============================================================\n";
            cout << "|                       POLI BROWSER                       |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|                     HISTORIAL WEB                        |\n";
            cout << "|                                                          |\n";
            cout << "|                  HISTORIAL VACIO                         |\n";
            cout << "|                                                          |\n";
            cout << "|             No hay paginas para mostrar                  |\n";
            cout << "|                                                          |\n";
            cout << "|__________________________________________________________|\n";
        }
        else {
            cout << "============================================================\n";
            cout << "|                       POLI BROWSER                       |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|                     HISTORIAL WEB                        |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";

            Nodo* aux = cima;

            while (aux != nullptr) {
                cout << "|  " << aux->url << "                                  |\n";
                aux = aux->siguiente;
            }

            cout << "|__________________________________________________________|\n";
        }

        cout << "Ingrese una letra y un enter para regresar al menu: ";
        cin >> vacio;
    }

    void actual() {
        string vacio;

        system("cls");

        if (pilaVacia()) {
            cout << "============================================================\n";
            cout << "|                       POLI BROWSER                       |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|                   NO HAY PESTANAS ABIERTAS               |\n";
            cout << "|__________________________________________________________|\n";
        }
        else {
            cout << "============================================================\n";
            cout << "|                       POLI BROWSER                       |\n";
            cout << "|__________________________________________________________|\n";
            cout << "|                                                          |\n";
            cout << "|                   ULTIMA PESTANA ABIERTA:                |\n";
            cout << "|                   " << cima->url << "\n";
            cout << "|__________________________________________________________|\n";
        }

        cout << "Seleccione una letra y enter para regresar al menu: ";
        cin >> vacio;
    }
};

int main() {
    int opcion;
    string direccion;
    url objeto;

    do {
        system("cls");

        cout << "============================================================\n";
        cout << "                    USUARIO BROWSER                         \n";
        cout << "============================================================\n";
        cout << "|                                                          |\n";
        cout << "|  <  >  R    https://www.poli-browser.com                 |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                      POLI                                |\n";
        cout << "|                   NAVEGADOR PERSONAL                     |\n";
        cout << "|                                                          |\n";
        cout << "|            Tu navegador, tu mundo digital                |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|  [1]  Visitar nueva pagina                               |\n";
        cout << "|                                                          |\n";
        cout << "|  [2]  Retroceder                                         |\n";
        cout << "|                                                          |\n";
        cout << "|  [3]  Mostrar historial                                  |\n";
        cout << "|                                                          |\n";
        cout << "|  [4]  Mostrar pagina actual                              |\n";
        cout << "|                                                          |\n";
        cout << "|  [5]  Salir                                              |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|  Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");

                cout << "============================================================\n";
                cout << "                    USUARIO BROWSER                         \n";
                cout << "============================================================\n";
                cout << "|                                                          |\n";
                cout << "|  <  >  R    https://www.poli-browser.com                 |\n";
                cout << "|__________________________________________________________|\n";
                cout << "|                                                          |\n";
                cout << "|                   Visitar nueva pagina                   |\n";
                cout << "|__________________________________________________________|\n";
                cout << "|                                                          |\n";
                cout << "|  URL: ";
                cin >> direccion;

                objeto.push(direccion);
                break;

            case 2:
                objeto.pop();
                break;

            case 3:
                objeto.mostrar();
                break;

            case 4:
                objeto.actual();
                break;

            case 5:
                system("cls");
                cout << "============================================================\n";
                cout << "                    USUARIO BROWSER                         \n";
                cout << "============================================================\n";
                cout << "|                                                          |\n";
                cout << "|                   SALIENDO DEL NAVEGADOR                 |\n";
                cout << "|__________________________________________________________|\n";
                break;

            default:
                system("cls");
                cout << "============================================================\n";
                cout << "|                  ERROR 404: BAD REQUEST                  |\n";
                cout << "|                    INTENTE DE NUEVO                      |\n";
                cout << "============================================================\n";
                Sleep(2000);
                break;
        }

    } while (opcion != 5);

    return 0;
}
