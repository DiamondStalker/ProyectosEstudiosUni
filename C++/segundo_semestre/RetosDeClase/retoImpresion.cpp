#include <iostream>
#include <string>
#include <windows.h>// Permite utilizar funciones de Windows como cambiar colores de la consola y pausar la ejecución.
using namespace std;
// 0  = Negro
// 1  = Azul oscuro
// 2  = Verde
// 3  = Aguamarina
// 4  = Rojo
// 5  = Morado
// 6  = Amarillo oscuro
// 7  = Gris claro (predeterminado)
// 8  = Gris oscuro
// 9  = Azul claro
// 10 = Verde claro
// 11 = Aguamarina claro
// 12 = Rojo claro
// 13 = Rosado
// 14 = Amarillo
// 15 = Blanco brillante
void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
} // Obtiene el identificador de la salida de la consola y establece el color indicado por c.SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

void pausa()
{
    cout << "\n";
    system("pause");// Detiene el programa hasta que el usuario presione una tecla.
}

class nodo
{
public:
    string archivo;
    string usuario;
    int paginas;
    nodo *siguiente;

    nodo(string arch, string usua, int pag)
    {
        archivo = arch;
        usuario = usua;
        paginas = pag;
        siguiente = nullptr;
    }
};

class impresion
{
private:
    nodo *inicio;
    nodo *final;

public:
    impresion()
    {
        inicio = nullptr;
        final = nullptr;
    }

    bool colaVacia()
    {
        return inicio == nullptr;
    }

    void encolar(string arch, string usua, int pag)
    {
        nodo *nuevo = new nodo(arch, usua, pag);

        if (colaVacia())
        {
            inicio = final = nuevo;
        }
        else
        {
            final->siguiente = nuevo;
            final = nuevo;
        }

        color(10);//color verde
        cout << "\n  [OK] Documento agregado correctamente.\n";
        color(7);//color normal(vuelve a ser normal)
    }

    void desencolar()
    {
        if (colaVacia())
        {
            color(12);//color rojo
            cout << "\n  No hay documentos pendientes.\n";
            color(7);//color normal(vuelve a ser normal)
            return;
        }

        nodo *temp = inicio;
        inicio = inicio->siguiente;
        delete temp;

        if (inicio == nullptr)
        {
            final = nullptr;
        }
    }

    void mostrarCola()
    {
        if (colaVacia())
        {
            color(14);//colora  amariillo
            cout << "\n  No hay documentos pendientes.\n";
            color(7);//color normal(vuelve a ser normal)
            return;
        }

        nodo *temp = inicio;
        int contador = 1;

        cout << "\n  ==========================================================\n";
        cout << "                    COLA DE IMPRESION\n";
        cout << "  ==========================================================\n";

        while (temp != nullptr)
        {

            cout << "\n  DOCUMENTO #" << contador << "\n";

            if (contador == 1)
            {
                color(10);//color verde
                cout << "  [PROXIMO A IMPRIMIR]\n";
                color(7);//color normal(vuelve a ser normal)
            }

            cout << "  Archivo: " << temp->archivo << endl;
            cout << "  Usuario: " << temp->usuario << endl;
            cout << "  Paginas: " << temp->paginas << endl;

            color(8);//color gris oscuro
            cout << "  ----------------------------------------------------------\n";
            color(7);//color normal(vuelve a ser normal)

            temp = temp->siguiente;
            contador++;
        }
    }

    void cantidadElementos()
    {
        int contador = 0;
        nodo *temp = inicio;

        while (temp != nullptr)
        {
            contador++;
            temp = temp->siguiente;
        }

        color(11);//color aguamarina
        cout << "  DOCUMENTOS PENDIENTES: ";
        color(15);//color blanco
        cout << contador << endl;
        color(7);//color normal(vuelve a ser normal)
    }

    void mostrarFrente()
    {
        if (colaVacia())
        {
            color(12);//color rojo
            cout << "\n  No hay documentos pendientes.\n";
            color(7);//color normal(vuelve a ser normal)
            return;
        }

        color(14);//color amarillo
        cout << "\n  PROXIMO DOCUMENTO A IMPRIMIR\n";
        color(7);//color normal(vuelve a ser normal)

        cout << "\n  Archivo: " << inicio->archivo << endl;
        cout << "  Usuario: " << inicio->usuario << endl;
        cout << "  Paginas: " << inicio->paginas << endl;
    }

    void mostrarPag()
    {
        if (colaVacia())
        {
            color(12);
            cout << "\n  No hay documentos pendientes.\n";
            color(7);//color normal(vuelve a ser normal)
            return;
        }

        cout << "\n  Paginas del proximo documento: ";
        color(15);
        cout << inicio->paginas << endl;
        color(7);//color normal(vuelve a ser normal)
    }

    void buscarDoc(string n)
    {
        if (colaVacia())
        {
            color(12);
            cout << "\n  No hay documentos pendientes.\n";
            color(7);
            return;
        }

        nodo *temp = inicio;

        while (temp != nullptr)
        {
            if (temp->archivo == n)
            {

                color(10);
                cout << "\n  DOCUMENTO ENCONTRADO\n";
                color(7);//color normal(vuelve a ser normal)

                cout << "\n  Archivo: " << temp->archivo << endl;
                cout << "  Usuario: " << temp->usuario << endl;
                cout << "  Paginas: " << temp->paginas << endl;

                return;
            }

            temp = temp->siguiente;
        }

        color(12);
        cout << "\n  No se encontro el documento.\n";
        color(7);//color normal(vuelve a ser normal)
    }

