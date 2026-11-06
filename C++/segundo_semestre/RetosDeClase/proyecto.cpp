#include <iostream>
#include<string>
#include<sstream>
#include<windows.h>

using namespace std;

void color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

class nodo{
	public:
		string archivo;
		string usuario;
		int paginas;
		nodo* siguiente;
		
		nodo(string arch, string usua, int pag){
			archivo = arch;
			usuario = usua;
			paginas = pag;
			siguiente = NULL;
		}
		
};

class impresion{
	private:
		nodo* inicio;
		nodo* final;
	public:
		impresion (){
			inicio = NULL;
			final = NULL;
		}
		bool colaVacia (){
			return inicio == NULL;
		}
		
		void encolar (string arch, string usua, int pag){
			nodo* nuevo = new nodo (arch, usua, pag);
			if (colaVacia ()){
				inicio = final = nuevo;
			}
			final->siguiente=nuevo;
			final=nuevo;
		}
		
		void desencolar (){
			if (colaVacia ()){
				cout<<"No hay documentos pendientes de impresion. << endl";
				return;
			}
			nodo* temp = inicio;
			inicio=inicio->siguiente;
			delete temp; 
			if (inicio == NULL){
				final = NULL;
			}
		}
		void mostrarCola (){
			if (colaVacia()){
				cout<<"No hay documentos pendientes de impresion. << endl";
				return;
			}
			nodo* temp = inicio;
			cout << "DOCUMENTOS PENDIENTES DE IMPRESION:" << endl << endl;
			
			while (temp!=NULL){
				cout << "Archivo: " << temp->archivo << endl;
				cout << "Usuario: " << temp->usuario << endl;
				cout << "Numero de paginas: " << temp->paginas << endl;
				cout << "-----------------------------" << endl;
				temp = temp->siguiente;
			}
		}
		void cantidadElementos (){
			if (colaVacia()){
				cout<<"No hay documentos pendientes de impresion." << endl;
				return;
			}
			int contador = 0;
			nodo* temp = inicio;
			while (temp!=NULL){
				contador++;	
				temp = temp->siguiente;
			}
			cout<<"Cantidad de documentos pendientes: "<<contador << endl;
			
		}
			void mostrarFrente (){
			if (colaVacia()){
				cout<<"No hay documentos pendientes de impresion." << endl;
				return;
			}
			cout << "SIGUIENTE DOCUMENTO A IMPRIMIR:" << endl << endl;
			cout << "Archivo: " << inicio->archivo << endl;
			cout << "Usuario: " << inicio->usuario << endl;
			cout << "Numero de paginas: " << inicio->paginas << endl;
	}		
		void mostrarPag(){
			if (colaVacia()){
				cout<<"No hay documentos pendientes de impresion." << endl;
				return;
			}
			cout<< "Numero de paginas del siguiente documento: ";
			cout<< inicio->paginas << endl;
		}
		
		void buscarDoc(string n){
			if(colaVacia()){
				cout<<"No hay documentos pendientes de impresion." << endl;
				return;
			}
			nodo* temp = inicio;
			
			while(temp != NULL){
				if(temp->archivo == n){
					cout << "Se ha encontrado el documento." << endl;
					cout << "Usuario: " << temp->usuario << endl;
					cout << "Paginas: " << temp->paginas << endl;
					return;
				}
				temp = temp->siguiente;
			}
			cout << "No se encontro el documento." << endl;
		}
		
		void totalPag(){
			if(colaVacia()){
				cout<<"No hay paginas pendientes para imprimir." << endl;
				return;
			}
			nodo* temp = inicio;
			int total = 0;
			
			while(temp != NULL){
				total += temp->paginas;
				temp = temp->siguiente;
			}
			cout << "El total de paginas pendientes es: " << total << endl;
		}
		
};
int main (){
	return 0;
}
