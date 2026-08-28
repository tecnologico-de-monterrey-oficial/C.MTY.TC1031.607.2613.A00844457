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


template <typename T>
void swapSort(vector<T> & list){
    // menor 
    // intercambiar valorrs
    for (int i = 0; i<list.size()-1; i++){
        for (int j = i +1; j<list.size(); j++){

            if(list[j]< list[i]){
                // Si es menor, cambiar los valores
                swap(list, i, j);
            
            }

        }
    }


}

template <typename T>
void BubbleSort(vector<T> & list){
    // DEfinir boolean
    bool change = true;
    //Iterar de n hasta 1
    for ( int i=list.size() -1; i>0 && change; i --){
        // cambia change a False
        change = false;
        // Iterar hasta que 0 sea i
        for (int j = 0; j<i; j++){
            // si es mayor vcambia a verdadero
            if (list[j] > list[j+1]){
               swap(list, j, j+1);
               change = true;

            }

        }

    } 
}





template <typename T>
void print(vector<T> & list){
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;
}



int main(){
    vector<int> list = {15, 7, 3, 9, 12, 5, 2};
    vector<int> listO = list;

    cout << "Lista Original: " << endl;
    print(list);

    swapSort(list);

    cout << "Swap sort: " << endl;
    print(list);
    
    BubbleSort(listO);

    cout << "Bubble sort: " << endl;
    print(listO);



    return 0;
}