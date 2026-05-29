#include<iostream>

using namespace std;

const int n = 3;

void IngresarMatriz(int matriz[n][n]);
void MostrarMatriz(int matriz[n][n]);
void SumarElementos(int matriz[n][n]);
void BuscarElementos(int matriz[n][n]);
void MatrizIdentidad(int matriz[n][n]);
void MostrarMatrizTranspuesta(int matriz[n][n], int transpuesta[n][n]);
void MatrizSimetrica(int matriz[n][n], int transpuesta[n][n]);

int main(){

    int opcion;
    int matriz[n][n];
    int transpuesta[n][n];

    do{

        cout << "\n===MENU===\n"
             << "1. Ingresar Matriz Cuadrada\n"
             << "2. Mostrar la Matriz Ingresada\n"
             << "3. Sumar Elementos de la Matriz\n"
             << "4. Buscar Elemento en la Matriz\n"
             << "5. La Matriz es o no Identidad\n"
             << "6. Mostrar Matriz Transpuesta\n"
             << "7. La Matriz es o no Simetrica\n"
             << "8. Salir\n";

        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch(opcion){

            case 1:

                cout << "HAZ INGRESADO A LA OPCION 1\n";
                IngresarMatriz(matriz);

            break;

            case 2:

                cout << "HAZ INGRESADO A LA OPCION 2\n";
                MostrarMatriz(matriz);

            break;

            case 3:

                cout << "HAZ INGRESADO A LA OPCION 3\n";
                SumarElementos(matriz);

            break;

            case 4:

                cout << "HAZ INGRESADO A LA OPCION 4\n";
                BuscarElementos(matriz);

            break;

            case 5:

                cout << "HAZ INGRESADO A LA OPCION 5\n";
                MatrizIdentidad(matriz);

            break;

            case 6:

                cout << "HAZ INGRESADO A LA OPCION 6\n";
                MostrarMatrizTranspuesta(matriz, transpuesta);

            break;

            case 7:

                cout << "HAZ INGRESADO A LA OPCION 7\n";

                MostrarMatrizTranspuesta(matriz, transpuesta);
                MatrizSimetrica(matriz, transpuesta);

            break;

            case 8:

                cout << "Saliendo...\n";

            break;

            default:

                cout << "Opcion invalida\n";

        }

    }while(opcion != 8);

    return 0;
}


void IngresarMatriz(int matriz[n][n]){

    cout << "Digite los valores:\n";

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << "Ingrese el dato [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];

        }

    }

}


void MostrarMatriz(int matriz[n][n]){

    cout << "\nMatriz:\n";

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << matriz[i][j] << " ";

        }

        cout << endl;
    }

}


void SumarElementos(int matriz[n][n]){

    int suma = 0;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            suma += matriz[i][j];

        }

    }

    cout << "La suma de la matriz es: " << suma << endl;

}


void BuscarElementos(int matriz[n][n]){

    int buscar;
    bool encontrado = false;

    cout << "\nQue elemento desea buscar: ";
    cin >> buscar;

    for(int i = 0; i < n ; i++){

        for(int j = 0; j < n; j++){

            if(matriz[i][j] == buscar){

                encontrado = true;

            }

        }

    }

    if(encontrado){

        cout << "Elemento encontrado" << endl;

    }
    else{

        cout << "Elemento no encontrado" << endl;

    }

}


void MatrizIdentidad(int matriz[n][n]){

    bool encuentro = true;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(i == j && matriz[i][j] != 1){

                encuentro = false;

            }

            if(i != j && matriz[i][j] != 0){

                encuentro = false;

            }

        }

    }

    if(encuentro){

        cout << "La matriz es identidad" << endl;

    }
    else{

        cout << "La matriz no es identidad" << endl;

    }

}


void MostrarMatrizTranspuesta(int matriz[n][n], int transpuesta[n][n]){

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            transpuesta[j][i] = matriz[i][j];

        }

    }

    cout << "\nMatriz Transpuesta:\n";

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << transpuesta[i][j] << " ";

        }

        cout << endl;
    }

}


void MatrizSimetrica(int matriz[n][n], int transpuesta[n][n]){

    bool simetrica = true;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            if(matriz[i][j] != transpuesta[i][j]){

                simetrica = false;

            }

        }

    }

    if(simetrica){

        cout << "La matriz es simetrica" << endl;

    }
    else{

        cout << "La matriz no es simetrica" << endl;

    }

}