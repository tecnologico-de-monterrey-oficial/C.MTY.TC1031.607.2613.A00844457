#include <iostream>
using namespace std;
#include "List.h"

// ================= Clase 1: Templates =================
// int sum(int a, int b){
//     return a + b;
// }

// double sum(double a, double b){

//     return a + b;
// }

// float sum(float a, float b){

//     return a + b;
// }


// string sum(string a, string b){

//     return a + b;
// }



// template <typename T> // Puede correr cualquier tipo de dato.
// T sum(T a, T b){
//     return a + b;
// }


//int main() {

    // string  a = "5.5555" ;
    // string b = "10.66666";
    // cout << "Sum of " << a << " and " << b << " = " << sum(a, b)<<endl;

//     return 0;
// }

// =========================== Act 1.1 ============================

int main() {
    cout << "============ Int  List==========="<<endl;
    List <int> list;  // Manda a llamar el constructor
        cout << "----Lista"<<endl;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.print();
    cout<<"----"<<endl;
    cout<<"Tamaño: "<<list.getSize()<<endl;
    cout<<"Dato en posicion 1: "<<list.getData(1)<<endl;
    cout<<"Max: "<<list.getMax()<<endl;
    cout<<"----"<<endl;

    cout<<"Insertar 11 en la posicion 0 "<<endl;
    list.insertAt(0, 11);
    list.print();

    cout<<"----"<<endl;

    cout << "Dato eliminado: ";
    list.removeAt(1);
    cout << "Lista despues de eliminar:" << endl;
    list.print();

    cout<<"----"<<endl;

    cout<<"Quitar último dato: ";
    list.removeLast();
    cout << "Lista despues de eliminar:" << endl;
    list.print();
    cout<<"----"<<endl;

    cout<< "-----Errores-----"<< endl;

    cout<<" -insertar en la posicion 5 el dato 100 -"<<endl;
    list.insertAt(5, 100);

    cout<<" - eliminar la posicion 20 -"<<endl;
    list.removeAt(20);

    cout<<" - Lista vacía -"<<endl;
    List<int> emptyList;
    emptyList.removeLast();




    cout << "==============String List=============="<<endl;
    cout << "----Lista"<<endl;
    List<string> things;
    things.insert("Laptop");
    things.insert("Bottle");
    things.insert("proyector");

    things.print();
    cout<<"----"<<endl;
    cout << "Tamaño de lista: " << things.getSize() << endl;
    cout << "Dato en posicion 1: " << things.getData(1) << endl;
    cout << "Max string: " << things.getMax() << endl;


    return 0;
}