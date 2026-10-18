// Allison Charlize Arriaza Chachagua
// A00844457

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;


// -------------------- Swap ---------------------------

template <typename T>
void swap(vector<T> & list, int i, int j){

    //Variable temporal
    T aux = list[i];
    list[i] = list[j];
    list[j] = aux;


}


// ------------------ Swap Sort ---------------------

template <typename T>
void swapSort(vector<T> & list, long long & comparaciones, long long & intercambios){

    comparaciones = 0;
    intercambios = 0;

    for(int i = 0; i<list.size()-1; i++){

        for(int j = i + 1; j<list.size(); j++){

            comparaciones++;

            if(list[j] < list[i]){
                swap(list, i, j);
                intercambios++;
            }
        }
    }
}



// ------------------ Bubble Sort -----------------------------

template <typename T>
void bubbleSort(vector<T> & list, long long & comparaciones, long long & intercambios){

    comparaciones = 0;
    intercambios = 0;

    bool change = true;

    for(int i = list.size()-1; i>0 && change; i--){
        change = false;

        for(int j = 0; j<i; j++){
            comparaciones++;

            if(list[j] > list[j+1]){
                swap(list, j, j+1);
                change = true;
                intercambios++;
            }
        }
    }
}


// ------------------ Selection Sort --------------------------

template <typename T>
void selectionSort(vector<T> & numbers, long long & comparaciones, long long & intercambios){

    comparaciones = 0;
    intercambios = 0;

    for(int i = 0; i<numbers.size(); i++){
        int min = i;

        for(int j = i + 1; j<numbers.size(); j++){
            comparaciones++;
            if(numbers[j] < numbers[min]){
                min = j;
            }
        }


        // Intercambio de min por i
        if(i != min){
            T valor = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = valor;

            intercambios++;

        }
    }
}



// --------------- Insertion Sort -----------------------------

template <typename T>
void insertionSort(vector<T> & numbers, long long & comparaciones, long long & intercambios){

    comparaciones = 0;
    intercambios = 0;

    for(int i = 0; i<numbers.size(); i++){
        int j = i;

        while(j > 0){
            comparaciones++;

            if(numbers[j] < numbers[j-1]){
                swap(numbers, j, j-1);
                intercambios++;
                j--;

            } else{
                break;

          
          }
        }
    }
}


// ------------------ Quick Sort -------------------------

template <typename T>
int getPivot(vector<T> & numbers, int left, int right){

    int aux = left - 1;
    int pivot = right;

    for(int i = left; i<pivot; i++){
        if(numbers[pivot] > numbers[i]){
            aux++;
            swap(numbers, aux, i);
        }
    }

    aux++;
    swap(numbers, aux, pivot);

    
    return aux;
}


template <typename T>
void quickSort(vector<T> & numbers, int left, int right){

    if(left < right){
        int pivot = getPivot(numbers, left, right);
        quickSort(numbers, left, pivot - 1);
        quickSort(numbers, pivot + 1, right);

    }
}


// ---------------- Merge Sort -----------------------------

template <typename T>
void merge(vector<T> & numbers, int left, int mid, int right){
    vector<T> leftnumber;

    for(int i = left; i<=mid; i++){
        leftnumber.push_back(numbers[i]);
    }

    vector<T> rightnumber;

    for(int j = mid + 1; j<=right; j++){
        rightnumber.push_back(numbers[j]);
    }


    int index = left;
    int i = 0;
    int j = 0;


    while(i < leftnumber.size() && j < rightnumber.size()){

        if(leftnumber[i] < rightnumber[j]){
            numbers[index] = leftnumber[i];
            i++;

        } else{
            numbers[index] = rightnumber[j];
            j++;
        }

        index++;
    }


    while(i < leftnumber.size()){

        numbers[index] = leftnumber[i];
        i++;
        index++;
    }

    while(j < rightnumber.size()){
        numbers[index] = rightnumber[j];
        j++;
        index++;

    }
}


