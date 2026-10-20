//Allison Charlize Arriaza Chachagua
//A00844457
#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include<fstream>
#include <string>
#include "NodeD.h"
#include <stdexcept>

using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size = 0;

    int comparaciones =0;
    int profundidadMax = 0;

    NodeD<T>* mitad(NodeD<T>* inicio);
    NodeD<T>* merge(NodeD<T>* left, NodeD<T>* right);
    NodeD<T>* mergeSort(NodeD<T>* inicio, int profundidad);



public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    int getSize(){
        return size;

    }

    int getComparaciones(){
        return comparaciones;
    }

    int getProfundidadMaxima(){
        return profundidadMax;
    }

    
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    bool deleteAt(int index);
    int findData(T data);
    bool deleteData(T data);
    T getData(int index);
    void updateData(T data, T newData);
    void updateAt(int index, T data);
    void clear();
    void sort();
    void duplicate();
    void removeDuplicates();
    void ordenarLogs();
    void generarArchivo(string archivoOutput);
    bool verificarOrdenArchivo();
    void imprimirAdelante();
    void imprimirAtras();

    T& operator[](int index);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& lista);

};

template <typename T>
void DoublyLinkedList<T>::addFirst(T data) {
    // validarsi la lista está vacía
    if (head == nullptr) {
        // si está vacía la lista
        // apunto head a un nuevo nodo con data
        head = new NodeD<T>(data);
        tail = head;
        size++;
    } else {
        // la lista no está vacía
        NodeD<T>* aux = new NodeD<T>(data);
        // apuntamos el next de aux a head
        aux->next = head;
        head->prev = aux;
        head = aux;
        size++;
    }
}


template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
    // validamos si la lista está vacía
    if (head == nullptr) {
        head = new NodeD<T>(data);
        tail = head;
        size++;
    } else {
        // la lista no está vacía
        NodeD<T>* aux = new NodeD<T>(data);
        aux->prev = tail;
        tail->next = aux;
        tail = aux;
        size++;

    }


}

template <typename T>
void DoublyLinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index <= size-1) {
        if (index != size-1) {
            // el index es desde 0 hasta el penúltimo (en medio)
            // creamos un indice auxiliar igual a 0
            int auxIndex = 0;
            NodeD<T>* aux = head;
            while (auxIndex < index) {
                aux = aux->next;
                auxIndex++;
            }


            NodeD<T>* auxNew = new NodeD<T>(data);
            auxNew->prev = aux;
            auxNew->next = aux->next;
            aux->next->prev = auxNew;
            aux->next = auxNew;
            size++;

        } else {
            // el index es igual a size -1
            NodeD<T>* aux = new NodeD<T>(data);
            aux->prev = tail;
            tail->next = aux;
            tail = aux;
            size++;
        }
     
        
    } else {
        throw out_of_range("Índice inválido");
 
 
    }
}


template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index){
    if (index >= 0 && index<size){
         // solo existe un elemento
        if (head-> next == nullptr){
            // nodo auxiliar para no perder el elemento
            NodeD<T>* aux = head;
            head= nullptr;
            tail = nullptr;
            delete aux;

            size--;
            return true;

        } else {
            if(index==0){
                NodeD<T>* aux = head;
                head = head->next;
                head->prev = nullptr;

                delete aux;
                size --;
                return true;

            } else{
                if(index == size -1){
                    //borrar el ultimo elemento
                    NodeD<T>* aux = tail;
                    tail = tail->prev;
                    tail->next = nullptr;

                    delete aux;
                    size --;
                    return true;

                } else{
                    //borrar elemento de posicion de el medio
                    if(index <= (size -1)/2 ){

                        int auxIndex = 1;
                        NodeD<T>* aux = head-> next;
                        while(auxIndex<index){
                            aux = aux->next;
                            auxIndex ++;

                        }
                        // ya se llego al nodo deseado
                        // NodeD
                        aux->prev->next = aux-> next;
                        aux->next->prev = aux->prev;

                        delete aux;
                        size --;
                        return true;

                    } else{
                        int auxIndex = size -2;
                        NodeD<T>* aux = tail-> prev;
                        while(index<auxIndex){
                            aux = aux->prev;
                            auxIndex --;

                        }

                        // ya se llego al nodo deseado
                        // NodeD
                        aux->prev->next = aux-> next;
                        aux->next->prev = aux->prev;

                        delete aux;
                        size--;
                        return true;


                    }

                }

            }
        }

    } else {

        return false;
    }
}

