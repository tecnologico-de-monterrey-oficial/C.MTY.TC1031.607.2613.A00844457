#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>
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


void shellSort(vector<Registro>& registros){
    int gap = registros.size()/2;

    while (gap>0){
        for (int i = gap; i<registros.size(); i++){

            int j = i;

            while (j>=gap && compFechas(registros[j], registros[j-gap])){

                Registro temporal = registros[j];
                registros[j]= registros[j-gap];
                registros[j-gap] = temporal;

            
                j = j-gap;
            }

        }

        gap = gap/2;
    }

}

// Merge Sort


void Merge(vector<Registro>& registros, int left,int mid, int right ){
    
    vector<Registro> izquierda;
    for(int i = left;i<=mid; i++ ){
        izquierda.push_back(registros[i]);
    }


    vector<Registro>derecha;
    for (int j = mid +1; j<= right; j++){
        derecha.push_back(registros[j]);

    }

    int i = 0;
    int j =0;
    int index = left;

    while(i<izquierda.size() && j<derecha.size()){

        if(compFechas(izquierda[i], derecha[j])){

            registros[index] = izquierda[i];
            i++;
            
        } else {
            registros[index] = derecha[j];
            j++;
        }

        index++;


    }

    while (i<izquierda.size()){
        registros[index] = izquierda[i];
        i++;
        index++;
    }

    while(j<derecha.size()){
        registros[index] = derecha[j];
        j++;
        index++;
    }


}

void MergeSort(vector<Registro>& registros, int left, int right){
    if(left<right){
        int mid = (left + right)/2;

        MergeSort(registros, left, mid);
        MergeSort(registros, mid+1, right);
        Merge(registros, left, mid, right);


    }

}

// quick sort

int getPivot(vector<Registro>& registros, int left, int right){

    int aux = left -1;
    int pivot = right;

    for (int i = left; i<pivot; i++){
        if(compFechas(registros[i], registros[pivot])){
            aux++;

            Registro temporal = registros[aux];
            registros[aux] = registros[i];
            registros[i] = temporal;
            
        }
    }

    aux++;
    Registro temporal = registros[aux];
    registros[aux] = registros[pivot];
    registros[pivot] = temporal;

    return aux;


}

void QuickSort(vector<Registro>& registros, int left, int right){
    if(left<right){

        int pivot = getPivot(registros, left, right);
        QuickSort(registros, left, pivot -1);
        QuickSort(registros, pivot + 1, right);


    }
}

void swapSort(vector<Registro>& registros){
    for(int i = 0; i<registros.size(); i++){
        for(int j = i +1 ; j<registros.size(); j++){

            if(compFechas(registros[j], registros[i])){

                Registro cambiar = registros[j];
                registros[j] = registros[i];
                registros[i] = cambiar;
            }
        }
    }
}

// --------------Busqueda Binaria -------------------------
int buscarInicio(vector<Registro>& registros, Registro fechaInicial){
    int left = 0;
    int right = registros.size() -1;
    int resultados = registros.size();

    while (left<=right){
        int mid = (left + right)/2;

        if(!compFechas(registros[mid], fechaInicial)){
         resultados = mid;
            right = mid -1;
        
        }else{
            left = mid +1;
        }
    }

    return resultados;

    
}


int busquedaFinal(vector<Registro>& registros, Registro fechaFinal){
    int left = 0;
    int right = registros.size() -1;
    int resultados = -1;

    while (left<=right){
        int mid = (left + right)/2;

        if(!compFechas(fechaFinal, registros[mid])){
         resultados = mid;
            left = mid + 1;
        
        }else{
            right = mid - 1;
        }
    }

    return resultados;

}





