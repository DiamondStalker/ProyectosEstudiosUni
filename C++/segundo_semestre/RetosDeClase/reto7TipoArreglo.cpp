#include<iostream>
#include<string>
#include <windows.h>
#define tam 5
using namespace std;
/*teacher que pena andar de creativo, voy a hacerlo todo muy visual, las funciones nuevas las voy a documentar igualmente solo es para mejorar
la interfaz
*/

class pila{
    private: 
        int cima;
    
        string arreglo[tam];
    public:
        pila(){
            cima = -1;
        }
        bool pilallena(){
            if(cima == tam -1){
                return true;
            }
            return false;
        }
        bool pilaVacia(){
            if(cima == -1){
                return true;
            }
            return false;
        }

        void push(string url){
            if(pilallena()){
                cout << "Paga para tener mas pestañas abiertas"<<endl;
                Sleep(2000);
            }
            else
            {
                cima++;
                arreglo[cima] = url;
                cout << "Buscando..."<<endl;
                Sleep(1000);//lo hice para estar simulando una barra de progreso.
                cout << "Redirigiendo"<<endl;
                Sleep(1000);//x2.
            }


  
        }
    void pop(){
    
    string nada;
    if(pilaVacia()){
        system("cls");//para que solo se muestre 1 sola cosa y no todo pero apilado(limpiar la consola).
        cout << "============================================================\n";
        cout << "|                       POLI BROWSER                       |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                   NO HAY PESTANAS ABIERTAS               |\n";
        cout << "|                                                          |\n";
        cout << "|             No hay paginas para restablecer              |\n";
        cout << "|__________________________________________________________|\n";
    }
    else if(cima == 0){
        system("cls");
        cout << "============================================================\n";
        cout << "|                       POLI BROWSER                       |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                 NO HAY PAGINA ANTERIOR                   |\n";
        cout << "|                                                          |\n";
        cout << "|  Solo tienes una pagina abierta:                         |\n";
        cout << "|  " << arreglo[cima] << "\n";
        cout << "|__________________________________________________________|\n";
    }
    else{
        system("cls");
        cout << "============================================================\n";
        cout << "|                       POLI BROWSER                       |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                  RESTABLECIENDO PAGINA                   |\n";
        cout << "|                                                          |\n";
        cout << "|  Cerrando pestaña actual...                              |\n";
        cout << "|  [..........                    ]                        |\n";

        Sleep(1000);//lo hice para simular barra de progreso.
        cima--;

        cout << "|  [.....................         ]                        |\n";
        Sleep(700);//tambien para simular barra de progreso.

        cout << "|  [------------------------------]                        |\n";
        cout << "|                                                          |\n";
        cout << "|                  PAGINA RESTABLECIDA                     |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|  URL actual: " << arreglo[cima] << "\n";
        cout << "|__________________________________________________________|\n";
    }

     cout << "Ingrese una letra y un enter para regresar al menu: ";
        cin >> nada;
}

        void historial() {
            string vacio;
    if (pilaVacia()) {
        system("cls");
        cout << "============================================================\n";
        cout << "|                                                          |\n";
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
        cout << "Ingrese una letra y un enter para regresar al menu: ";
        cin >> vacio;
    }
    else {
        system("cls");
        cout << "============================================================\n";
        cout << "|                       POLI BROWSER                       |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                     HISTORIAL WEB                        |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";

        for (int i = cima; i >= 0; i--) {
    cout << "|  " << arreglo[i] << "  |\n";
}

        cout << "|__________________________________________________________|\n";
        cout << "Ingrese una letra y un enter para regresar al menu: ";
        cin >> vacio;
    }
}

void actual(){
    string vacio;
    system("cls");
    if(pilaVacia()){
        cout << "============================================================\n";
        cout << "|                       POLI BROWSER                       |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                   NO HAY PESTANAS ABIERTAS               |\n";
        cout << "|__________________________________________________________|\n";
    }
    else{
        system("cls");
        cout << "============================================================\n";
        cout << "|                       POLI BROWSER                       |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                   ULTIMA PESTAÑA ABIERTA:                |\n";
        cout << "|                   " <<    arreglo[cima]        << "      |\n";
        cout << "|__________________________________________________________|\n";
        cout << "Seleccione una leta y enter para regresar al menu: ";
        cin >> vacio;

    }
}


};






int main() {
    int opcion= 0;
    string url;
    pila objeto;
    do {
            system("cls");

        cout << "============================================================\n";
        cout << "                    USUARIO BROWSER                         \n";
        cout << "============================================================\n";
        cout << "|                                                          |\n";
        cout << "|  <  >  R    https://www.poli-browser.com                 |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                      POLI                                |\n";
        cout << "|                   NAVEGADOR PERSONAL                     |\n";
        cout << "|                                                          |\n";
        cout << "|            Tu navegador, tu mundo digital                |\n";
        cout << "|                                                          |\n";
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
        cout << "|                                                          |\n";
        cout << "============================================================\n";
        switch(opcion){
            case 1:
             system("cls");

        cout << "============================================================\n";
        cout << "                    USUARIO BROWSER                         \n";
        cout << "============================================================\n";
        cout << "|                                                          |\n";
        cout << "|  <  >  R    https://www.poli-browser.com                 |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                      POLI                                |\n";
        cout << "|                   NAVEGADOR PERSONAL                     |\n";
        cout << "|                                                          |\n";
        cout << "|            Tu navegador, tu mundo digital                |\n";
        cout << "|                                                          |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                   Visitar nueva pagina                   |\n";
        cout << "|                                                          |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|  Url: "; 
       cin >> url;
        cout << "|                                                          |\n";
        cout << "============================================================\n";
        objeto.push(url);


            break;
            case 2:
            objeto.pop();
            break;
            case 3:
            objeto.historial();
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
        cout << "|  <  >  R    https://www.poli-browser.com                 |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                      POLI                                |\n";
        cout << "|                   NAVEGADOR PERSONAL                     |\n";
        cout << "|                                                          |\n";
        cout << "|            Tu navegador, tu mundo digital                |\n";
        cout << "|                                                          |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                   SALIENDO DEL NAVEGADOR                 |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|__________________________________________________________|\n";
            break;
            default:
            system("cls");
        cout << "============================================================\n";
        cout << "                    USUARIO BROWSER                         \n";
        cout << "============================================================\n";
        cout << "|                                                          |\n";
        cout << "|  <  >  R    https://www.poli-browser.com                 |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                      POLI                                |\n";
        cout << "|                   NAVEGADOR PERSONAL                     |\n";
        cout << "|                                                          |\n";
        cout << "|            Tu navegador, tu mundo digital                |\n";
        cout << "|                                                          |\n";
        cout << "|__________________________________________________________|\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                  ERROR 404  Bad Request                  |\n";
        cout << "|                    INTENTE DE NUEVO                      |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|                                                          |\n";
        cout << "|__________________________________________________________|\n";
         Sleep(3000);
            break;
        }

    } while (opcion != 5);

    return 0;
}