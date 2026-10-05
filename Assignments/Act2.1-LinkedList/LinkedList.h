#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // operaciones
    void push_front(T data);
    void push_back(T data);
    void print();
    void insert(int index, T data);
    void deleteData(T data);
    void deleteAt(int index);
    T getData(int index);
    void updateData(T oldData, T newData);
    void updateAt(int index, T data);
    int finData(T data);

    T& operator [](int index);
    LinkedList<T>& operator=(const LinkedList<T>& lista);
    
};

template <typename T>
void LinkedList<T>::push_front(T data) {
    // Creamos el nuevo nodo y lo colocamos al inicio
    Node<T>* node = new Node<T>(data);
    node->next = head;
    head = node;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
    // Si la lista tiene elementos, recorremos hasta el final
    if (head != nullptr) {
        Node<T>* aux = head;

        while (aux->next != nullptr) {
            aux = aux->next;
        }

        aux->next = new Node<T>(data);

    } else {
        // Si está vacía, el nuevo nodo se convierte en head
        head = new Node<T>(data);
    }

    size++;
}

template <typename T>
void LinkedList<T>::insert(int index, T data) {
    // Validamos que la posición sea válida
    if (index >= 0 && index < size) {
        int auxIndex = 0;
        Node<T>* aux = head;

        // Recorremos hasta llegar al índice indicado
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }

        // Insertamos el nodo después de la posición encontrada
        aux->next = new Node<T>(data, aux->next);
        size++;

    } else {
        throw out_of_range("la posición no existe en la lista");
    }
}

template <typename T>
void LinkedList<T>::deleteData(T data) {
    // Primero verificamos que la lista no esté vacía
    if (head != nullptr) {

        // Caso en el que el dato está al inicio
        if (head->data == data) {
            Node<T>* aux = head;
            head = head->next;

            delete aux;
            size--;

        } else {
            Node<T>* auxPrev = head;
            Node<T>* aux = head->next;

            // Buscamos el dato en el resto de la lista
            while (aux != nullptr) {

                if (aux->data == data) {
                    auxPrev->next = aux->next;

                    delete aux;
                    size--;
                    return;
                }

                auxPrev = aux;
                aux = aux->next;
            }

            throw out_of_range("no se encontró el dato a borrar");
        }

    } else {
        throw out_of_range("La lista esta vacía");
    }
}

template <typename T>
void LinkedList<T>::print() {
    Node<T>* aux = head;

    // Recorremos la lista e imprimimos cada dato
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;

        if (aux != nullptr) {
            cout << "-";
        }
    }

    cout << endl;
}

template <typename T>
void LinkedList<T>:: deleteAt(int index){
    if (index < 0 || index>= size){
        throw out_of_range(" La posición no existe en la lista")
    }


    if(index ==0){
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
        return;
    }

    
    Node<T>* auxPrev = head;
    Node<T>* aux = head->next;
    int auxIndex = 1;

    while (auxIndex < index) {
        auxPrev = aux;
        aux = aux->next;
        auxIndex++;
    }

    auxPrev->next = aux->next;
    delete aux;
    size--;

}

template <typename T>
void LinkedList<T>:: getData(int index){
    // validar  que la posicion exista
    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }


    Node<T>* aux = head;
    int auxIndex = 0;
    while (auxIndex < index) {
        aux = aux->next;
        auxIndex++;
    }

    return aux->data;
}

template<typename T>
void LinkedList<T>:: updateData(T oldData, T newData){
    Node<T>* aux = head;
    while (aux != nullptr) {
        if (aux->data == oldData) {
            aux->data = newData;
            return;
        }

        aux = aux->next;
    }

    throw out_of_range("No se encontro el dato");
}


template <typename T>
void LinkedList<T>:: updateAt(int index, T data){
    if (index < 0 || index >= size) {
        throw out_of_range("La posicion no existe en la lista");
    }

    Node<T>* aux = head;
    int auxIndex = 0;
    while (auxIndex < index) {
        aux = aux->next;
        auxIndex++;
    }


    aux->data = data;
}

template <typename T>
void LinkedList<T>::finData(T data){
    Node<T>* aux = head;
    int index = 0;

    while (aux != nullptr) {
        if (aux->data == data) {
            return index;
        }

        aux = aux->next;
        index++;
    }

    
    return -1;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {

    if (index >= 0 && index < size) {
        Node<T>* aux = head;
        int auxIndex = 0;

        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }

        return aux->data;
    } else {
        throw out_of_range("La posicion no existe en la lista");
    }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& lista) {
    while (head != nullptr) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }

    size = 0;

    Node<T>* aux = lista.head;

    while (aux != nullptr) {
        push_back(aux->data);
        aux = aux->next;
    }

    return *this;
}







#endif /* LinkedList_h */