int main (){
    int continuar = 1;

    while(continuar == 1){

        // abrir archivos
        int opcionArchivo;
        ifstream archivo;
        string nombreArchivo;

        cout<< "=========== Menú================"<< endl; 
        cout<< "Escriba 1 para escoger el archivo  log607-1.txt (desordenado)" <<endl;
        cout<< "Escriba 2 para  escoger el archivo log607-2.txt (casi ordenado)"<< endl; 
        cin>>opcionArchivo;

        if (opcionArchivo == 1){
            archivo.open("log607-1.txt");
            nombreArchivo = "log607-1.txt";

        } else if (opcionArchivo == 2){
            archivo.open("log607-2.txt");
            nombreArchivo = "log607-2.txt";

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
        cout << "1. Swap Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Selection Sort" << endl;
        cout << "4. Insertion Sort" << endl;
        cout << "5. Shell Sort" << endl;
        cout << "6. Merge Sort" << endl;
        cout << "7. Quick Sort" << endl;

        int opcionSort;
        cin >> opcionSort;
        vector<Registro> copia = registros;

        string tipoAlgoritmo;
        string mejorCaso;
        string peorCaso;
        string prediccion;
        string justificacion;



        cout<<"Antes de ejecutar el algoritmo, como crees que sera su rendimiento?"<<endl;
        cout<<"1. Rapido"<<endl;
        cout<<"2. Lento"<<endl;
        int opcionPrediccion;
        cin>>opcionPrediccion;

        if(opcionPrediccion == 1){
            prediccion = "Rapido";
        } else if(opcionPrediccion == 2){
            prediccion = "Lento";
        }

        cin.ignore();
        cout<<"Por que crees que tendra ese rendimiento? ";
        getline(cin, justificacion);

        auto tiempoInicial = chrono::high_resolution_clock::now();

        if(opcionSort ==1){
            tipoAlgoritmo = "Swap Sort";
            mejorCaso = "O(n^2)";
            peorCaso = "O(n^2)";
            swapSort(copia);

        } else if(opcionSort == 2){
            tipoAlgoritmo = "Bubble Sort";
            mejorCaso = "O(n^2)";
            peorCaso = "O(n^2)";
            BubbleSort(copia);

        }else if(opcionSort == 3){
            tipoAlgoritmo = "Selection Sort";
            mejorCaso = "O(n^2)";
            peorCaso = "O(n^2)";
            SelectionSort(copia);

        } else if(opcionSort == 4){
            tipoAlgoritmo = "Insertion Sort";
            mejorCaso = "O(n)";
            peorCaso = "O(n^2)";
            InsertionSort(copia);

        } else if(opcionSort == 5){
            tipoAlgoritmo = "Shell Sort";
            mejorCaso = "O(n log n)";
            peorCaso = "O(n^2)";
            shellSort(copia);
    
        } else if(opcionSort == 6){
            tipoAlgoritmo = "Merge Sort ";
            mejorCaso = "O(n log n)";
            peorCaso = "O(n log n)";
            MergeSort(copia, 0, copia.size()-1);
        } else if(opcionSort==7){
            tipoAlgoritmo = " Quick Sort";
            mejorCaso = "O(n log n)";
            peorCaso = "O(n^2)";
            QuickSort(copia, 0, copia.size() -1);

        }

        auto tiempoFinal = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::microseconds>(tiempoFinal - tiempoInicial);

        string resultadoPrediccion;
        string comparacionPrediccion;

        if(duracion.count() < 1000000){
            resultadoPrediccion = "Rapido";
        } else{
            resultadoPrediccion = "Lento";
        }

        if(prediccion == resultadoPrediccion){
            comparacionPrediccion = "La prediccion coincidio con el resultado";
        } else{
            comparacionPrediccion = "La prediccion no coincidio con el resultado";
        }

        cout << "Algoritmo: " << tipoAlgoritmo << endl;
        cout<<"Archivo: "<<nombreArchivo<<endl;
        cout<<"Cantidad de registros: "<<copia.size()<<endl;
        cout << "Mejor caso: "<<mejorCaso<<endl;
        cout<<"Peor caso: "<<peorCaso<<endl;
        cout<<"Tiempo de duración: "<<duracion.count()<<" microsegundos"<<endl;
        cout<<"Prediccion: " << prediccion << endl;
        cout<<"Justificacion: "<<justificacion<<endl;
        cout<<"Resultado observado: "<<resultadoPrediccion<<endl;
        cout<<comparacionPrediccion<<endl;
        

        // --------------------Archivo final ------------------------

        ofstream archivoFinal("output608.txt");

        for(int i = 0; i<copia.size(); i++){
            archivoFinal<<copia[i].mes<<" "<<copia[i].dia<<" "
            <<copia[i].anno<<" "<<copia[i].hora<<" "
            <<copia[i].ip<<copia[i].contenido<<endl;
        }
        archivoFinal.close();
        cout<<"Los registros ordenados fueron guardados en output608.txt"<<endl;


        //Registros
        Registro fechaIncial;
        Registro fechaFinal;

        cout<<"Fecha inicial (Mes, Dia, Anno, Hora): ";
        cin>>fechaIncial.mes>>fechaIncial.dia>>fechaIncial.anno>>fechaIncial.hora;

        cout<<"Fecha final (Mes, Dia, Anno, Hora): ";
        cin>>fechaFinal.mes>>fechaFinal.dia>>fechaFinal.anno>>fechaFinal.hora;

        int posicionIncio = buscarInicio(copia, fechaIncial);
        int posicionFinal = busquedaFinal(copia, fechaFinal);

        // ARchivo Rage

        if (posicionIncio<= posicionFinal){

            ofstream resultados("range607.txt");

            for(int i = posicionIncio; i<=posicionFinal; i++){
                resultados <<copia[i].mes<< " "<<copia[i].dia<< " "
                <<copia[i].anno<< " "<<copia[i].hora<< " "
                <<copia[i].ip<<copia[i].contenido<<endl;
            }

            cout<< "Los resultados fueron guardados en range607.txt"<<endl;


        }  else {
            cout << "No se encontraron registros en ese rango" << endl;
        }


        cout<<"Deseas realizar otra corrida?"<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. No"<<endl;
        cin>>continuar;

        
    }

    return 0; 


    
}