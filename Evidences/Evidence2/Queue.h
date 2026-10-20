#ifndef Queue_h
#define Queue_h
#include <stdexcept>
#include <iostream>
using namespace std;
#include "LinkedList.h"

template <typename T>
class Queue{
    private:
    LinkedList<T> lista;

    public:
    Queue(){}
    T pop();
    void push(T data);
    T front();

    void enqueue(T data){
        push(data);
    }

    T dequeue(){
        return pop();
    }

    bool isEmpty(){
        return lista.getSize() ==0;
    }

    //Deje ambos metodos para evitar problemas con el codigo anterior, ya que antes usaba getsize().
    int getSize(){
        return lista.getSize();
    }

    int getsize(){
        return getSize();
    }
    

};

template <typename T>
T Queue<T>::pop(){

    if (isEmpty() == true){
        throw out_of_range ("Lista vacia");
    }

    T data = lista.getData(0);
    lista.deleteAt(0);
    return data;
    
 
}

template <typename T>
void Queue<T>::push( T data){
    lista.push_back(data);

}

template <typename T>
T Queue<T>:: front(){
    if (isEmpty() == true ){
        throw out_of_range ("Lista vacía");
    }
    return lista.getData(0);

}


#endif /* Queue_h */