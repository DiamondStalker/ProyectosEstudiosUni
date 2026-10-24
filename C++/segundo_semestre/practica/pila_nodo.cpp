#include<iostream>
using namespace std;
class Nodo{
    public:
 int dato;
 Nodo* siguiente;

 Nodo(int valor){
    dato = valor;
    siguiente = nullptr;
 }

};
class Pila{
private:
    Nodo* cima;
    public:
    Pila(){
        
            cima = nullptr;
    }

    void insertar(int valor){
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cima;
        cima = nuevo;
        cout << "insertado"<<endl;
    }
    void elimiar(){
        if(cima == nullptr){
            cout << "la pila esta vacia"<<endl;
     }
     else{
        Nodo* aux = cima;
        cout << "El dato a eliminar sera: "<< cima->dato<<endl;
        cout << "eliminado"<<endl;
        cima = cima->siguiente;
        delete aux;
     }
    }

    void mostrar(){
        if(cima == nullptr){
            cout << "la pila esta vacia "<<endl;

        }
        else{
            Nodo* aux = cima;
            while(aux!=nullptr){
                cout << aux->dato<< "->";
                aux = aux->siguiente;
            }
        }
    }
};