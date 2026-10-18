//Allison Charlize Arriaza Chachagua 
//A00844457

#ifndef Stack_h
#define Stack_h 
#include <iostream>
using namespace std;

#include "NodeD.h"

template <typename T>
class Stack{
    private: 
    NodeD<T>* head;
    int size;

    public: 
    Stack(): head(nullptr), size(0){}
    T pop();
    void push(T data);
    T top();
    int getSize();
};

template <typename T>
T Stack<T>::pop(){
        if (head == nullptr){
        throw out_of_range ("Lista vacia");
    }

    NodeD<T>* aux = head;
    T data = head->data;
    head = head-> next;

    delete aux;
    size--;
    return data;

}

template <typename T>
void Stack<T>::push( T data){
    NodeD<T>* nuevo = new NodeD<T>(data);
    nuevo-> next = head;
    head = nuevo;

    size++;

}

template <typename T>
T Stack<T>::top(){
    if (head == nullptr){
        throw out_of_range("Lista vacia");
    }

    return head->data;

}

template <typename T>
int Stack<T>::getSize(){
    return size;
}





#endif