// Allison Charlize Arriaza Chachagua
// A00844457

#include <iostream>
#include <vector>
using namespace std;



template <typename T>
void swap(vector<T> & list, int i, int j){
    //Variable temporal
    T aux = list[i];
    list [i] = list [j];
    list[j] = aux;
}


// ------------------ Swap Sort -----------------------------

template <typename T>
void swapSort(vector<T> & list, long long & comparaciones, long long & intercambios){

    comparaciones = 0;
    intercambios = 0;

    // menor
    // intercambiar valores
    for (int i = 0; i<list.size()-1; i++){

        for (int j = i +1; j<list.size(); j++){

            comparaciones++;

            if(list[j]< list[i]){

                // Si es menor, cambiar los valores
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

    // Definir boolean
    bool change = true;

    //Iterar de n hasta 1
    for (int i=list.size() -1; i>0 && change; i --){

        // cambia change a False
        change = false;

        // Iterar hasta que 0 sea i
        for (int j = 0; j<i; j++){

            comparaciones++;

            // si es mayor cambia a verdadero
            if (list[j] > list[j+1]){

               swap(list, j, j+1);
               change = true;
               intercambios++;

            }
        }
    }

}



// ------------------ Selection Sort -----------------------------

template <typename T>
void selectionSort(vector<T> & numbers, long long & comparaciones, long long & intercambios){

    comparaciones = 0;
    intercambios = 0;

    for (int i = 0;  i<numbers.size(); i++){
        int min = i;

        for (int j = i + 1; j<numbers.size(); j++){
            comparaciones++;

            if (numbers[j] < numbers[min]){
                min = j;
            }

        }


        // Intercambio de min por i
        if (i != min){
            T valor = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = valor;

            intercambios++;
        }
    }

}



// ------------------ Insertion Sort -----------------------------

template <typename T>
void insertionSort(vector<T> & numbers, long long & comparaciones, long long & intercambios){

    comparaciones = 0;
    intercambios = 0;

    for (int i = 0; i<numbers.size(); i++){
        int j = i;

        while (j > 0){
            comparaciones++;

            if (numbers[j] < numbers[j-1]){
                //Intercambiar j con j-1
                swap(numbers, j, j-1);
                intercambios++;
                j--;

            } else{
                break;

            }
        }
    }
}

// ------------------ Quick Sort -----------------------------

template <typename T>
int getPivot(vector<T> & numbers, int left, int right){

    int aux = left - 1;
    int pivot = right;

    for (int i = left; i < pivot; i++){

        if (numbers[pivot] > numbers[i]){
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

    if (left < right){

        int pivot = getPivot(numbers, left, right);
        quickSort(numbers, left, pivot - 1);
        quickSort(numbers, pivot + 1, right);
    }
}

// ------------------ Merge Sort -----------------------------

template <typename T>
void merge(vector<T> & numbers, int left, int mid, int right){
    
    vector<T> leftnumber;
    for (int i = left; i <= mid; i++){
        leftnumber.push_back(numbers[i]);
    }

    vector<T> rightnumber;
    for (int j = mid + 1; j <= right; j++){
        rightnumber.push_back(numbers[j]);
    }

    int index = left;
    int i = 0;
    int j = 0;



    while (i < leftnumber.size() && j < rightnumber.size()){

        if(leftnumber[i] < rightnumber[j]){

            numbers[index] = leftnumber[i];
            i++;
        } else{
            numbers[index] = rightnumber[j];
            j++;
        }

        index++;

    }


    while (i < leftnumber.size()){
        numbers[index] = leftnumber[i];
        i++;
        index++;

    }


    while (j < rightnumber.size()){
        numbers[index] = rightnumber[j];
        j++;
        index++;

    }

}


template <typename T>
void mergeSort(vector<T> & numbers, int left, int right){

    if (left < right){
        int mid = (left + right)/2;
        mergeSort(numbers, left, mid);
        mergeSort(numbers, mid + 1, right);
        merge(numbers, left, mid, right);

    }

}


// ------------------ Imprimir -----------------------------

template <typename T>
void imprimir(vector<T> & numbers){

    for (int i = 0; i<numbers.size(); i++){
        cout<< numbers[i]<< " ";

    }

    cout<<endl;

}



int main (){

    vector<int> numbers = {15, 7, 3, 9, 12, 5, 2};

    long long comparaciones;
    long long intercambios;

    cout<<"Cadena Original: ";
    imprimir(numbers);


    // Swap Sort
    vector<int> numbersSwap = numbers;

    swapSort(numbersSwap, comparaciones, intercambios);
    cout<<endl;
    cout<< "Cadena Swap Sort: ";
    imprimir(numbersSwap);
    cout<< "Comparaciones: "<<comparaciones<<endl;
    cout<< "Intercambios: "<<intercambios<<endl;

    

    // Bubble Sort
    vector<int> numbersBubble = numbers;
    bubbleSort(numbersBubble, comparaciones, intercambios);
    cout<<endl;
    cout<< "Cadena Bubble Sort: ";
    imprimir(numbersBubble);
    cout<< "Comparaciones: "<<comparaciones<<endl;
    cout<< "Intercambios: "<<intercambios<<endl;


    // Selection Sort
    vector<int> numbersSelection = numbers;
    selectionSort(numbersSelection, comparaciones, intercambios);
    cout<<endl;
    cout<< "Cadena Selection Sort: ";
    imprimir(numbersSelection);
    cout<< "Comparaciones: "<<comparaciones<<endl;
    cout<< "Intercambios: "<<intercambios<<endl;



    // Insertion Sort
    vector<int> numbersInsertion = numbers;
    insertionSort(numbersInsertion, comparaciones, intercambios);
    cout<<endl;
    cout<< "Cadena Insertion Sort: ";
    imprimir(numbersInsertion);
    cout<< "Comparaciones: "<<comparaciones<<endl;
    cout<< "Intercambios: "<<intercambios<<endl;



    // Quick Sort
    vector<int> numbersQuick = numbers;

    quickSort(numbersQuick, 0, numbersQuick.size() - 1);
    cout<<endl;
    cout<< "Cadena Quick Sort: ";
    imprimir(numbersQuick);

    // Merge Sort
    vector<int> numbersMerge = numbers;
    mergeSort(numbersMerge, 0, numbersMerge.size() - 1);
    cout<<endl;
    cout<< "Cadena Merge Sort: ";
    imprimir(numbersMerge);


    return 0;
}