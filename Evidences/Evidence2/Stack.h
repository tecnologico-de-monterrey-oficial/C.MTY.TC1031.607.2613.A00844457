//Allison Charlize Arriaza Chachagua 
//A00844457

#ifndef Stack_h
#define Stack_h 
#include <iostream>
using namespace std;

#include "LinkedList.h"

template <typename T>
class Stack{
    private: 
    LinkedList<T> lista;


    public: 
    Stack(){}
    T pop();
    void push(T data);
    T top();

    T peek(){
        return top();
    }
    bool isEmpty(){
        return lista.getSize() == 0;
    }
    int getSize(){
        return lista.getSize();
    }

};

template <typename T>
T Stack<T>::pop(){
    if(isEmpty()== true){
        throw out_of_range("La lista está vacía ");

    }

    T data = lista.getData(0);
    lista.deleteAt(0);
    return data;

}

template <typename T>
void Stack<T>::push( T data){
    lista.push_front(data);

}

template <typename T>
T Stack<T>::top(){
    if (isEmpty() == true){
        throw out_of_range("Lista vacia");
    }

    return lista.getData(0);

}





#endif