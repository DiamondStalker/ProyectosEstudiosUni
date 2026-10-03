#include <iostream>
using namespace std;

//Este codigo no me dio pa hacerlo con el comando variant pa definir si el arrelo o era float o entero
class Sensor{
private:
    float temperatura[7];
    int contador;
    int n;

public:

    Sensor(){
        n = 7;
        contador = 0;

        for(int i = 0; i < n; i++){
            temperatura[i] = 0;
        }
    }

    void recepcionDatos(float datos){

        if(contador < n){
            temperatura[contador] = datos;
            contador++;
        }
    }

    float obtenerDatos(int posicion){
        return temperatura[posicion];
    }

    virtual void mostrarDatos(){
        cout << "=== DATOS ===" << endl;
    }
};


class SensorAnalogico : public Sensor{
private:
    int n;

public:

    SensorAnalogico(){
        n = 7;
    }

    void mostrarDatos(){

        cout << "\n=== SENSOR ANALOGICO ===" << endl;

        for(int i = 0; i < n; i++){

            cout << "Dia #" << i + 1 << ": "
                 << obtenerDatos(i)
                 << " °C" << endl;
        }
    }
};


class SensorDigital : public Sensor{
private:
    int n;

public:

    SensorDigital(){
        n = 7;
    }

    void mostrarDatos(){

        cout << "\n=== SENSOR DIGITAL ===" << endl;

        for(int i = 0; i < n; i++){

            cout << "Dia #" << i + 1 << ": "
                 << (int)obtenerDatos(i)
                 << " °C" << endl;
        }
    }
};


int main(){

    int n = 7;

    SensorAnalogico analogico;
    SensorDigital digital;

    float datosAnalogicos;

    cout << "=== INGRESO DE TEMPERATURAS ANALOGICAS ===" << endl;

    for(int i = 0; i < n; i++){

        cout << "Ingrese temperatura del dia #" << i + 1 << ": ";
        cin >> datosAnalogicos;

        analogico.recepcionDatos(datosAnalogicos);
    }


    int datosDigitales;

    cout << "\n=== INGRESO DE TEMPERATURAS DIGITALES ===" << endl;

    for(int i = 0; i < n; i++){

        cout << "Ingrese temperatura del dia #" << i + 1 << ": ";
        cin >> datosDigitales;

        digital.recepcionDatos(datosDigitales);
    }


   

    Sensor* sensor;

    sensor = &analogico;
    sensor->mostrarDatos();

    sensor = &digital;
    sensor->mostrarDatos();


    return 0;
}