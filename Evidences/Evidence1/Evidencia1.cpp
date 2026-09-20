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

// ------------------Asignacion numericsa de los meses-------------------

int convertMeses(string mes){
    if(mes == "Jan"){
        return 1;
    } else if (mes == "Feb"){
        return 2;
    } else if (mes == "Mar"){
        return 3;
    } else if (mes == "Apr"){
        return 4;
    } else if (mes == "May"){
        return 5;
    } else if(mes == "Jun"){
        return 6;
    } else if(mes == "Jul"){
        return 7;
    } else if (mes == "Aug"){
        return 8;
    }else if (mes == "Sep"){
        return 9;
    }else if (mes == "Oct"){
        return 10;
    }else if (mes == "Nov"){
        return 11;
    }else if (mes == "Dec"){
        return 12;
    }

    return 0;

}

// -----------------Conversion de tiempo-----------------------

int convertirTiempo(string hora){
    int h;
    int min; 
    int s;
    char dosPuntos;

    stringstream ssHora(hora);
    ssHora>>h>>dosPuntos>>min>>dosPuntos>>s;

    return h * 3600 + min * 60 + s;
}

bool compFechas(Registro primer, Registro segundo){
    if(primer.anno< segundo.anno){
        return true;
    } else if (primer.anno>segundo.anno){
        return false;
    }

    // Annos iguales, meses diferentes

    int mes1 = convertMeses(primer.mes);
    int mes2 = convertMeses(segundo.mes);

    if(mes1<mes2){
        return true; 
    } else if(mes1>mes2){
        return false;
    }

    // Meses iguales, dia diferente;

    if(primer.dia<segundo.dia){
        return true; 
    } else if(primer.dia>segundo.dia){
        return false;
    }

    if (convertirTiempo(primer.hora)<convertirTiempo(segundo.hora)){
        return true;
    } else{
        return false;
    }

}

//----------------- opciones de sort-----------------------------

void BubbleSort(vector<Registro>& registros){
    for (int i =0; i<registros.size()-1; i++){
        for(int j=0; j<registros.size()-1-i; j++){
            if(compFechas(registros[j+1], registros[j])){

                Registro temporal = registros[j];
                registros[j] = registros[j+1];
                registros[j+1]= temporal;

            }
        }

    }
}

void SelectionSort(vector<Registro>& registros){
    for(int i = 0;i<registros.size()-1; i++ ){

        int minimo = i;

        for(int j = i + 1; j<registros.size(); j++){
            if(compFechas(registros[j], registros[minimo])){
                minimo = j;

            }

        }

        // cambio de lugar
        if(minimo != i){
            Registro temporal = registros[i];
            registros[i] = registros[minimo];
            registros[minimo] = temporal;

        }
    }


}

void InsertionSort(vector<Registro>& registros){
    for (int i = 1; i<registros.size(); i++){

        Registro actual = registros[i];
        int j = i-1;

        while (j>= 0 && compFechas(actual, registros[j])){
            registros[j+1] = registros[j];
            j--;

        }

        registros[j+1] = actual;

    }
}




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
        ss>>dato.hora;
        ss>>dato.ip;
        

        getline(ss, dato.contenido);
        registros.push_back(dato);
    }

    cout<<"# total de registros: "<<registros.size()<<endl;

    //----------------- Ordenar registros  -------------------------

    //BubbleSort(registros);
    //SelectionSort(registros);
    InsertionSort(registros);

    for(int i =0; i<5; i++){
        cout<< registros[i].mes<<" "<<registros[i].dia<<" "
        <<registros[i].anno<< " "<<registros[i].hora<< " "
        <<registros[i].ip<<" "<<registros[i].contenido<< " "<<endl;
    }

    // for (int i = 0; i<registros.size(); i++){


    // }
    






    return 0;  
}