    void totalPag()
    {
        if (colaVacia())
        {
            color(12);
            cout << "\n  No hay paginas pendientes para imprimir.\n";
            color(7);//color normal(vuelve a ser normal)
            return;
        }

        nodo *temp = inicio;
        int total = 0;

        while (temp != nullptr)
        {
            total += temp->paginas;
            temp = temp->siguiente;
        }

        color(11);
        cout << "\n  Total de paginas pendientes: ";
        color(15);
        cout << total << endl;
        color(7);//color normal(vuelve a ser normal)
    }
};

void barraProgreso()
{

    cout << "\n\n  Imprimiendo documento...\n\n  [";// Muestra el mensaje y abre visualmente la barra.

    for (int i = 0; i < 30; i++)// Repite 30 veces para dibujar 30 bloques.
    {

        color(10);
        cout << (char)219;// Convierte el número 219 en un carácter que representa un bloque sólido.
        color(7);

        cout.flush();// Fuerza a mostrar inmediatamente en la consola lo que esté pendiente en el búfer de salida.

        Sleep(80);// Espera 80 milisegundos antes de dibujar el siguiente bloque.
    }

    cout << "] 100%\n";//dice que llega al 100 por ende ya imprimio
}

void imprimirDocumento(impresion &cola)// &cola recibe el objeto original por referencia, sin crear una copia de la cola.
    //if (cola.colaVacia()) // Comprueba si hay algún documento para imprimir.
{

    if (cola.colaVacia())
    {
        color(12);
        cout << "\n  No hay documentos para imprimir.\n";
        color(7);
        return;
    }

    cout << "\n  ==========================================================\n";
    cout << "                    TRABAJO DE IMPRESION\n";
    cout << "  ==========================================================\n";

    cola.mostrarFrente();

    barraProgreso();

    cola.desencolar();

    color(10);
    cout << "\n  [OK] Documento impreso correctamente.\n";
    cout << "  [OK] Documento retirado de la cola.\n";
    color(7);
}

void encabezado(impresion &cola) // &cola recibe por referencia la cola original para consultar sus documentos sin copiarla.
    //system("cls"); // Limpia la consola antes de volver a dibujar el menú.
{

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

    if (cola.colaVacia())
    {
        color(10);
        cout << "DISPONIBLE\n";
    }
    else
    {
        color(14);
        cout << "TRABAJOS PENDIENTES\n";
    }

    color(7);

    cout << "\n  ---------------------------------------------------------------------\n";

    cola.cantidadElementos();

    cout << "  ---------------------------------------------------------------------\n";

    cout << "\n                    VISTA DE IMPRESION\n";

    if (cola.colaVacia())
    {
        color(8);
        cout << "\n             No hay documentos en espera.\n";
        color(7);
    }
    else
    {
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
    cout << "Mostrar documentos pendientes\n";

    color(10);
    cout << "       [4] ";
    color(7);
    cout << "Cantidad de documentos pendientes\n";

    color(10);
    cout << "       [5] ";
    color(7);
    cout << "Mostrar siguiente documento\n";

    color(10);
    cout << "       [6] ";
    color(7);
    cout << "Paginas del siguiente documento\n";

    color(10);
    cout << "       [7] ";
    color(7);
    cout << "Buscar documento\n";

    color(10);
    cout << "       [8] ";
    color(7);
    cout << "Total de paginas pendientes\n";

    color(12);
    cout << "       [0] ";
    color(7);
    cout << "Apagar administrador\n";

    cout << "\n  ---------------------------------------------------------------------\n";
}

int main()
{

    impresion cola;

    int opcion;
    string archivo, usuario;
    int paginas;

    do
    {

        encabezado(cola);

        cout << "\n  Seleccione una operacion: ";
        cin >> opcion;
        cin.ignore();

        system("cls");

        color(11);
        cout << "\n  =====================================================================\n";
        cout << "                       PRINT MANAGER PRO\n";
        cout << "  =====================================================================\n";
        color(7);

        switch (opcion)
        {

        case 1:

            color(10);
            cout << "\n  NUEVO TRABAJO DE IMPRESION\n";
            color(7);

            cout << "\n  Nombre del archivo: ";
            getline(cin, archivo);

            cout << "  Nombre del usuario: ";
            getline(cin, usuario);

            cout << "  Numero de paginas: ";
            cin >> paginas;
            cin.ignore();

            if (paginas <= 0)
            {
                color(12);
                cout << "\n  El numero de paginas debe ser mayor que cero.\n";
                color(7);
            }
            else
            {
                cola.encolar(archivo, usuario, paginas);
            }

            pausa();
            break;

        case 2:

            imprimirDocumento(cola);

            pausa();
            break;

        case 3:

            cola.mostrarCola();

            pausa();
            break;

        case 4:

            cola.cantidadElementos();

            pausa();
            break;

        case 5:

            cola.mostrarFrente();

            pausa();
            break;

        case 6:

            cola.mostrarPag();

            pausa();
            break;

        case 7:

            color(14);
            cout << "\n  BUSCAR DOCUMENTO\n";
            color(7);

            cout << "\n  Nombre del archivo: ";
            getline(cin, archivo);

            cola.buscarDoc(archivo);

            pausa();
            break;

        case 8:

            cola.totalPag();

            pausa();
            break;

        case 0:

            color(10);
            cout << "\n  Cerrando administrador de impresion...\n";
            cout << "  Gracias por utilizar PRINT MANAGER PRO.\n";
            color(7);

            Sleep(1000);
            break;

        default:

            color(12);
            cout << "\n  Opcion invalida. Seleccione una opcion del menu.\n";
            color(7);

            pausa();
            break;
        }

    } while (opcion != 0);

    return 0;
}