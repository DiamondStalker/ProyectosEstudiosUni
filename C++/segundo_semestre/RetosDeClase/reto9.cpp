
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

const int TAM = 5;

// ==========================================
// CONFIGURACION DE COLORES
// ==========================================

void color(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// ==========================================
// VALIDAR ENTRADAS NUMERICAS
// ==========================================

int leerEntero(string mensaje) {
    string entrada;
    int numero;
    char extra;

    while (true) {
        cout << mensaje;
        getline(cin, entrada);

        stringstream ss(entrada);

        if (ss >> numero && !(ss >> extra)) {
            return numero;
        }

        color(12);
        cout << "\n  Entrada invalida. Ingrese un numero entero.\n\n";
        color(7);
    }
}

// ==========================================
// CLASE DOCUMENTO
// ==========================================

class Documento {
public:
    string nombre;
    string usuario;
    int paginas;

    Documento() {
        nombre = "";
        usuario = "";
        paginas = 0;
    }

    Documento(string n, string u, int p) {
        nombre = n;
        usuario = u;
        paginas = p;
    }
};

// ==========================================
// CLASE COLA DE IMPRESION
// ==========================================

class ColaImpresion {
private:
    Documento documentos[TAM];

    int frente;
    int indiceFinal;
    int cantidad;

public:

    // CONSTRUCTOR
    ColaImpresion() {
        frente = 0;
        indiceFinal = -1;
        cantidad = 0;
    }

    // VERIFICAR SI LA COLA ESTA LLENA
    bool colaLlena() {
        return cantidad == TAM;
    }

    // VERIFICAR SI LA COLA ESTA VACIA
    bool colaVacia() {
        return cantidad == 0;
    }

    // AGREGAR DOCUMENTO
    void encolar(Documento documento) {

        if (colaLlena()) {
            color(12);
            cout << "\n  [ERROR] La cola esta llena.\n";
            color(7);
            return;
        }

        indiceFinal = (indiceFinal + 1) % TAM;

        documentos[indiceFinal] = documento;

        cantidad++;

        color(10);
        cout << "\n  [OK] Documento agregado correctamente.\n";
        color(7);
    }

    // RETIRAR DOCUMENTO DEL FRENTE
    bool desencolar() {

        if (colaVacia()) {
            color(12);
            cout << "\n  [ERROR] No hay documentos pendientes.\n";
            color(7);
            return false;
        }

        frente = (frente + 1) % TAM;

        cantidad--;

        if (colaVacia()) {
            frente = 0;
            indiceFinal = -1;
        }

        return true;
    }

    // MOSTRAR DOCUMENTOS PENDIENTES
    void mostrarCola() {

        if (colaVacia()) {
            color(14);
            cout << "\n  No hay documentos pendientes.\n";
            color(7);
            return;
        }

        cout << "\n  ==========================================================\n";
        cout << "                    COLA DE IMPRESION\n";
        cout << "  ==========================================================\n";

        for (int i = 0; i < cantidad; i++) {

            int posicion = (frente + i) % TAM;

            cout << "\n  DOCUMENTO #" << i + 1 << "\n";

            if (i == 0) {
                color(10);
                cout << "  [PROXIMO A IMPRIMIR]\n";
                color(7);
            }

            cout << "  Archivo: " << documentos[posicion].nombre << "\n";
            cout << "  Usuario: " << documentos[posicion].usuario << "\n";
            cout << "  Paginas: " << documentos[posicion].paginas << "\n";

            cout << "  ----------------------------------------------------------\n";
        }
    }

    // CONSULTAR CANTIDAD DE ELEMENTOS
    int cantidadElementos() {
        return cantidad;
    }

    // CONSULTAR EL DOCUMENTO DEL FRENTE
    bool consultarFrente(Documento &documento) {

        if (colaVacia()) {
            return false;
        }

        documento = documentos[frente];

        return true;
    }

    // CONSULTAR PAGINAS DEL PROXIMO DOCUMENTO
    int consultarPaginas() {

        if (colaVacia()) {
            return -1;
        }

        return documentos[frente].paginas;
    }
};

// ==========================================
// BARRA DE PROGRESO
// ==========================================

void barraProgreso() {

    cout << "\n\n  Imprimiendo documento...\n\n  [";

    for (int i = 0; i < 30; i++) {

        color(10);
        cout << (char)219;
        color(7);

        cout.flush();

        Sleep(80);
    }

    cout << "] 100%\n";
}

// ==========================================
// PROCESAR IMPRESION
// ==========================================

void imprimirDocumento(ColaImpresion &cola) {

    if (cola.colaVacia()) {
        color(12);
        cout << "\n  No hay documentos para imprimir.\n";
        color(7);
        return;
    }

    Documento documento;

    cola.consultarFrente(documento);

    cout << "\n  ==========================================\n";
    cout << "           TRABAJO DE IMPRESION\n";
    cout << "  ==========================================\n";

    cout << "\n  Archivo: " << documento.nombre;
    cout << "\n  Usuario: " << documento.usuario;
    cout << "\n  Paginas: " << documento.paginas;

    barraProgreso();

    if (cola.desencolar()) {
        color(10);
        cout << "\n  [OK] Documento impreso correctamente.\n";
        cout << "  [OK] Documento retirado de la cola.\n";
        color(7);
    }
}

// ==========================================
// ENCABEZADO DE LA VENTANA
// ==========================================

void encabezado(ColaImpresion &cola) {

    system("cls");

    color(11);

    cout << "\n";
    cout << "  =====================================================================\n";
    cout << "                       PRINT MANAGER PRO\n";
    cout << "                   ADMINISTRADOR DE IMPRESION\n";
    cout << "  =====================================================================\n";

    color(7);

    cout << "\n  Impresora: HP LaserJet Pro";

    color(10);
    cout << "                          [EN LINEA]\n";

    color(7);

    cout << "\n  Estado: ";

    if (cola.colaVacia()) {
        color(10);
        cout << "DISPONIBLE\n";
    }
    else {
        color(14);
        cout << "TRABAJOS PENDIENTES\n";
    }

    color(7);

    cout << "\n  ---------------------------------------------------------------------\n";

    cout << "   DOCUMENTOS PENDIENTES: ";

    color(11);
    cout << cola.cantidadElementos() << " / " << TAM;

    color(7);

    cout << "          ESPACIOS LIBRES: ";

    color(11);
    cout << TAM - cola.cantidadElementos() << "\n";

    color(7);

    cout << "  ---------------------------------------------------------------------\n";

    cout << "\n                    VISTA DE IMPRESION\n";

    if (cola.colaVacia()) {

        color(8);
        cout << "\n             No hay documentos en espera.\n";
        color(7);

    }
    else {

        cola.mostrarCola();

    }

    cout << "\n  =====================================================================\n";
    cout << "                       PANEL DE OPERACIONES\n";
    cout << "  =====================================================================\n";

    color(10);
    cout << "\n       [1] ";
    color(7);
    cout << "Agregar documento a la cola\n";

    color(10);
    cout << "       [2] ";
    color(7);
    cout << "Imprimir siguiente documento\n";

    color(10);
    cout << "       [3] ";
    color(7);
    cout << "Mostrar cola de impresion\n";

    color(10);
    cout << "       [4] ";
    color(7);
    cout << "Consultar cantidad de documentos\n";

    color(10);
    cout << "       [5] ";
    color(7);
    cout << "Consultar proximo documento\n";

    color(10);
    cout << "       [6] ";
    color(7);
    cout << "Consultar paginas del proximo documento\n";

    color(12);
    cout << "       [0] ";
    color(7);
    cout << "Apagar administrador\n";

    cout << "\n  ---------------------------------------------------------------------\n";
}

// ==========================================
// PROGRAMA PRINCIPAL
// ==========================================

int main() {

    SetConsoleOutputCP(CP_UTF8);

    ColaImpresion cola;

    int opcion = -1;

    do {

        encabezado(cola);

        opcion = leerEntero("  Seleccione una operacion: ");

        switch (opcion) {

        // AGREGAR DOCUMENTO
        case 1: {

            if (cola.colaLlena()) {

                color(12);
                cout << "\n  La cola esta llena. No puede agregar mas documentos.\n";
                color(7);

                break;
            }

            string nombre;
            string usuario;
            int paginas;

            cout << "\n  ==========================================\n";
            cout << "           NUEVO TRABAJO DE IMPRESION\n";
            cout << "  ==========================================\n";

            cout << "\n  Nombre del archivo: ";
            getline(cin, nombre);

            if (nombre.empty()) {
                cout << "\n  El nombre del archivo no puede estar vacio.\n";
                break;
            }

            cout << "  Usuario: ";
            getline(cin, usuario);

            if (usuario.empty()) {
                cout << "\n  El usuario no puede estar vacio.\n";
                break;
            }

            do {

                paginas = leerEntero("  Numero de paginas: ");

                if (paginas <= 0) {
                    color(12);
                    cout << "\n  El documento debe tener al menos una pagina.\n";
                    color(7);
                }

            } while (paginas <= 0);

            Documento nuevo(nombre, usuario, paginas);

            cola.encolar(nuevo);

            break;
        }

        // IMPRIMIR DOCUMENTO
        case 2: {

            imprimirDocumento(cola);

            break;
        }

        // MOSTRAR COLA
        case 3: {

            cola.mostrarCola();

            break;
        }

        // CANTIDAD DE DOCUMENTOS
        case 4: {

            cout << "\n  Documentos pendientes: "
                 << cola.cantidadElementos() << "\n";

            break;
        }

        // CONSULTAR FRENTE
        case 5: {

            Documento documento;

            if (cola.consultarFrente(documento)) {

                cout << "\n  PROXIMO DOCUMENTO A IMPRIMIR\n";

                cout << "\n  Archivo: " << documento.nombre;
                cout << "\n  Usuario: " << documento.usuario;
                cout << "\n  Paginas: " << documento.paginas << "\n";

            }
            else {

                cout << "\n  No hay documentos pendientes.\n";

            }

            break;
        }

        // CONSULTAR PAGINAS
        case 6: {

            int paginas = cola.consultarPaginas();

            if (paginas != -1) {

                cout << "\n  El proximo documento tiene "
                     << paginas << " paginas.\n";

            }
            else {

                cout << "\n  No hay documentos pendientes.\n";

            }

            break;
        }

        // SALIR
        case 0: {

            color(11);
            cout << "\n  Cerrando administrador de impresion...\n";
            cout << "  Gracias por utilizar PRINT MANAGER PRO.\n";
            color(7);

            break;
        }

        // OPCION INVALIDA
        default: {

            color(12);
            cout << "\n  Opcion invalida. Seleccione una opcion del menu.\n";
            color(7);

            break;
        }

        }

        if (opcion != 0) {
            cout << "\n";
            system("pause");
        }

    } while (opcion != 0);

    return 0;
}