template <typename T>
void mergeSort(vector<T> & numbers, int left, int right){

    if(left < right){
        int mid = (left + right)/2;

        mergeSort(numbers, left, mid);
        mergeSort(numbers, mid + 1, right);
        merge(numbers, left, mid, right);
        

    }
}



// ------------------ Shell Sort ------------------------------------

template <typename T>
void shellSort(vector<T> & numbers){

    int gap = numbers.size()/2;
    while(gap > 0){

        for(int i = gap; i<numbers.size(); i++){
            int j = i;


            while(j >= gap && numbers[j] < numbers[j-gap]){
                swap(numbers, j, j-gap);
                j = j-gap;
            }
        }

        gap = gap/2;
    }
}


// ------------------ Imprimir ---------------------

template <typename T>
void imprimir(vector<T> & numbers){

    for(int i = 0; i<numbers.size(); i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
}



// ------------------ Crear datos -----------------------------

void crearDatosInt(vector<int> & numbers, int cantDatos){

    numbers.clear();
    for(int i = 0; i<cantDatos; i++){
        numbers.push_back(rand()%1000000 + 1);
    }
}


void crearDatosFloat(vector<float> & numbers, int cantDatos){

    numbers.clear();
    for(int i = 0; i<cantDatos; i++){
        float valor = (rand()%1000000 + 1)/10.0;
        numbers.push_back(valor);
    }
}


void crearDatosDouble(vector<double> & numbers, int cantDatos){

    numbers.clear();
    for(int i = 0; i<cantDatos; i++){
        double valor = (rand()%1000000 + 1)/10.0;
        numbers.push_back(valor);
    }
}


// ----------- Analisis comparativo ---------------------

template <typename T>
void analisisComp(string tipo){
    vector<T> datos1000;
    vector<T> datos10000;
    vector<T> datos100000;

    for(int i = 0; i<1000; i++){
        datos1000.push_back(rand()%1000000 + 1);
    }

    for(int i = 0; i<10000; i++){
        datos10000.push_back(rand()%1000000 + 1);
    }

    for(int i = 0; i<100000; i++){
        datos100000.push_back(rand()%1000000 + 1);
    }


    long long comparaciones;
    long long intercambios;
    long long tiempo1000;
    long long tiempo10000;
    long long tiempo100000;


    // ---------------- Swap Sort ----------------

    vector<T> copia1000 = datos1000;

    auto inicio = chrono::high_resolution_clock::now();
    swapSort(copia1000,  comparaciones,  intercambios);
    auto fin = chrono::high_resolution_clock::now();

    tiempo1000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();



    vector<T> copia10000 = datos10000;
    inicio = chrono::high_resolution_clock::now();
    swapSort(copia10000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();
    tiempo10000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    vector<T> copia100000 = datos100000;
    inicio = chrono::high_resolution_clock::now();
    swapSort(copia100000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();
    tiempo100000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    cout<<endl;
    cout<<"Swap Sort"<<endl;
    cout<<"Tipo de dato: "<<tipo<<endl;
    cout<<"1000 datos: "<<tiempo1000<<" ns"<<endl;
    cout<<"10000 datos: "<<tiempo10000<<" ns"<<endl;
    cout<<"100000 datos: "<<tiempo100000<<" ns"<<endl;

    cout<<"Swap Sort,"<<tipo <<","<<tiempo1000<<","<<tiempo10000<<","<<tiempo100000<<endl;



    // ----------------Bubble Sort ---------------

    copia1000 = datos1000;

    inicio = chrono::high_resolution_clock::now();
    bubbleSort(copia1000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();
    tiempo1000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

    copia10000 = datos10000;

    inicio = chrono::high_resolution_clock::now();
    bubbleSort(copia10000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo10000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia100000 = datos100000;\
    inicio = chrono::high_resolution_clock::now();
    bubbleSort(copia100000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo100000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    cout<<endl;
    cout<<"Bubble Sort "<<endl;
    cout<<"Tipo de dato: "<<tipo<<endl;
    cout<<"1000 datos: "<<tiempo1000<<" ns"<<endl;
    cout<<"10000 datos: "<<tiempo10000<<" ns"<<endl;
    cout<<"100000 datos: "<<tiempo100000<<" ns"<<endl;

    cout<<"Bubble Sort, "<<tipo<<", "<<tiempo1000<<", "<<tiempo10000<<", "<<tiempo100000<<endl;



    // --------------Selection Sort----------------

    copia1000 = datos1000;
    inicio = chrono::high_resolution_clock::now();
    selectionSort(copia1000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo1000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia10000 = datos10000;
    inicio = chrono::high_resolution_clock::now();
    selectionSort(copia10000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo10000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia100000 = datos100000;
    inicio = chrono::high_resolution_clock::now();
    selectionSort(copia100000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo100000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    cout<<endl;
    cout<<"Selection Sort"<<endl;
    cout<<"Tipo de dato: "<<tipo<<endl;
    cout<<"1000 datos: "<<tiempo1000<<" ns"<<endl;
    cout<<"10000 datos: "<<tiempo10000<<" ns"<<endl;
    cout<<"100000 datos: "<<tiempo100000<<" ns"<<endl;


    cout<<"Selection Sort,"<<tipo<<","<<tiempo1000<<","<<tiempo10000<<","<<tiempo100000<<endl;



    // -------------- Insertion Sort -------------

    copia1000 = datos1000;
    inicio = chrono::high_resolution_clock::now();
    insertionSort(copia1000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo1000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia10000 = datos10000;
    inicio = chrono::high_resolution_clock::now();
    insertionSort(copia10000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo10000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

    copia100000 = datos100000;
    inicio = chrono::high_resolution_clock::now();
    insertionSort(copia100000, comparaciones, intercambios);
    fin = chrono::high_resolution_clock::now();

    tiempo100000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    cout<<endl;
    cout<<"Insertion Sort"<<endl;
    cout<<"Tipo de dato: "<<tipo<<endl;
    cout<<"1000 datos: "<<tiempo1000<<" ns"<<endl;
    cout<<"10000 datos: "<<tiempo10000<<" ns"<<endl;
    cout<<"100000 datos: "<<tiempo100000<<" ns"<<endl;

    cout<<"Insertion Sort, "<<tipo<<", "<<tiempo1000<<", "<<tiempo10000<<", "<<tiempo100000<<endl;



    // ---------------- Quick Sort ----------------

    copia1000 = datos1000;
    inicio = chrono::high_resolution_clock::now();
    quickSort(copia1000, 0, copia1000.size()-1);
    fin = chrono::high_resolution_clock::now();

    tiempo1000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia10000 = datos10000;
    inicio = chrono::high_resolution_clock::now();
    quickSort(copia10000, 0, copia10000.size()-1);
    fin = chrono::high_resolution_clock::now();

    tiempo10000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia100000 = datos100000;
    inicio = chrono::high_resolution_clock::now();
    quickSort(copia100000, 0, copia100000.size()-1);
    fin = chrono::high_resolution_clock::now();

    tiempo100000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    cout<<endl;
    cout<<"Quick Sort"<<endl;
    cout<<"Tipo de dato: "<<tipo<<endl;
    cout<<"1000 datos: "<<tiempo1000<<" ns"<<endl;
    cout<<"10000 datos: "<<tiempo10000<<" ns"<<endl;
    cout<<"100000 datos: "<<tiempo100000<<" ns"<<endl;

    cout<<"Quick Sort, "<<tipo<<" , "<<tiempo1000<<" , "<<tiempo10000<<" , "<<tiempo100000<<endl;



    // ---------------Merge Sort ----------------

    copia1000 = datos1000;
    inicio = chrono::high_resolution_clock::now();
    mergeSort(copia1000, 0, copia1000.size()-1);
    fin = chrono::high_resolution_clock::now();

    tiempo1000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia10000 = datos10000;
    inicio = chrono::high_resolution_clock::now();
    mergeSort(copia10000, 0, copia10000.size()-1);
    fin = chrono::high_resolution_clock::now();

    tiempo10000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia100000 = datos100000;
    inicio = chrono::high_resolution_clock::now();
    mergeSort(copia100000, 0, copia100000.size()-1);
    fin = chrono::high_resolution_clock::now();

    tiempo100000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    cout<<endl;
    cout<<"Merge Sort"<<endl;
    cout<<"Tipo de dato: "<<tipo<<endl;
    cout<<"1000 datos: "<<tiempo1000<<" ns"<<endl;
    cout<<"10000 datos: "<<tiempo10000<<" ns"<<endl;
    cout<<"100000 datos: "<<tiempo100000<<" ns"<<endl;

    cout<<"Merge Sort , "<<tipo<<" , "<<tiempo1000<<" , "<<tiempo10000<<" , "<<tiempo100000<<endl;


    // -------------Shell Sort -------------

    copia1000 = datos1000;
    inicio = chrono::high_resolution_clock::now();
    shellSort(copia1000);
    fin = chrono::high_resolution_clock::now();

    tiempo1000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia10000 = datos10000;
    inicio = chrono::high_resolution_clock::now();
    shellSort(copia10000);
    fin = chrono::high_resolution_clock::now();

    tiempo10000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    copia100000 = datos100000;
    inicio = chrono::high_resolution_clock::now();
    shellSort(copia100000);
    fin = chrono::high_resolution_clock::now();
    tiempo100000 = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


    cout<<endl;
    cout<<"Shell Sort"<<endl;
    cout<<"Tipo de dato: "<<tipo<<endl;
    cout<<"1000 datos: "<<tiempo1000<<" ns"<<endl;
    cout<<"10000 datos: "<<tiempo10000<<" ns"<<endl;
    cout<<"100000 datos: "<<tiempo100000<<" ns"<<endl;

    cout<<"Shell Sort, "<<tipo<<" , "<<tiempo1000<<" , "<<tiempo10000<<" , "<<tiempo100000<<endl;
    cout<<endl;
}



// ---------Main---------------------------

int main(){

    srand(time(0));

    vector<int> numbersInt;
    vector<float> numbersFloat;
    vector<double> numbersDouble;

    int tipoActual = 0;
    int opcion = 0;


    while(opcion != 10){
        cout<<endl;
        cout<<"----------Menu----------"<<endl;
        cout<<"1. Crear lista de datos"<<endl;
        cout<<"2. Swap Sort"<<endl;
        cout<<"3. Bubble Sort"<<endl;
        cout<<"4. Selection Sort"<<endl;
        cout<<"5. Insertion Sort"<<endl;
        cout<<"6. Quick Sort"<<endl;
        cout<<"7. Merge Sort"<<endl;
        cout<<"8. Shell Sort"<<endl;
        cout<<"9. Analisis comparativo"<<endl;
        cout<<"10. Salir"<<endl;

        cout<<"Opcion: ";
        cin>>opcion;



        // ----------------Opcion1----------------

        if(opcion == 1){

            int tipo;
            int cantDatos;


            cout<<endl;
            cout<<"Tipo de dato"<<endl;
            cout<<"1. int"<<endl;
            cout<<"2. float"<<endl;
            cout<<"3. double"<<endl;
            cout<<"Opcion: ";
            cin>>tipo;

            cout<<"Cantidad de datos (1000, 10000 o 100000): ";
            cin>>cantDatos;


            if(cantDatos != 1000 && cantDatos != 10000 && cantDatos != 100000){
                cout<<"Cantidad no valida"<<endl;

            } else if(tipo == 1){
                crearDatosInt(numbersInt, cantDatos);
                tipoActual = 1;

                cout<<"Datos int creados"<<endl;

            } else if(tipo == 2){
                crearDatosFloat(numbersFloat, cantDatos);
                tipoActual = 2;

                cout<<"Datos float creados"<<endl;

            } else if(tipo == 3){

                crearDatosDouble(numbersDouble, cantDatos);
                tipoActual = 3;

                cout<<"Datos double creados"<<endl;

            } else{

                cout<<"Tipo de dato no valido"<<endl;
            }
        }



        // ----------------Opcion 2----------------

        else if(opcion == 2){

            long long comparaciones;
            long long intercambios;


            if(tipoActual == 1){

                vector<int> numbersSwap = numbersInt;
                auto inicio = chrono::high_resolution_clock::now();
                swapSort(numbersSwap, comparaciones, intercambios);

                auto fin = chrono::high_resolution_clock::now();
                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();
        

                cout<<endl;
                cout<<"Swap Sort: ";
                imprimir(numbersSwap);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 2){

                vector<float> numbersSwap = numbersFloat;
                auto inicio = chrono::high_resolution_clock::now();
                swapSort(numbersSwap, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();
                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Swap Sort: ";
                imprimir(numbersSwap);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 3){

                vector<double> numbersSwap = numbersDouble;
                auto inicio = chrono::high_resolution_clock::now();
                swapSort(numbersSwap, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Swap Sort: ";
                imprimir(numbersSwap);


                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;

            } else{

                cout<<"Cree los datos primero"<<endl;
            }
        }



        // ----------------Opcion3----------------

        else if(opcion == 3){

            long long comparaciones;
            long long intercambios;


            if(tipoActual == 1){

                vector<int> numbersBubble = numbersInt;
                auto inicio = chrono::high_resolution_clock::now();
                bubbleSort(numbersBubble, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Bubble Sort: ";
                imprimir(numbersBubble);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 2){

                vector<float> numbersBubble = numbersFloat;
                auto inicio = chrono::high_resolution_clock::now();
                bubbleSort(numbersBubble, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Bubble Sort: ";
                imprimir(numbersBubble);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 3){
                vector<double> numbersBubble = numbersDouble;
                auto inicio = chrono::high_resolution_clock::now();
                bubbleSort(numbersBubble, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Bubble Sort: ";
                imprimir(numbersBubble);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;

            } else{
                cout<<"Cree los datos primero"<<endl;
            }
        }



        // ----------------Opcion 4----------------

        else if(opcion == 4){

            long long comparaciones;
            long long intercambios;

            if(tipoActual == 1){

                vector<int> numbersSelection = numbersInt;
                auto inicio = chrono::high_resolution_clock::now();
                selectionSort(numbersSelection, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Selection Sort: ";
                imprimir(numbersSelection);


                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 2){

                vector<float> numbersSelection = numbersFloat;
                auto inicio = chrono::high_resolution_clock::now();
                selectionSort(numbersSelection, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Selection Sort: ";
                imprimir(numbersSelection);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 3){

                vector<double> numbersSelection = numbersDouble;
                auto inicio = chrono::high_resolution_clock::now();
                selectionSort(numbersSelection, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Selection Sort: ";
                imprimir(numbersSelection);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;

            } else{
                cout<<"Cree los datos primero"<<endl;
            }
        }



        // -----------Opcion 5 ----------------

        else if(opcion == 5){

            long long comparaciones;
            long long intercambios;


            if(tipoActual == 1){

                vector<int> numbersInsertion = numbersInt;
                auto inicio = chrono::high_resolution_clock::now();
                insertionSort(numbersInsertion, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


                cout<<endl;
                cout<<"Insertion Sort: ";
                imprimir(numbersInsertion);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 2){

                vector<float> numbersInsertion = numbersFloat;
                auto inicio = chrono::high_resolution_clock::now();
                insertionSort(numbersInsertion, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Insertion Sort: ";
                imprimir(numbersInsertion);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 3){

                vector<double> numbersInsertion = numbersDouble;
                auto inicio = chrono::high_resolution_clock::now();
                insertionSort(numbersInsertion, comparaciones, intercambios);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Insertion Sort: ";
                imprimir(numbersInsertion);

                cout<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Intercambios: "<<intercambios<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else{
                cout<<"Cree los datos primero"<<endl;
            }
        }



        // -------------Opcion6-------------

        else if(opcion == 6){

            if(tipoActual == 1){

                vector<int> numbersQuick = numbersInt;
                auto inicio = chrono::high_resolution_clock::now();
                quickSort(numbersQuick, 0, numbersQuick.size()-1);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Quick Sort: ";
                imprimir(numbersQuick);
                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 2){
                vector<float> numbersQuick = numbersFloat;
                auto inicio = chrono::high_resolution_clock::now();
                quickSort(numbersQuick, 0, numbersQuick.size()-1);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();


                cout<<endl;
                cout<<"Quick Sort: ";
                imprimir(numbersQuick);


                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 3){

                vector<double> numbersQuick = numbersDouble;
                auto inicio = chrono::high_resolution_clock::now();
                quickSort(numbersQuick, 0, numbersQuick.size()-1);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Quick Sort: ";
                imprimir(numbersQuick);

                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;

            } else{
                cout<<"Cree los datos primero"<<endl;
            }
        }



        // --------------Opcion7--------------

        else if(opcion == 7){

            if(tipoActual == 1){
                vector<int> numbersMerge = numbersInt;
                auto inicio = chrono::high_resolution_clock::now();
                mergeSort(numbersMerge, 0, numbersMerge.size()-1);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Merge Sort: ";
                imprimir(numbersMerge);

                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 2){
                vector<float> numbersMerge = numbersFloat;
                auto inicio = chrono::high_resolution_clock::now();
                mergeSort(numbersMerge, 0, numbersMerge.size()-1);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Merge Sort: ";
                imprimir(numbersMerge);

                
                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 3){

                vector<double> numbersMerge = numbersDouble;
                auto inicio = chrono::high_resolution_clock::now();
                mergeSort(numbersMerge, 0, numbersMerge.size()-1);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Merge Sort: ";
                imprimir(numbersMerge);

                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;

            } else{
                cout<<"Cree los datos primero"<<endl;
            }
        }



        // --------------Opcion 8----------------------

        else if(opcion == 8){

            if(tipoActual == 1){
                vector<int> numbersShell = numbersInt;
                auto inicio = chrono::high_resolution_clock::now();
                shellSort(numbersShell);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Shell Sort: ";
                imprimir(numbersShell);
                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 2){

                vector<float> numbersShell = numbersFloat;
                auto inicio = chrono::high_resolution_clock::now();
                shellSort(numbersShell);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Shell Sort: ";
                imprimir(numbersShell);

                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;


            } else if(tipoActual == 3){
                vector<double> numbersShell = numbersDouble;
                auto inicio = chrono::high_resolution_clock::now();
                shellSort(numbersShell);
                auto fin = chrono::high_resolution_clock::now();

                auto tiempo = chrono::duration_cast<chrono::nanoseconds>(fin - inicio).count();

                cout<<endl;
                cout<<"Shell Sort: ";
                imprimir(numbersShell);

                cout<<endl;
                cout<<"Tiempo: "<<tiempo<<" nanosegundos"<<endl;

            } else{
                cout<<"Cree los datos primero"<<endl;
            }
        }



        // -------------Opcion 9 ---------------

        else if(opcion == 9){

            int tipo;
            cout<<endl;
            cout<<"----------Analisis comparativo----------"<<endl;
            cout<<"1. int"<<endl;
            cout<<"2. float"<<endl;
            cout<<"3. double"<<endl;
            cout<<"Tipo de dato: ";
            cin>>tipo;

            cout<<endl;
            cout<<"algoritmo, tipo de dato,tiempo1000, tiempo10000, tiempo100000"<<endl;


            if(tipo == 1){
                analisisComp<int>("int");

            } else if(tipo == 2){
                analisisComp<float>("float");

            } else if(tipo == 3){
                analisisComp<double>("double");

            } else{
                cout<<"Tipo de dato no valido"<<endl;
            }
        }



        // ----------------Opcion 10----------------

        else if(opcion == 10){
            cout<<"Saliendo"<<endl;
        }

        else{
            cout<<"ERROR, intente nuevamente"<<endl;

        }
    }


    return 0;
}