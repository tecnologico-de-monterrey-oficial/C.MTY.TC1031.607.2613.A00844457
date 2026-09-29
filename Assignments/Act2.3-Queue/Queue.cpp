//Allison Charlize Arriaza Chachagua
//A00844457

#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

template<typename T>
class Queue{
    private:
    int head;
    int tail;


    public:
    Queue();
    void pop();
    void push();
    int front();
    void print();

};

template <typename T>
void Queue<T>::pop(){
    

    
}

template <typename T>
void Queue<T>::push(T data){

}

template <typename T>
int Queue<T>::front(T data){


}

template <typename T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;
        if (aux != nullptr) {
            cout << "-";
        }
    }
    cout << endl;
}



int main {
    queue.pop



    return 0;
}
