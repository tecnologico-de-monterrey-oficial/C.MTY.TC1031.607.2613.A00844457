//Allison Charlize Arriaza Chachagua
//A00844457

//====================================== Ejer 1=================================================

#include <iostream>
#include <vector>
#include <cstdlib> // numeros aleatorios
#include <ctime>
#include <algorithm> // para ocupar sort
#include <chrono> //medir el tiempo de búsqueda secuencial
using namespace std;




int pedirNumero(){
    int target;
    cout<<"Ingrese el numero que quisiera buscar o ingrese 0 para salir: "<<endl;
    cin>> target;

    return target;

}


// Se le agrega const porque sino mostraria el tiempo de buscar y copia de la lista de elementos
bool searchSequence( const vector<int> &randomNum, int target){
    for (int i = 0; i<randomNum.size(); i++){
        if (randomNum[i] == target){
            return true;
        } 
    }

    return false;

}

bool searchBinary(const vector<int> &randomNum, int target){
    int start = 0;
    int end = randomNum.size() -1;
    int middle; 

    while (start <= end){
        middle = (start + end)/2;

        if (randomNum[middle] == target){
            return true;
        }else if (randomNum[middle] <target){
            start = middle + 1;
        } else{
            end = middle -1 ;
        }
    }

    return false;




}





int main (){
    vector<int> randomNum;
    srand(time(0));
    
    for (int i = 0; i<10000; i++){
        int num = rand() % 1000000 +1; // si no se pone quedaría de 0:999999
        randomNum.push_back(num);

    }

    sort(randomNum.begin(), randomNum.end());

    int target = pedirNumero();

    while (target != 0){



        auto startSeq = chrono :: high_resolution_clock::now();
        bool resultSeq = searchSequence( randomNum, target);
        auto endSeq = chrono :: high_resolution_clock::now();
        auto calcSeqTime = chrono::duration_cast<chrono::nanoseconds>(endSeq - startSeq);
        // lo deje en nanosegundos porque si le pongo segundo me da 0 :(


        auto startBin = chrono :: high_resolution_clock ::now();
        bool resultBin = searchBinary(randomNum, target);
        auto endBin = chrono :: high_resolution_clock :: now ();
        auto calcBinTime = chrono :: duration_cast<chrono :: nanoseconds> (endBin - startBin); 
        // lo deje en nanosegundos porque si le pongo segundo me da 0 :(


        if (resultSeq == true){
        cout<< "Busqueda secuencial = numero encontrado"<< endl;
        } else {
            cout<< "Busqueda secuencial = numero NO encontrado"<< endl;
        }

        cout << "Tiempo secuencial: " << calcSeqTime.count() << " nanosegundos" << endl;

        if (resultBin == true){
            cout<< "Busqueda Binario = numero encontrado"<< endl;
        } else {
            cout<< "Busqueda Binario = numero NO encontrado"<< endl;
        }

        cout << "Tiempo binario: " << calcBinTime.count() << " nanosegundos" << endl;

        target = pedirNumero();


    }


    return 0;
}