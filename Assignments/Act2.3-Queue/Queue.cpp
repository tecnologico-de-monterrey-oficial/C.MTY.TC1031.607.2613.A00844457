//Allison Charlize Arriaza Chachagua
//A00844457

#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"

struct Cliente{
    string nombre;
    int boletos;
};


int main (){
    Queue<Cliente> fila;
    int opcion;

    while (opcion!= 5){
        cout<<"=============MENU================"<<endl;
        cout<<"1. Agregar cliente"<<endl;
        cout<<"2. Atender cliente"<<endl;
        cout<<"3. Ver siguiente cliente"<<endl;
        cout<<"4. Mostrar cuantas personas se encuentran en la fila"<<endl;
        cout<<"5. Salir"<<endl;
        cout <<"Opcion: ";
        cin>>opcion;

        if (opcion == 1){
            Cliente nuevo;
            cout<<"Nombre: ";
            cin>>nuevo.nombre;
            cout<<"Numero de boletos: ";
            cin>>nuevo.boletos;
            
            fila.push(nuevo);
            cout<<"Cliente agregado"<<endl;

        } else if(opcion == 2){
            if (fila.getsize()> 0){
                Cliente atendido = fila.pop();
                cout<<"Atendiendo a: "<<atendido.nombre<<endl;
                cout<<"Numero de boletos pedidos: "<<atendido.boletos;

            } else{
                cout<<"No hay clientes en la fila"<<endl;
            }

        } else if(opcion == 3){
            
            if(fila.getsize()>0){
                Cliente siguiente = fila.front();
                
                cout<<"Siguiente en la fila: "<<siguiente.nombre<<endl;
                cout<<"Cantidad de boletos: "<<siguiente.boletos<<endl;
                
            } else {
                cout<<"No hay cliente en la fila"<<endl;
            }
            

        } else if (opcion == 4){
            cout<<"Personas en la fila: "<<fila.getsize()<<endl;

        } else if(opcion == 5){
            cout<< "fin del programa"<<endl;
        }else{
            cout<<"opcion invalida"<< endl;

        }

    }



    return 0;
}