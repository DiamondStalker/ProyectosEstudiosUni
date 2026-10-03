#include<iostream>
#include<String>
using namespace std;
class inventario{
    private:
    string nombresP[5];
    float preciosP[5];
    int contador;

    public:
    inventario(){
        contador = 0;
        for(int i = 0; i<5; i++){
            nombresP[i] = "   ";
        }
        for(int i = 0; i<5; i++){
            preciosP[i] = 0;
        }

    }
     
    void setAgregarProducto(string nombre, float precio){
            if(contador < 5){
                
                nombresP[contador] = nombre;
                
                preciosP[contador] = precio;
                contador++;
            }

    }
    void mostrarProductos(){
    cout << "Productos y sus precios" << endl;

    for(int i = 0; i < 5; i++){
        cout << "Nombre: " << nombresP[i] << endl;
        cout << "Precio: $" << preciosP[i] << endl;
    }
}

    int calcularValorTotal(){
       int total = 0;
        for(int i = 0; i<5; i++){
            total += preciosP[i];
        }
        return total;
    }



    int getCantidad(){
        return contador;
    }


    
};


int main(){
        inventario inv;
        string nom;
        int prec;
        cout << "digite los 5 productos(nombre y precio)";
        for(int i  = 0; i<5; i++){
            cout << "Nombre: ";
            cin >> nom;
            cout << "precio: ";
            cin >> prec;
            inv.setAgregarProducto(nom,prec);
            

        }
        cout << "la suma total de los productos es de: $"<<inv.calcularValorTotal();
        inv.mostrarProductos();
        cout << "La cantidad de elementos registrados: "<<inv.getCantidad();

    }