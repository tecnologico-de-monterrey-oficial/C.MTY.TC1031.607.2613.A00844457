// Allison Charlize Arriaza Chachagua
//A00844457

#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"

struct PaginaWeb{
   string titulo;
   string url;
};


int main (){
    Stack<PaginaWeb>historial;
    int opcion =0;

    while (opcion != 5){
        cout<<"===========Menu=============="<<endl;
        cout<<"1. Visitar pagina nueva"<<endl;
        cout<<"2. Retroceder pagina anterior"<<endl;
        cout<<"3. Ver pagina actual"<<endl;
        cout<<"4. Mostrar cantidad de paginas en historial"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Opcion: ";

        cin>>opcion;

        if(opcion == 1){
            PaginaWeb nuevaPag;
            cout<<"Titulo: ";
            cin>>nuevaPag.titulo;
            cout<<"URL: ";
            cin>>nuevaPag.url;

            historial.push(nuevaPag);
        } else if(opcion == 2){
            if(historial.getSize()>0){
                PaginaWeb pagAnterior = historial.pop();
                cout<<"Saliendo de: "<<pagAnterior.titulo<<endl;
                
            }else{
                cout<<"No existia una pagina previa"<<endl;
            }

        } else if(opcion == 3){
            if (historial.getSize()>0){
                PaginaWeb pagActual = historial.top();
                cout<<"Pagina actual: "<<pagActual.titulo<<endl;
                cout<<"URL: "<<pagActual.url<<endl;

            } else{
                cout<<"No existe paginas en el historial"<<endl;
            }

        }else if(opcion == 4){
            cout<<"Paginas en el historial: "<<historial.getSize()<<endl;
        } else if(opcion == 5){
            cout<<"Fin del programa"<<endl;

        } else {
            cout<<"Error, intente nuevamente"<<endl;
        }

    }






    return 0;
}