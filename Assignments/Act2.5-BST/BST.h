// Allison Charlize Arriaza Chachagua
//A00844457
#if !defined(BST_H)
#define BST_H
#include <iostream>
#include <string>
#include "Queue.h"
#include "NodeT.h"

using namespace std;

template <typename T>
class BST {
private:
    NodeT<T>* root;
    void printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot);
    int alturaArbol(NodeT<T>* node);
public:
    BST(): root (nullptr){}
    void insert(T data);
    void preOrder(NodeT<T>* node);
    void inOrder(NodeT<T>* node);
    void posOrder(NodeT<T>* node);
    void porNiveles();
    bool find(T data);
    void print();
    void visit(string metodo);
    void remove(T data);
    int altura();
    void ancestors(T data);
    int whatLevelAmI(T data);
    
};

template<typename T>
void BST<T>:: insert(T data){
    if (root == nullptr){
        // ARbol vacio
        root = new NodeT<T>(data);
    } else{
        // arbol no vacio
        // aux = root
        if (root != nullptr){
            NodeT<T>* aux = root;
            // Apuntador father = root 
            NodeT<T>* father = root;
            // encontrar  donde voy a insertar el nodo
            while (aux != nullptr){
                // validar si aux->data = data
                if (aux-> data == data){
                    return;
                } else{
                    father = aux;
                    if(data< aux-> data){
                        aux = aux-> left;

                    } else{
                        aux = aux -> right;

                    }


                }

            }
            if (data< father->data){
                father->left = new NodeT<T>(data);
            } else{
                father -> right = new NodeT<T>(data);
            }
        }



    

    }
}

template <typename T>
bool BST<T>:: find(T data) {
    // validamos que el árbol no este vacío
    if (root == nullptr) {
        // el árbol está vacío
        // retornamos false
        return false;
    } else {
        // el árbol no está vacío
        // creamos un apuntador aux igual a root
        NodeT<T>* aux = root;
        // itero en el árbol hasta encontrar el nodo a buscar o que no lo encuentre
        while (aux != nullptr) {
            // valido si aux->data es igual a data
            if (aux->data == data) {
                // son iguales, regreso true
                return true;
            } else {
                // recorremos aux
                //if (data < aux->data ? aux = aux->left : aux = aux->right);  
                if (data < aux->data) {
                    aux = aux->left;
                } else {
                    aux = aux->right;
                }
            }
        }
        // no se encontró el dato a buscar, regreso false
        return false;
    }
}

// Visit 
template <typename T>
void BST<T>:: visit(string metodo){
    if(metodo == "PreOrder"){
        preOrder(root);
    } else if (metodo == "InOrder") {
        inOrder (root);
        
    } else if(metodo == "PosOrden"){
        posOrder(root);

    } else if(metodo == "PorNiveles"){
        porNiveles();
    }
    cout<< endl;
}

// parte del root de izquierda a derecha 
template <typename T>
void BST<T>:: preOrder(NodeT<T>* node){
    if (node != nullptr){
        cout<< node-> data<<" ";
        preOrder(node-> left);
        preOrder(node-> right);
    }
}

template<typename T>
void BST<T>:: inOrder(NodeT<T>* node){
    if(node != nullptr){
        inOrder(node-> left);
        cout<< node-> data<<" ";
        inOrder(node-> right);
    }

}

template<typename T>
void BST<T>:: posOrder(NodeT<T>* node){
    if(node != nullptr){
        posOrder(node-> left);
        posOrder(node-> right);
        cout<< node-> data<<" ";
        
    }

}


template <typename T>
void BST<T>::porNiveles(){
    Queue<NodeT<T>*> datos;
    if(root != nullptr){
        datos.push(root);
    }

    while(datos.isEmpty() == false){
        NodeT<T>* aux = datos.front();
        datos.pop();
        cout << aux->data << " ";

        if(aux->left != nullptr){
            datos.push(aux->left);
        }

        if(aux->right != nullptr){
            datos.push(aux->right);
        }
    }
}

