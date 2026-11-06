#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class ExpresionElemento{
public: 
    char tipo;
    float valor;

    ExpresionElemento(char t, float v){
        tipo = t;
        valor = v;
    }
};

class Nodo{
    public:
    Nodo* siguiente;
    float dato;
    Nodo(float valor){
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

    bool pilaVacia(){
        if(cima == nullptr){
            return true;
        }
        return false;
    }
    void push(float x){
        Nodo* nuevo = new Nodo(x);
        nuevo->siguiente = cima;
        cima = nuevo;
    }
    float pop(){
        if(pilaVacia()){
            cout << "La pila esta vacia"<<endl;
            return 0;
        }
        else{
            float valor = cima->dato;
            Nodo* temp = cima;
            cima = cima->siguiente;
            delete temp;
            return valor;
        }
    }
    void mostrarPila(){
        Nodo* temp  = cima;
        while(temp!=nullptr){
            cout << temp->dato<<"->"<<endl;
            temp = temp->siguiente;
        }
        cout << "-> NULL"<<endl;
    }

};
class EvaluadorPosDijo{
    private:
        Pila pila;
        float operar(float a, float b, char control){
            switch (control)
            {
               case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': 
            if(b==0){
                cout << "No se puede divir entre 0";
                return 0;
            }else{
               return a / b; 
            }
            return a / b;
            case '^': return pow(a, b);
            default:
                cout << "Opcion no valida" << endl;
                return 0;
            }
        }
public:
    int contarOperandos(ExpresionElemento expr[]){
        int contador_x =0;
        int i = 0;
   while (!(expr[i].tipo == 'r' && (char)expr[i].valor == '#')) {
           if(expr[i].tipo == 'v'){
        contador_x++;
       
        
    } i++;
            }
            
        
        return contador_x;
    }
    int contarOperadores(ExpresionElemento expr[]){
    int contador = 0;
    int i = 0;

    while (!(expr[i].tipo == 'r' && (char)expr[i].valor == '#')) {
        if(expr[i].tipo == 'r'){
            contador++;
        }
        i++;
    }

    return contador;
}




    float evaluar(ExpresionElemento expr[]) {
        int i = 0;
        
        while (!(expr[i].tipo == 'r' && (char)expr[i].valor == '#')) {
            if (expr[i].tipo == 'v') {
                pila.push(expr[i].valor);
            } else {
                float b = pila.pop();
                float a = pila.pop();
                float R = operar(a, b, (char)expr[i].valor);
                pila.push(R);
            }
            i++;
        }
        return pila.pop();
    }
};
int main() {
    
ExpresionElemento expr[] = {
{'v', 8}, {'v', 2}, {'r', '+'},
{'v', 3}, {'v', 4}, {'v', 2}, {'r', '*'}, {'r', '+'},
{'r', '*'},
{'v', 6}, {'v', 3}, {'r', '/'},
{'r', '-'},
{'v', 2}, {'v', 3}, {'r', '^'},
{'r', '+'},
{'r', '#'}
    }; 
    
    EvaluadorPosDijo evaluador;
    float Resultado = evaluador.evaluar(expr);
    cout << "El resultado es: " << Resultado << endl;
    cout << "Hay: "<<evaluador.contarOperandos(expr)<<" operandos"<<endl;
    cout << "Hay: "<<evaluador.contarOperadores(expr)<<" operadores"<<endl;

    return 0;
}
