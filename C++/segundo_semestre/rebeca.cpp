#include <iostream>
using namespace std;

class nodo {
public:
    int numero;
    nodo* enlace;

    nodo(int valor) {
        numero = valor;
        enlace = nullptr;
    }
};

class lista {
private:
    nodo* inicio;

public:
    lista() {
        inicio = nullptr;
    }

    void agregarAscendente(int numero) {
        nodo* nuevo = new nodo(numero);

        if (inicio == nullptr || numero < inicio->numero) {
            nuevo->enlace = inicio;
            inicio = nuevo;
        }
        else {
            nodo* auxiliar = inicio;

            while (auxiliar->enlace != nullptr &&
                   auxiliar->enlace->numero < numero) {
                auxiliar = auxiliar->enlace;
            }

            nuevo->enlace = auxiliar->enlace;
            auxiliar->enlace = nuevo;
        }
    }

    void agregarDescendente(int numero) {
        nodo* nuevo = new nodo(numero);

        if (inicio == nullptr || numero > inicio->numero) {
            nuevo->enlace = inicio;
            inicio = nuevo;
        }
        else {
            nodo* auxiliar = inicio;

            while (auxiliar->enlace != nullptr &&
                   auxiliar->enlace->numero > numero) {
                auxiliar = auxiliar->enlace;
            }

            nuevo->enlace = auxiliar->enlace;
            auxiliar->enlace = nuevo;
        }
    }

    void imprimirLista() {
        nodo* auxiliar = inicio;

        while (auxiliar != nullptr) {
            cout << auxiliar->numero << " -> ";
            auxiliar = auxiliar->enlace;
        }

        cout << "FIN" << endl;
    }

    int obtenerCantidad() {
        nodo* auxiliar = inicio;
        int total = 0;

        while (auxiliar != nullptr) {
            total++;
            auxiliar = auxiliar->enlace;
        }

        return total;
    }

    float calcularPromedio() {
        if (inicio == nullptr) {
            return 0;
        }

        nodo* auxiliar = inicio;
        int acumulado = 0;

        while (auxiliar != nullptr) {
            acumulado += auxiliar->numero;
            auxiliar = auxiliar->enlace;
        }

        return (float)acumulado / obtenerCantidad();
    }

    void registrarDatos(lista &listaInversa) {
        int numeroIngresado;
        char respuesta;

        do {
            cout << "Digite un numero para agregar: ";
            cin >> numeroIngresado;

            agregarAscendente(numeroIngresado);
            listaInversa.agregarDescendente(numeroIngresado);

            cout << "¿Desea agregar un numero adicional? (s/n): ";
            cin >> respuesta;

        } while (respuesta == 's' || respuesta == 'S');
    }
};

int main() {
    lista ordenAscendente;
    lista ordenDescendente;

    ordenAscendente.registrarDatos(ordenDescendente);

    cout << endl;

    cout << "Elementos organizados de menor a mayor:" << endl;
    ordenAscendente.imprimirLista();

    cout << endl;

    cout << "Elementos organizados de mayor a menor:" << endl;
    ordenDescendente.imprimirLista();

    cout << endl;

    cout << "Numero total de elementos: "
         << ordenAscendente.obtenerCantidad() << endl;

    cout << "Valor promedio de los elementos: "
         << ordenAscendente.calcularPromedio() << endl;

    return 0;
}

