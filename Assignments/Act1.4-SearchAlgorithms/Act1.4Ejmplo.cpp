

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

// Busqueda Secuencial

template <typename>
int seqSearch (vector <int> & list, int data){
    for (int i =0; i<list.size(); i++){
        if (list[i]== data){
            return i;
        }
    }

    // Excepciones
    throw out_of_range ("No se encontró el valor");
}

// Busqueda Binaria 

template<typename T>
int binarySearch(vector<T> & list, T data){
    int left = 0; 
    int right = list.size() -1;

    // left <= right

    while (left<=right){
        int mid = (left + right)/2;
        if (data == list[mid]){
            return mid;
        } else{
            if (data < list[mid]){
                right = mid -1;
            } else {
                left = mid + 1;
            }
        }
    }
    // No se encuentra
    throw out_of_range ("NO se encoentró el valor");

}



int main() {

    vector<int> list = {3, 5, 6, 8, 11, 12, 13, 16, 27, 35};
    try {
        int index = binarySearch(list, 16);
        cout << "El valor se encuentra en: " << index << endl;
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
    return 0;
}


// class ListaNumeros{
//     private: 

//     public:
//     list<int> NumList = {3, 5, 6, 8, 11, 12, 13, 16, 27, 35};

//     int secBinary (int n){
//         int left = 0;
//         int right = 0;
//         int mid = trunc((right + left)/2);

//         while ()

        
    
    
//     }





// // }

