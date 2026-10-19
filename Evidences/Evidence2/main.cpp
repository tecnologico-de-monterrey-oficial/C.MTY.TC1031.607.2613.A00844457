//Allison Charlize Arriaza Chachagua 
// A00844457

#include <iostream>
#include <string>
#include <fstream>
#include "log.h"
using namespace std;


int main(){
    int opcion;
    string nombreArchivo;

    cout<<"===============MENU=============================="<<endl;
    cout<<"Que archivo desea cargar?"<<endl;
    cout<<"Para log607-1.txt ingrese 1"<<endl;
    cout<<"Para log607-2.txt ingrese 2"<<endl;
    cin>>opcion;

    if(opcion == 1){
        nombreArchivo = "log607-1.txt";
    } else if(opcion == 2){
        nombreArchivo = "log607-2.txt";
    } else{
        cout<<"Error intente nuevamente";
        return 1;
    }

    ifstream abrirArchivo(nombreArchivo);

    if(!abrirArchivo.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        return 1;

    }  else {
        cout<<"Los archivos se pudieron abrir"<<endl;
    }

    Log registro;
    int cont;

    while(true){
        abrirArchivo>> registro.mes;
        abrirArchivo>> registro.fecha;
        abrirArchivo>> registro.anno;
        abrirArchivo>> registro.hora;
        abrirArchivo>> registro.ip;
        abrirArchivo>> registro.mensaje;

        if (!abrirArchivo){
            break;
        }

        getline(abrirArchivo, registro.mensaje);
        cont ++;
    }

    cout<<"Total de registros: "<<cont<<endl;

    return 0;
}