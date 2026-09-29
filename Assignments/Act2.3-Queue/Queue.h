#ifndef Queue_h
#define Queue_h

#include "Node.h"

class Queue{
    private:
    Node<T>* head;
    Node<T>*tail;

    public:
    Queue: head(nullptr), tail(nullptr){}
    void pop();
    void push();
    int front();
    void print();
}

template <typename T>
void Queue<T>::pop(){

    if(head != nullptr){
        if (head == tail){
            Node<T>* aux = head;
            delete aux;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node<T>* aux = head;
            head = head -> next;
            delete aux; 
        }
    }
    
 
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

}

template <typename T>
void Queue<T>::front(){
    if ()
}


#endif /* Queue_h */