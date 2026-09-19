#include <iostream>
#include <fstream>
#include <vector>
using namespace std; 



int main (){

    // abrir archivos

    int opcionArchivo;
    ifstream archivo;

    cout<< "=========== Menú================"<< endl; 
    cout<< "Escriba 1 para escoger el archivo  log607-1.txt (desordenado)" <<endl;
    cout<< "Escriba 2 para  escoger el archivo log607-2.txt (casi ordenado) "<< endl; 
    cin>>opcionArchivo>>endl;

    if (opcionArchivo == 1){
        archivo.open("log607-1.txt");

    } else if (opcionArchivo == 2){
        archivo.open("log607-2.txt");

    } else {
        cout<<"Opción iválida"<<endl;
    }
    





    return 0;  
}