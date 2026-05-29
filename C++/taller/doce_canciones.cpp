#include<iostream>
#include<string>
using namespace std;
int main(){
string canciones[20];
string buscar,nueva;
int opcion;
canciones[0] = "Lola - Jedis";
canciones[1] = "Manifiestate - Dani y Magneto";
canciones[2] = "Perreo en la Disco - Los Farandulay";
canciones[3] = "Cuidado - Hector el Father ";
canciones[4] = "Sacala - Daddy Yankee";
do{
    cout << "\n===MENU===\n"
         << "1. Mostrar Canciones Favoritas\n"
         << "2. Buscar Cancion\n"
         << "3. Agregar Cancion\n"
         << "4. Salir\n";
    cout << "Escoga una Opcion: ";
    cin >> opcion;
    
    switch (opcion)
    {
    case 1:
    cout << "HAZ INGRESADO A LA OPCION 1: Mostrar Canciones Favoritas"<<endl;
    for(int i = 0; i<20; i++){
        cout << "Fav "<< i +1 << canciones[i]<<endl;
    }
    break;
    case 2:
    cout << "HAZ INGRESADO A LA OPCION 2: Buscar Cancion"<< endl;
    cout << "Al Buscar la Cancion, busquela con el (Nombre de la cancion)-(Autor de la Cancion)"<<endl;
    cout << "Nombre a buscar: ";
    cin >> buscar;
    for(int i = 0; i<20; i++){
        if(canciones[i]==buscar){
            cout<< "La cancion se encontro en tus favoritos en la posicion "<<i+1<<endl;
        }
        else{
            cout << "La cancion no se encontro en tus favoritos"<<endl;
        }
    }

    break;
    case 3:
        cout << "HAZ INGRESADO A LA OPCION 3: Agregar Cancion"<<endl;
        cout << "Al Agregar la cancion porfavor colocar el orden incluyendo el(-), NombreCancion-AutorCancion"<<endl;
        cout << "Nombre a Agregar: ";
        cin >> nueva;
    break;
    case 4:
    cout << "Saliendo..."<<endl;
        break;
    
    default:
    cout << "Opcion Invalida"<<endl;
        break;
    
    
    }
}while(opcion!=4);
return 0;
}