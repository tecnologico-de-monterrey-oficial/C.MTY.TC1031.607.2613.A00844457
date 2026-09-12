//Alliosn Charlize Arriaza Chachagua 
//A00844457

#include <iostream>
using namespace std; 

int main (){
    int x = 42; 
    int* p = &x;

    cout << x<<endl; 
    cout<< &x<<endl; //& indica donde esta almacenada x
    cout<< p << endl; 
    cout << *p<<endl;  // p guarda la dirección

    cout << "valores de q"<< endl;
    int* q = new int(5); // apuntador que define un espacio de memoria 
    cout << q << endl;
    cout<< *q <<endl;

    delete q; // elima el dato del espacio de memoria
    cout << q<<endl; 
    cout << *q << endl;

    Fraction* f = new Fraction(2,3);
    f -> print();  // -> acceder al metodo
    cout<< f<< endl;
    delete f;
     f= nullopt;

     auto g = std ::make_unique<Fraction> (3, 4);  // make_unique realiza el delete
      g -> print
      cout<< g-> detDenominador()<<"/"<<g-> getNumerator()<<end;

    return 0;
}