template <typename T>
int DoublyLinkedList<T>::findData(T data){
    int auxIndex =0;

    NodeD<T>* aux = head;
    while(auxIndex<size){
        if(aux->data == data){
            return auxIndex;
        }

        auxIndex++;
        aux = aux->next;
    }
    return -1;


}

template <typename T>
bool DoublyLinkedList<T>:: deleteData(T data){
    // find data
    int auxIndex =0;

    NodeD<T>* aux = head;
    while(auxIndex<size){
        if(aux->data == data){
            //Encontrado! se borra
            //---------------------
            // un solo elemento
            if (head == tail){
                head= nullptr;
                tail = nullptr;
                delete aux;

                size--;
                return true;

            } else {
                // borrar head
                if (aux == head){ // data = head;
                    head = head->next;
                    head->prev = nullptr;


                    delete aux;
                    size --;
                    return true;


                } else {
                    if (aux == tail){

                        tail = tail->prev;
                        tail->next = nullptr;

                        delete aux;
                        size --;
                        return true;

                    } else {
                        aux->prev->next = aux-> next;
                        aux->next->prev = aux->prev;

                        delete aux;
                        size --;
                        return true;


                        
                    }

                }
         
         
            }

        }
        auxIndex++;
        aux = aux->next;
    }
    return false;
}

template <typename T>
T DoublyLinkedList<T>::getData(int index){
    if(index>=0 && index < size){
        // desde head
        NodeD<T>* aux = head;
        int auxIndex = 0;

        if (index <= (size - 1)/2){
            aux = head;
            auxIndex = 0;

            while (auxIndex<index){
                aux = aux-> next;
                auxIndex ++;

            }


        } else {
            aux = tail;
            auxIndex = size -1;

            while (auxIndex>index){
                aux = aux-> prev;
                auxIndex --;
            }

        }
        return aux -> data;

        

    } else {
        throw out_of_range("Indice invalido");
    }

}

template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T data){
    if(index >= 0 && index < size){
        
        NodeD<T>* aux;
        int auxIndex;

        if(index <= (size - 1)/2){
            aux = head;
            auxIndex = 0;
            while(auxIndex < index){
                aux = aux->next;
                auxIndex++;
            }


        } else {
            aux = tail;
            auxIndex = size - 1;

            while(auxIndex > index){
                aux = aux->prev;
                auxIndex--;
            }
        }

        aux->data = data;


    } else {
        throw out_of_range("Índice inválido");
 
    }
}

template <typename T>
void DoublyLinkedList<T>::updateData (T data, T newData){
    int auxIndex = 0;
    NodeD<T>* aux = head;

    while(auxIndex < size){
        if(aux->data == data){
            aux->data = newData;
            return;
            
        }

        auxIndex++;
        aux = aux->next;

    }
    throw out_of_range("Dato no encontrado");
}

