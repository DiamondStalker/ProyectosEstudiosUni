#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
using namespace std;

void mostrarVector(const vector<char> &vec)
{
    cout << "Vector actual: ";
    for (const auto &val : vec)
    {
        if (val == '\0')
        {
            cout << "null-";
        }
        else
        {
            cout << val << "-";
        }
    }
    cout << endl;
}

vector<char> inicialiozarVector()
{
    std::srand(std::time(0));
    vector<char> vec(10);
    for (int i = 0; i < 5; ++i)
    {
        vec[i] = 'A' + std::rand() % 20 + 1;
    }
    return vec;
}

void buscarValor(const vector<char> &vec)
{
    system("cls");
    cout << "Ingresa el valor a buscar: ";
    char valor;
    cin >> valor;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == valor)
        {
            cout << "El valor " << valor << " fue encontrado en la posicion: " << i  + 1<< endl;
            return;
        }
    }
    cout << "El valor " << valor << " no fue encontrado en el vector." << endl;
}

vector<char> insertarValorInicio(vector<char> &vec)
{
    if (vec[vec.size() - 1] != '\0')
    {
        cout << "El vector esta lleno, no se puede insertar un nuevo valor al inicio." << endl;
        return vec;
    }
    else
    {
        system("cls");
        cout << "Ingresa el valor a insertar al inicio: ";
        char valorInicio;
        cin >> valorInicio;

        vector<char> nuevoVec(vec.size());
        nuevoVec[0] = valorInicio;
        for (size_t i = 0; i < vec.size() - 1; ++i)
        {
            nuevoVec[i + 1] = vec[i];
        }
        return nuevoVec;
    }
}

int main()
{
    int options = -1;
    int posicionesLlenas = 5;
    vector<char> vectorValores = inicialiozarVector();

    do
    {
        cout << "==MENU==\n";
        cout << "1. Mostrar el vector actual\n";
        cout << "2. Buscar un valor dentro del vector\n";
        cout << "3. Insertar un valor al inicio\n";
        cout << "4. Insertar un valor al Final\n";
        cout << "5. Insertar un valor al en una posicion espesifica\n";
        cout << "0. Exit\n";
        cout << "====================\n";
        cout << "Ingresa tu opcion: ";
        cin >> options;

        switch (options)
        {
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;

        case 1:
            mostrarVector(vectorValores);
            break;

        case 2:
            buscarValor(vectorValores);
            break;
        case 3:
            vectorValores = insertarValorInicio(vectorValores);
            break;
        default:
            cout << "Opcion invalida. Por favor, ingresa una opcion valida." << endl;
            break;
        }
    } while (options != 0);
}