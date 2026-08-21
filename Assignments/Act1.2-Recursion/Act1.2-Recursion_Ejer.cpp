
// Allison Charlize Arriaza Chachagua 
// A00844457

#include <iostream>
using namespace std;
#include <cmath>

// ================= Suma Iterativa =================
int sumIterative (int n){
    int suma = 0;
    for(int i=1; i<=n; i++ ){
        suma += i;

    }
    return suma;
}

int sumRecursive(int n){
    if (n == 1){
        return 1;
    }
    return n + sumRecursive(n-1);

}

int sumFormula (int n){
    int formula = n * (n+1)/2;

    return formula;
}

int fibonacciIlterative(int n){
    int a = 1; 
    int b = 1;
    int c = 0;

    for (int i = 3; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return c;
    
}

int fibonacciRecursive (int n){
    if (n == 1 || n == 2){
        return 1;
    }
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);

}

int bacteriasIterative(int n){
    double born = 3.78;
    double died = 2.34;
    int sum = 1;

    for (int i = 1; i<=n; i++){
        int bac;
        int bacBorn = sum * born;
        int bacDied = sum * died;
        sum += bacBorn - bacDied;
    }

    return sum;

}

int bacteriasRecursive(int n){
    if(n==0){
        return 1;
    }

    int bacteria = bacteriasRecursive(n-1);
    int born = bacteria * 3.78;
    int died = bacteria * 2.34;

    return bacteria + born - died;

}

double investmentIterative (int n, double cant){
    float intMensual = 0.1875;
    double cantActual = cant; 
    double cantNueva = cant;

    for (int i = 0; i<n; i++){
        cantNueva =  cantActual + (cantActual * intMensual);
        cantNueva = round(cantNueva * 100)/ 100;
        cantActual = cantNueva;       


    }

    return cantNueva;

}

double investmentRecursive(int n, double cant){
    if (n == 0){
        return cant;
    }

    double cActual;
    cActual = cant;
    float interes = 0.1875;
    double cNueva;
    cNueva = cActual + (cActual*interes);
    cNueva = round(cNueva * 100)/ 100;
    cActual = cNueva ;

    return investmentRecursive(n-1, cNueva);



}

int powIterative(int n, int y){
    int base; 
    int potencia;
    base = n;
    potencia = y;
    int numNuevo = 1;

    while (potencia!= 0){
        numNuevo = base * numNuevo;
        potencia --; 

    }

    return numNuevo;



}

int powRecursive(int n, int y){
    if (y ==0){
        return 1;
    }

    return n * powRecursive(n, y-1);

}



int main(){
    cout<< "La suma iteratva de 5 es: "<< sumIterative(5)<<endl;
    cout<< "La suma recursiva de 5 es: "<< sumRecursive(5)<<endl;
    cout<< "La suma de Formula de 5 es: "<< sumFormula(5)<<endl;
    cout<< "La suma de Fibonacci Iterativa de 4 es: "<< fibonacciIlterative(4)<<endl;
    cout<< "La suma de Fibonacci Recursiva de 4 es: "<< fibonacciRecursive(4)<<endl;
    cout<< "La suma de Bacterias Iterativa de 5 es: "<< bacteriasIterative(5)<<endl;
    cout<< "La suma de Bacterias Recursiva de 5 es: "<< bacteriasRecursive(5)<<endl;
    cout<< "La cantidad total de 5 meses y base 100.00 es : "<< investmentIterative(5, 100.00)<<endl;
    cout<< "La cantidad total de 5 meses y base 100.00 (Recursiva) es : "<< investmentRecursive(5, 100.00)<<endl;
    cout<< " 5 elevado a la 8 es: "<< powIterative(5, 8)<<endl;
    cout<< " 5 elevado a la 8 (Recursiva )es: "<< powRecursive(5, 8)<<endl;
}