template <typename T>
void DoublyLinkedList<T>::clear(){
    NodeD<T>* aux = head;

    while(aux != nullptr){

        head = head->next;
        delete aux;
        aux = head;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
void DoublyLinkedList<T>::sort(){
    NodeD<T>* aux;
    NodeD<T>* aux2;

    for(int i = 0; i < size - 1; i++){
        aux = head;

        for(int j = 0; j < size - i - 1; j++){
            aux2 = aux->next;

            if(aux->data > aux2->data){
                T temp = aux->data;
                aux->data = aux2->data;
                aux2->data = temp;
            }

            aux = aux->next;
        }
    }
}



template <typename T>
void DoublyLinkedList<T>::duplicate(){
    NodeD<T>* aux = head;

    while(aux != nullptr){
        NodeD<T>* aux2 = new NodeD<T>(aux->data);
        aux2->next = aux->next;
        aux2->prev = aux;

        if(aux->next != nullptr){
            aux->next->prev = aux2;

        } else {
            tail = aux2;
        }

        aux->next = aux2;
        size++;
        aux = aux2->next;

    }
}

template <typename T>
void DoublyLinkedList<T>::removeDuplicates(){
    sort();

    NodeD<T>* aux = head;

    while(aux != nullptr && aux->next != nullptr){
        NodeD<T>* aux2 = aux->next;

        if(aux->data == aux2->data){
            aux->next = aux2->next;

            if(aux2 == tail){
                tail = aux;
            } else {
                aux2->next->prev = aux;
            }

            delete aux2;
            size--;

        } else {
            aux = aux->next;
        }
    }
}




template <typename T>
T& DoublyLinkedList<T>::operator[](int index){
    int auxIndex = 0;

    NodeD<T>* aux = head;
    while(auxIndex < size){
        if(auxIndex == index){
            return aux->data;

        }


        aux = aux->next;
        auxIndex++;
    }
    throw out_of_range("Indice invalido");


}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& lista){
    if(this == &lista){

        return *this;
    }
    clear();

    NodeD<T>* aux = lista.head;
    while(aux != nullptr){
        addLast(aux->data);
        aux = aux->next;

    }

    return *this;
}

template <typename T>
NodeD<T>* DoublyLinkedList<T>:: mitad(NodeD<T>* inicio){
    NodeD<T>* aux = inicio;
    NodeD<T>* aux2 = inicio->next;

    while(aux2 != nullptr && aux2->next != nullptr){
        aux = aux->next; // Avanza 1 nodo
        aux2 = aux2-> next-> next; // avanza 2 nodos
    }
    return aux;
}

template <typename T>
NodeD<T>* DoublyLinkedList<T>:: merge(NodeD<T>* left, NodeD<T>* right){  
    
    if(left == nullptr){
    return right;
    } else if (right == nullptr){
        return left;
    } 
    


    NodeD<T>* aux;
    comparaciones ++;

    if(compararFecha(left-> data, right-> data)){
        aux = left;
        aux->next = merge(left-> next, right);
    } else {
        aux = right;
        aux -> next = merge(left, right-> next);
    }

    if(aux-> next != nullptr){
        aux->next-> prev = aux;
    }

    aux-> prev = nullptr;
    return aux;



}

template <typename T>
NodeD<T>* DoublyLinkedList<T>:: mergeSort(NodeD<T>* inicio, int profundidad){
    if(profundidad > profundidadMax){
        profundidadMax = profundidad;
    }
    
    if(inicio == nullptr || inicio -> next == nullptr){
        return inicio;
    }

    NodeD<T>* aux = mitad(inicio);
    NodeD<T>* right = aux-> next;

    aux-> next = nullptr;
    right -> prev = nullptr;

    NodeD<T>* left = mergeSort(inicio, profundidad + 1);
    right = mergeSort(right, profundidad + 1);

    return merge(left, right);
} 

template <typename T>
void DoublyLinkedList<T>:: ordenarLogs(){
    comparaciones =0;
    profundidadMax =0;
    head = mergeSort(head, 1);
    tail = head;

    while (tail != nullptr && tail->next != nullptr){
        tail = tail-> next;
    }

}

template<typename T>
void DoublyLinkedList<T>:: generarArchivo(string archivoOutput){
    ofstream archivo(archivoOutput);

    if(!archivo.is_open()){
        cout<<"No se pudo crear el archivo"<<endl;
        return;
    }
    NodeD<T>* aux = head;

    while(aux != nullptr){
        archivo<<aux->data.mes<<" "<<aux->data.fecha<<" "<<aux->data.anno<<" "<<aux->data.hora<<" "<<aux->data.ip <<aux->data.mensaje<<endl;
        aux = aux->next;
    }

    archivo.close();
}

template<typename T>
bool DoublyLinkedList<T>::verificarOrdenArchivo(){
    NodeD<T>* aux = head;
    while(aux != nullptr && aux->next !=nullptr){

        if(compararFecha(aux-> next-> data, aux->data)){
            return false;

        }
        aux = aux->next;
        
    }


    return true;
}

template <typename T>
void DoublyLinkedList<T>:: imprimirAdelante(){
    NodeD<T>* aux = head;
    while(aux != nullptr){
        cout<<aux-> data<< " ";
        aux = aux-> next;
    }
    cout<<endl;

}

template <typename T>
void DoublyLinkedList<T>:: imprimirAtras(){
    NodeD<T>* aux = tail;
    while(aux!= nullptr){
        cout<< aux-> data<<" ";
        aux = aux -> prev;
    }

    cout<<endl;
}








#endif /* DoublyLinkedList_h */