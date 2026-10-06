#ifndef Queue_h
#define Queue_h
#include <stdexcept>
#include <iostream>
using namespace std;
#include "Node.h"

template <typename T>
class Queue{
    private:
    Node<T>* head;
    Node<T>*tail;
    int size;

    public:
    Queue() : head(nullptr), tail(nullptr), size(0){}
    T pop();
    void push(T data);
    T front();
    int getsize();
};

template <typename T>
T Queue<T>::pop(){

    if (head == nullptr){
        throw out_of_range ("Lista vacia");
    }

    T data = head->data;
    if (head == tail){
        Node<T>* aux = head;
        delete aux;
        head = nullptr;
        tail = nullptr;
    }else {
        Node<T>* aux = head;
        head = head -> next;
        delete aux; 
    
    }
    size --;
    return data;
    
 
}

template <typename T>
void Queue<T>::push( T data){
    if(head != nullptr){
        tail -> next = new Node<T>(data);
        tail = tail->next;

    } else { 
        head = new Node<T>(data);
        tail = head;
    }
    size ++;

}

template <typename T>
T Queue<T>:: front(){
    if (head==nullptr ){
        throw out_of_range ("Lista vacía");
    }
    return head-> data;

}

template <typename T>
int Queue<T>::getsize(){
    return size;
}


#endif /* Queue_h */