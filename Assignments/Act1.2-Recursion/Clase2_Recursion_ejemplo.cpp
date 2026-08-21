// ================= Clase 2: Recursion =================
// Fucnion que se llama a si misma cambiando el valor de entrada
// Se ocupa un caso base --> a condición que frena las llamadas y devuelve un resultado
// * Mayor consumo de memoria 
// * Codigo mas limpio
// FIFO: First i n First out


#include <iostream>
using namespace std;

int factorial (int n){
    if (n<=1){
        return 1;
    }
    return n * factorial (n-1);
}

int main(){
    cout<< "El factorial de 5 es: "<< factorial(5)<<endl;

    return 0;


}