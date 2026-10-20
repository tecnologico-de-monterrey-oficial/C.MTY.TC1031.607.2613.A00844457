//Allison Charlize Arriaza Chachagua
//A00844457

#include <iostream>
#include <stdexcept>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "DoublyLinkedList.h"
using namespace std;

int main(){
    LinkedList<int> lista;
    cout<<"========== Linked list =========="<<endl;
    cout<<"Lista vacia: ";
    lista.print();
    cout<<"Tamaño: "<<lista.getSize()<<endl;
    lista.push_front(10);
    lista.push_back(20);
    lista.push_back(30);

    cout<<"Lista con datos: ";
    lista.print();

    lista.deleteAt(0);
    cout<<"Despues de borrar el primero: ";
    lista.print();

    lista.deleteAt(1);
    cout<<"Despues de borrar el ultimo: ";
    lista.print();

    lista.deleteAt(0);
    cout<<"Tamaño despues de vaciar la lista: "<<lista.getSize()<<endl;
    lista.push_back(50);
    cout<<"Nuevo dato: ";
    lista.print();

    Queue<int> cola;
    cout<<endl<<"======== Queue ==========="<<endl;
    cout<<"Vacia: "<<cola.isEmpty()<<endl;
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);

    cout<<"Tamaño: "<<cola.getSize()<<endl;
    cout<<"Primero: "<<cola.front()<<endl;
    cout<<"Dato: "<<cola.dequeue()<<endl;
    cout<<"Dato: "<<cola.dequeue()<<endl;
    cout<<"Dato: "<<cola.dequeue()<<endl;
    cout<<"Tamaño final: "<<cola.getSize()<<endl;

    cola.enqueue(40);
    cout<<"Nuevo primer dato: "<<cola.front()<<endl;

    Stack<int> pila;

    cout<<endl<<"========== Stack ==========="<<endl;
    cout<<"Vacia: "<<pila.isEmpty()<<endl;
    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout<<"Tamaño: "<<pila.getSize()<<endl;
    cout<<"Arriba: "<<pila.peek()<<endl;
    cout<<"Dato: "<<pila.pop()<<endl;
    cout<<"Dato: "<<pila.pop()<<endl;
    cout<<"Dato: "<<pila.pop()<<endl;
    cout<<"Tamaño final: "<<pila.getSize()<<endl;

    pila.push(40);
    cout<<"Nuevo Dato: "<<pila.top()<<endl;

    DoublyLinkedList<int> doble;

    cout<<endl<<"===== Doubly Linked List ====="<<endl;
    cout<<"Tamaño inicial: "<<doble.getSize()<<endl;
    doble.addFirst(10);
    doble.addLast(20);
    doble.addLast(30);

    cout<<"Imprimir Adelante: ";
    doble.imprimirAdelante();
    cout<<"Imprimir Atras: ";
    doble.imprimirAtras();

    doble.insert(1,25);
    cout<<"Lista despues de insertar: ";
    doble.imprimirAdelante();

    doble.deleteAt(0);
    cout<<"Lista despues de borrar el primero: ";
    doble.imprimirAdelante();

    doble.deleteAt(doble.getSize()-1);
    cout<<"Lista despues de borrar el ultimo: ";
    doble.imprimirAdelante();

    doble.deleteAt(0);
    doble.deleteAt(0);

    cout<<"Tamaño al vaciar lista: "<<doble.getSize()<<endl;

    doble.addLast(50);
    cout<<"Nuevo dato: ";
    doble.imprimirAdelante();

    cout<<endl<<"======= Pruebas vacias ========="<<endl;

    Stack<int> pilaVacia;
    Queue<int> colaVacia;

    if(pilaVacia.isEmpty() == true){
        cout<<"La pila esta vacia"<<endl;
    }else{
        pilaVacia.pop();
    }

    if(colaVacia.isEmpty() == true){
        cout<<"La cola esta vacia"<<endl;
    }else{
        colaVacia.dequeue();
    }

    cout<<"Fin de las pruebas"<<endl;
    return 0;
}