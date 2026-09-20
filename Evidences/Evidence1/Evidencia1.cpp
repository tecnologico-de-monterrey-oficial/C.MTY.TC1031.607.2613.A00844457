#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std; 

struct Registro {
    string mes;
    int dia;
    int anno;
    string hora;
    string ip;
    string contenido;
};


int main (){

    // abrir archivos

    int opcionArchivo;
    ifstream archivo;

    cout<< "=========== Menú================"<< endl; 
    cout<< "Escriba 1 para escoger el archivo  log607-1.txt (desordenado)" <<endl;
    cout<< "Escriba 2 para  escoger el archivo log607-2.txt (casi ordenado)"<< endl; 
    cin>>opcionArchivo;

    if (opcionArchivo == 1){
        archivo.open("log607-1.txt");

    } else if (opcionArchivo == 2){
        archivo.open("log607-2.txt");

    } else {
        cout<<"Error al cargar"<<endl;
    }

    // leer lineas del archivo
    vector<Registro> registros;
    string linea;

    while(getline(archivo, linea)){
        Registro dato;
        stringstream ss(linea);

        ss>>dato.mes;
        ss>>dato.dia;
        ss>>dato.anno;

        getline(ss, dato.contenido);
        registros.push_back(dato);
    }

    cout<<"# total de registros: "<<registros.size()<<endl;

    // for (int i = 0; i<registros.size(); i++){


    // }
    






    return 0;  
}