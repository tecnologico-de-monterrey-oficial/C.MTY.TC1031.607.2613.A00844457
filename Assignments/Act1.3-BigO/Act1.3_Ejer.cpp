// Allison Charlize Arriaza Chachagua 
// A00844457

#include <iostream>
#include <vector>
using namespace std; 

// O(n): recorre todos los elementos del vector

int funInteractive (vector <int> numeros){
    int sum = 0;


    for (int i = 0; i<numeros.size(); i++){
        if (numeros[i]%2 != 0){

            sum =  sum + numeros [i]; 


        }

    }

    return sum;

}

// O(n): Reccorre el vector mediante la recusividad avanzando de posicion hasta llegar al caso base

int funRecursive(vector<int> numeros, int i){

    if (i == numeros.size()){
        return 0;
    }

    if (numeros[i]%2 != 0){
        return numeros[i] + funRecursive(numeros, i+1);



    } else{
        return funRecursive(numeros, i+1);
    }

        

}
    
    


int main (){

    vector <int> numeros = {11, 12, 2, 3, 50, 45, 33, 34, 1, 8};
    cout<< " Suma de enteros impares Iterativos: "<<funInteractive(numeros)<<endl;
    cout<< " Suma de enteros impares Recursiva: "<<funRecursive(numeros, 0)<<endl;


    return 0;

}