template <typename T>
void BST<T>:: remove(T data){

    // ARbol vacia 
    if(root != nullptr){
        // Es una hoja 

        // el nodo a borrar es root?
        if(root-> data == data){
            // validamos si no tiene hijos 
            if(root ->left == nullptr && root -> right == nullptr){
                NodeT<T>* aux = root;
                root = nullptr;
                delete aux; 
                return;
            }
            // root solo tiene un hijo
            if(root ->left== nullptr || root-> right == nullptr){
                NodeT<T>* aux = root;
                if(root-> left == nullptr){
                    root = root->right;
                } else{
                    root = root-> left;
                }

                delete aux;
                return;
                
            }
            // 

            NodeT<T>* aux = root;
            //Aux left es el mas grande del lado izquierdo
            if(aux-> left-> right == nullptr ){
                NodeT<T>* auxRemove = aux -> left;
                aux-> data = auxRemove -> data;
                aux -> left = auxRemove -> left;
                delete auxRemove;

                return;

            } else {
                NodeT<T>* fatherRemove = aux-> left;
                NodeT<T>* auxRemove= fatherRemove-> right;

                while(auxRemove-> right!= nullptr){
                    // PREGUNTAR
                    fatherRemove = auxRemove;
                    auxRemove = auxRemove-> right;
                }

                aux-> data = auxRemove-> data;
                // mover el ultimo numero hacia arriba;
                fatherRemove-> right = auxRemove-> left;
                delete auxRemove;
                return;
            }


        } else{
            // Buscar el nodo que quiero borrar
            NodeT<T>* aux = root;
            NodeT<T>* father = nullptr;

            while(aux != nullptr && aux->data != data){
                father = aux;

                if(data < aux->data){
                    aux = aux->left;
                } else {
                    aux = aux->right;
                }
            }

            // No se encontro el dato
            if(aux == nullptr){
                return;
            }

            // El nodo no tiene hijos
            if(aux->left == nullptr && aux->right == nullptr){
                if(father->left == aux){
                    father->left = nullptr;
                } else {
                    father->right = nullptr;
                }
                delete aux;
                return;
            }

            // El nodo tiene un hijo
            if(aux->left == nullptr || aux->right == nullptr){
                NodeT<T>* hijo = nullptr;

                if(aux->left != nullptr){
                    hijo = aux->left;
                } else {
                    hijo = aux->right;
                }

                if(father->left == aux){
                    father->left = hijo;
                } else {
                    father->right = hijo;
                }

                delete aux;
                return;
            }

            // El nodo tiene dos hijos
            if(aux->left->right == nullptr){
                NodeT<T>* auxRemove = aux->left;

                aux->data = auxRemove->data;
                aux->left = auxRemove->left;

                delete auxRemove;
                return;
            } else {
                NodeT<T>* fatherRemove = aux->left;
                NodeT<T>* auxRemove = fatherRemove->right;

                while(auxRemove->right != nullptr){
                    fatherRemove = auxRemove;
                    auxRemove = auxRemove->right;
                }

                aux->data = auxRemove->data;
                fatherRemove->right = auxRemove->left;

                delete auxRemove;
                return;
            }

        }

            
    }

}



template <typename T>
// no hay nodo
int BST<T>::alturaArbol(NodeT<T>* node){
    if(node == nullptr){
        return -1;
    }
    // Calcular la altura de ambos lados
    int heightLeft = alturaArbol(node->left);
    int heightRight = alturaArbol(node->right);

    // Regresar la altura mayor
    if(heightLeft > heightRight){
        return heightLeft + 1;
    } else {
        return heightRight + 1;
    }
}

template <typename T>
int BST<T>::altura(){
    // empezar desde root
    return alturaArbol(root);
}



template <typename T>
void BST<T>::ancestors(T data){
    if(find(data) == false){
        cout << "Dato no encontrado" << endl;
        return;
    }
    NodeT<T>* aux = root;

    // La raiz no tiene ancestros
    if(aux->data == data){
        cout << "La raiz no tiene ancestros" << endl;
        return;
    }
    // Encontrar el datp
    while(aux != nullptr && aux->data != data){
        cout << aux->data << " ";

        if(data < aux->data){
            aux = aux->left;
        } else {
            aux = aux->right;
        }
    }

    cout << endl;
}


template <typename T>
int BST<T>::whatLevelAmI(T data){
    NodeT<T>* aux = root;
    int nivel = 0;

    while(aux != nullptr){
        if(aux->data == data){
            return nivel;
        }
        // Avanzar a la izquierda o derecha
        if(data < aux->data){
            aux = aux->left;
        } else {
            aux = aux->right;
        }
        nivel ++;
    }

    return -1;
}




template <typename T>
void BST<T>::printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot) {
    if (node == nullptr) return;
    printTree(node->right, prefix + (isRoot ? "" : (isRight ? "      " : "|     ")), true, false);
    cout << prefix << (isRoot ? "" : (isRight ? ".---- " : "`---- ")) << node->data << endl;
    printTree(node->left,  prefix + (isRoot ? "" : (isRight ? "|     " : "      ")), false, false);
}

template <typename T>
void BST<T>::print() {
    if (root == nullptr) { cout << "(arbol vacio)" << endl; return; }
    printTree(root, "", false, true);
}


#endif // BST_H