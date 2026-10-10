//Allison Charlize Arriaza Chachagua
//A00844457

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DoublyLinkedList.h"

using namespace std;


int main(){
    DoublyLinkedList<int> lista;
    DoublyLinkedList<int> lista2;

    int opcion = 0;
    int dato;
    int nuevo;
    int index;
    int cantidad;
    int tipo;

    srand(time(0));

    cout<<"Como quieres llenar la lista?"<<endl;
    cout<<"1. Manualmente"<<endl;
    cout<<"2. Aleatoriamente"<<endl;
    cout<<"Opcion: ";
    cin>>tipo;

    if(tipo == 1){
        cout<<"Cuantos datos quieres agregar? ";
        cin>>cantidad;

        for(int i = 0; i < cantidad; i++){

            cout<<"Dato "<<i+1<<": ";
            cin>>dato;
            lista.addLast(dato);

        }

    } else if(tipo == 2){
        cout<<"Cuantos datos quieres generar? ";
        cin>>cantidad;

        for(int i = 0; i < cantidad; i++){
            dato = rand() % 100;
            lista.addLast(dato);
        }
    }


    while(opcion != 17){
        cout<<endl;
        cout<<"=============MENU=================="<<endl;
        cout<<"1. Agregar al inicio"<<endl;
        cout<<"2. Agregar al final"<<endl;
        cout<<"3. Insertar despues de un indice"<<endl;
        cout<<"4. Eliminar por indice"<<endl;
        cout<<"5. Buscar dato"<<endl;
        cout<<"6. Eliminar por dato"<<endl;
        cout<<"7. Obtener dato por indice"<<endl;
        cout<<"8. Actualizar dato"<<endl;
        cout<<"9. Actualizar por indice"<<endl;
        cout<<"10. Consultar o modificar con []"<<endl;
        cout<<"11. Copiar lista"<<endl;
        cout<<"12. Vaciar lista"<<endl;
        cout<<"13. Ordenar lista"<<endl;
        cout<<"14. Duplicar elementos"<<endl;
        cout<<"15. Eliminar duplicados"<<endl;
        cout<<"16. Mostrar lista"<<endl;
        cout<<"17. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;


        if(opcion == 1){
            cout<<"Dato: ";
            cin>>dato;

            lista.addFirst(dato);
            cout<<"Dato agregado"<<endl;

        } else if(opcion == 2){
            cout<<"Dato: ";
            cin>>dato;
            lista.addLast(dato);

            cout<<"Dato agregado"<<endl;

        } else if(opcion == 3){
            cout<<"Indice: ";
            cin>>index;
            cout<<"Dato: ";
            cin>>dato;

            if(index >= 0 && index < lista.getSize()){
                lista.insert(index, dato);
                cout<<"Dato insertado"<<endl;
            } else {
                cout<<"Indice invalido"<<endl;
            }

        } else if(opcion == 4){
            cout<<"Indice: ";
            cin>>index;

            if(lista.deleteAt(index)){
                cout<<"Dato eliminado"<<endl;
            } else {
                cout<<"Indice invalido"<<endl;
            }


        } else if(opcion == 5){
            cout<<"Dato a buscar: ";
            cin>>dato;
            index = lista.findData(dato);

            if(index != -1){
                cout<<"Dato encontrado en indice: "<<index<<endl;
            } else {
                cout<<"Dato no encontrado"<<endl;
            }

        } else if(opcion == 6){
            cout<<"Dato a eliminar: ";
            cin>>dato;

            if(lista.deleteData(dato)){
                cout<<"Dato eliminado"<<endl;
            } else {
                cout<<"Dato no encontrado"<<endl;
            }

        } else if(opcion == 7){
            cout<<"Indice: ";
            cin>>index;

            if(index >= 0 && index < lista.getSize()){
                cout<<"Dato: "<<lista.getData(index)<<endl;
            } else {

                cout<<"Indice invalido"<<endl;
            }

        } else if(opcion == 8){
            cout<<"Dato a actualizar: ";
            cin>>dato;
            cout<<"Nuevo dato: ";
            cin>>nuevo;

            if(lista.findData(dato) != -1){

                lista.updateData(dato, nuevo);
                cout<<"Dato actualizado"<<endl;

            } else {
                cout<<"Dato no encontrado"<<endl;
            }

        } else if(opcion == 9){
            cout<<"Indice: ";
            cin>>index;
            cout<<"Nuevo dato: ";
            cin>>dato;

            if(index >= 0 && index < lista.getSize()){
                lista.updateAt(index, dato);
                cout<<"Dato actualizado"<<endl;

            } else {
                cout<<"Indice invalido"<<endl;
            }

        } else if(opcion == 10){
            cout<<"1. Consultar"<<endl;
            cout<<"2. Modificar"<<endl;
            cout<<"Opcion: ";
            cin>>tipo;

            cout<<"Indice: ";
            cin>>index;

            if(index >= 0 && index < lista.getSize()){
                if(tipo == 1){
                    cout<<"Dato: "<<lista[index]<<endl;
                } else if(tipo == 2){
                    cout<<"Nuevo dato: ";
                    cin>>dato;
                    lista[index] = dato;
                    cout<<"Dato actualizado"<<endl;

                } else {
                    cout<<"Opcion invalida"<<endl;
                }


            } else {
                cout<<" Indice invalido"<<endl;
            }

        } else if(opcion == 11){
            lista2 = lista;
            cout<<"Lista copiada "<<endl;

        } else if(opcion == 12){
            lista.clear();
            cout<<"Lista vaciada"<<endl;


        } else if(opcion == 13){
            lista.sort();
            cout<<"Lista ordenada"<<endl;

        } else if(opcion == 14){
            lista.duplicate();
            cout<<"Elementos duplicados "<<endl;


        } else if(opcion == 15){
            lista.removeDuplicates();
            cout<<"Duplicados eliminados"<<endl;

        } else if(opcion == 16){
            cout<<"Lista: ";

            for(int i = 0; i < lista.getSize(); i++){
                cout<<lista[i]<<" ";
            }
            cout<<endl;

        } else if(opcion == 17){
            cout<<"Fin del programa"<<endl;

            
        } else {
            cout<<"Opcion invalida"<<endl;
        }


    }

    return 0;
}