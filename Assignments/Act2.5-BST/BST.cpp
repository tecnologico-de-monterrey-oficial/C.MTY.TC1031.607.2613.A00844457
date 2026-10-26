
#include <iostream>
using namespace std;

#include "BST.h"

int main(){
    BST<int> bst;

    int opcion = 0;
    int dato;
    int recorrido;
    int nivel;

    while(opcion != 9){
        cout<<endl;
        cout<<"==========Menu BST==========="<<endl;
        cout<<"1. Insertar dato"<<endl;
        cout<<"2. Eliminar dato"<<endl;
        cout<<"3. Mostrar recorridos"<<endl;
        cout<<"4. Buscar dato"<<endl;
        cout<<"5. Altura del arbol"<<endl;
        cout<<"6. Mostrar ancestros"<<endl;
        cout<<"7. Nivel de un nodo"<<endl;
        cout<<"8. Imprimir arbol"<<endl;
        cout<<"9. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        

        if(opcion == 1){
            cout<<"Dato a insertar: ";
            cin>>dato;
            bst.insert(dato);
            cout<<"Dato insertado"<<endl;


        } else if(opcion == 2){
            cout<<"Dato a eliminar: ";
            cin>>dato;

            if(bst.find(dato) == true){
                bst.remove(dato);
                cout<<"Dato eliminado"<<endl;
            } else {
                cout<<"Dato no encontrado"<<endl;
            }

        } else if(opcion == 3){
            cout<<"1. PreOrder"<<endl;
            cout<<"2. InOrder"<<endl;
            cout<<"3. PosOrden"<<endl;
            cout<<"4. Por niveles"<<endl;
            cout<<"Opcion: ";
            cin>> recorrido;

            if(recorrido == 1){
                bst.visit("PreOrder");
            } else if(recorrido == 2){
                bst.visit("InOrder");
            } else if(recorrido == 3){
                bst.visit("PosOrden");
            } else if(recorrido == 4){
                bst.visit("PorNiveles");
            } else {
                cout<<"Opcion no valida"<<endl;
            }



        } else if(opcion == 4){
            cout<<"Dato a buscar: ";
            cin>>dato;

            if(bst.find(dato) == true){
                cout<<"Dato encontrado"<<endl;
            } else {
                cout<<"Dato no encontrado"<<endl;
            }


        } else if(opcion == 5){
            cout<<"Altura: "<<bst.altura()<<endl;


        } else if(opcion == 6){
            cout<<"Dato: ";
            cin>>dato;

            cout<<"Ancestros: ";
            bst.ancestors(dato);

        } else if(opcion == 7){
            cout<<"Dato: ";
            cin>>dato;

            nivel = bst.whatLevelAmI(dato);

            if(nivel == -1){
                cout<<"Dato no encontrado"<<endl;
            } else {
                cout<<"Nivel: "<<nivel<<endl;
            }

        } else if(opcion == 8){
            bst.print();

        } else if(opcion == 9){
            cout<<"Fin del programa"<<endl;

        } else {
            cout<<"Opcion no valida"<<endl;
        }


    }

    
    return 0;
}
