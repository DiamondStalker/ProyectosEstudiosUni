#include <iostream>
using namespace std;

int main(){

    int zonas;
    int votantes;

    cout << "Digite la cantidad de zonas: ";
    cin >> zonas;

    int votosA[100];
    int votosB[100];
    int nulos[100];
    int blancos[100];

    int totalA = 0;
    int totalB = 0;
    int totalNulos = 0;
    int totalBlancos = 0;


    for(int i = 0; i < zonas; i++){

        cout << "\nZona " << i+1 << endl;

        cout << "Cantidad de votantes: ";
        cin >> votantes;


        votosA[i] = 0;
        votosB[i] = 0;
        nulos[i] = 0;
        blancos[i] = 0;


        for(int j = 0; j < votantes; j++){

            char voto;

            cout << "Voto " << j+1 << " (A/B/N/E): ";
            cin >> voto;


            if(voto == 'A'){
                votosA[i]++;
            }
            else if(voto == 'B'){
                votosB[i]++;
            }
            else if(voto == 'N'){
                nulos[i]++;
            }
            else if(voto == 'E'){
                blancos[i]++;
            }
        }


        totalA += votosA[i];
        totalB += votosB[i];
        totalNulos += nulos[i];
        totalBlancos += blancos[i];

    }


    cout << "\n----- RESULTADOS POR ZONA -----\n";


    for(int i = 0; i < zonas; i++){

        int total = votosA[i] + votosB[i] + nulos[i] + blancos[i];


        cout << "\nZona " << i+1 << endl;

        cout << "Candidato A: " << votosA[i] 
             << " (" << (votosA[i]*100.0)/total << "%)" << endl;

        cout << "Candidato B: " << votosB[i] 
             << " (" << (votosB[i]*100.0)/total << "%)" << endl;

        cout << "Nulos: " << nulos[i] << endl;

        cout << "Blancos: " << blancos[i] << endl;


        if(votosA[i] > votosB[i]){
            cout << "Ganador zona: Candidato A\n";
        }
        else if(votosB[i] > votosA[i]){
            cout << "Ganador zona: Candidato B\n";
        }
        else{
            cout << "Empate\n";
        }

    }


    cout << "\n----- RESULTADO GENERAL -----\n";


    int totalVotos = totalA + totalB + totalNulos + totalBlancos;


    cout << "Candidato A: " << totalA 
         << " (" << (totalA*100.0)/totalVotos << "%)" << endl;

    cout << "Candidato B: " << totalB 
         << " (" << (totalB*100.0)/totalVotos << "%)" << endl;


    if(totalA > totalB){

        cout << "Ganador general: Candidato A\n";
        cout << "Gano con " << totalA << " votos\n";
        cout << "Diferencia: " << totalA-totalB << " votos\n";

    }
    else if(totalB > totalA){

        cout << "Ganador general: Candidato B\n";
        cout << "Gano con " << totalB << " votos\n";
        cout << "Diferencia: " << totalB-totalA << " votos\n";

    }
    else{

        cout << "Resultado general: Empate\n";

    }


    return 0;
}