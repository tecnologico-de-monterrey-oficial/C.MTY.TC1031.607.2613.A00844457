// Allison Charlize Arriaza Chachagua
//A00844457

#include <iostream>
#include <vector>
using namespace std; 




void imprimir(vector <int> numbers){
    for (int i = 0; i<numbers.size(); i++){
        cout<< numbers[i]<< " ";
    }
    cout<<endl;
}

vector <int> selectionSort(vector <int> numbers){

    for (int i = 0;  i<numbers.size(); i++){
        int min = i;
        for (int j = i + 1; j<numbers.size(); j++){
            if ( numbers[j]< numbers[min]){
                min = j;
            }
        }

        if (i != min){
            int valor = numbers[i];
            numbers[i] = numbers[min];
            numbers[min] = valor;
        }

    }

    return numbers;






}

int insertionSort(vector<int> numbers){
    for (int i = 0; i<numbers.size(); i++){
        int j = i + 1;
        int insertionMin = 0
        while (numbers[j]<numbers[i]){
            


        }

    }


}







int main (){

    vector<int> numbers = {15, 7, 3, 9, 12, 5, 2};

    cout<<"Cadena Original: ";
    imprimir(numbers);
    cout<< "Cadena selection Sort: ";
    imprimir(selectionSort(numbers));
    cout<< "Cadena intersection Sort "<< endl;

    return 0;
}