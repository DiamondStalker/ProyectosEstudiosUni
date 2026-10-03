#include<iostream>
#include<string>
using namespace std;

class Estudiante{
    private:
        string nombre[3];
        float nota[3];
        int contador;
        float notaf;

    public:

        Estudiante(){
            for(int i = 0; i < 3; i++){
                nombre[i] = " ";
                nota[i] = 0.0;
            }
            contador = 0;
            notaf = 0;
        }

        void setregistrarDatosBasicos(string nom, float not){
            if(contador < 3){
                nombre[contador] = nom;
                nota[contador] = not;
                notaf += nota[contador];
                contador++;
            }
            
        }

        virtual void mostrarDatos(){
            for(int i = 0; i < 3; i++){
                cout << "Estudiante #" << i + 1 << " " << nombre[i];
                cout << " NotaFinal de: " << nota[i] << endl;
            }
        }

        float getNota(){
            return notaf/3;
        }
};

class EstudianteUniversitario : public Estudiante{
    private:
        string carrera[3];
        int contador = 0;

    public:

        EstudianteUniversitario(){
            for(int i = 0; i < 3; i++){
                carrera[i] = " ";
            }
            contador = 0;
        }

        void setregistrarDatosUniversitarios(string car){
            if(contador < 3){
                carrera[contador] = car;
                contador++;
            }
        }

        void mostrarDatos(){
            Estudiante::mostrarDatos();

            for(int i = 0; i < 3; i++){
                cout << "Estudiante #" << i + 1 << " Carrera: " << carrera[i] << endl;
            }
        }
};

class EstudianteColegio : public Estudiante{
    private:
        string grado[3];
        int contador = 0;

    public:

        EstudianteColegio(){
            for(int i = 0; i < 3; i++){
                grado[i] = " ";
            }
            contador = 0;
        }

        void setRegistrarDatosColegio(string grad){
            if(contador < 3){
                grado[contador] = grad;
                contador++;
            }
        }

        void mostrarDatos(){
            Estudiante::mostrarDatos();

            for(int i = 0; i < 3; i++){
                cout << "Estudiante #" << i + 1 << " Grado: " << grado[i] << endl;
            }
        }
};

int main(){

    string nombre;
    float nota;
    string carrera;
    string grado;

    EstudianteUniversitario EU;
    EstudianteColegio EC;

    cout << "========== ESTUDIANTES UNIVERSITARIOS ==========" << endl;

    for(int i = 0; i < 3; i++){

        cout << "\nNombre: ";
        cin >> nombre;

        cout << "Nota: ";
        cin >> nota;

        cout << "Carrera: ";
        cin >> carrera;

        EU.setregistrarDatosBasicos(nombre, nota);
        EU.setregistrarDatosUniversitarios(carrera);
    }

    cout << "\n========== ESTUDIANTES DE COLEGIO ==========" << endl;

    for(int i = 0; i < 3; i++){

        cout << "\nNombre: ";
        cin >> nombre;

        cout << "Nota: ";
        cin >> nota;

        cout << "Grado: ";
        cin >> grado;

        EC.setregistrarDatosBasicos(nombre, nota);
        EC.setRegistrarDatosColegio(grado);
    }

    cout << "\n========== UNIVERSITARIOS ==========" << endl;
    EU.mostrarDatos();

    cout << "\n========== COLEGIO ==========" << endl;
    EC.mostrarDatos();
    cout << "\n========== UNIVERSITARIOS ==========" << endl;
EU.mostrarDatos();


cout << "Promedio Universitarios: " << EU.getNota() << endl;
cout << "Promedio Colegio: " << EC.getNota() << endl;

return 0;
    

    return 0;
}