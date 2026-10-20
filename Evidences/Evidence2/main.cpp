//Allison Charlize Arriaza Chachagua 
// A00844457

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <map>
#include "log.h"
#include "Queue.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
using namespace std;


int main(){
    int opcionArchivo;
    int opcion = 0;
    string nombreArchivo;

    cout<<"===============MENU=============================="<<endl;
    cout<<"Que archivo desea cargar?"<<endl;
    cout<<"Para log607-1.txt ingrese 1"<<endl;
    cout<<"Para log607-2.txt ingrese 2"<<endl;
    cout<<"opcion: ";
    cin>>opcionArchivo;

    if(opcionArchivo == 1){
        nombreArchivo = "log607-1.txt";
    } else if(opcionArchivo == 2){
        nombreArchivo = "log607-2.txt";
    } else{
        cout<<"Error intente nuevamente";
        return 1;
    }

    ifstream abrirArchivo(nombreArchivo);

    if(!abrirArchivo.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        return 1;

    }  else {
        cout<<"Los archivos se pudieron abrir"<<endl;
    }

    Log registro;
    int cont =0;
    Queue<Log> datos;

    while(true){
        abrirArchivo>> registro.mes;
        abrirArchivo>> registro.fecha;
        abrirArchivo>> registro.anno;
        abrirArchivo>> registro.hora;
        abrirArchivo>> registro.ip;

        if (!abrirArchivo){
            break;
        }

        getline(abrirArchivo, registro.mensaje);
        datos.push(registro);
        cont ++;
    }

    DoublyLinkedList<Log> lista;
    while(datos.getsize() > 0){
        lista.addLast(datos.front());
        datos.pop();
    }

    cout<<"Total de registros: "<<cont<<endl;
    cout<<"Logs en lista: "<<lista.getSize()<<endl;

    bool ordenado = false; 
    string buscarMes;
    int buscarFecha;
    int buscarAnno;
    int encontrado = 0;
    bool buscandoFecha = true;



    while (opcion != 5){
        cout<<"===============MENU================"<<endl;
        cout<<"1. Ordenar por fecha y hora"<<endl;
        cout<<"2. Buscar logs por dia"<<endl;
        cout<<"3. Mostrar logs en orden descendente"<<endl;
        cout<<"4. Estadisticas del archivo"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        if(opcion == 1){
            if(ordenado == true){
                cout<<"Los registros ya fuero ordenados"<<endl;
            } else{
                int prediccion;
                cout<<"Que crecimiento esperas en las comparaciones?"<<endl;
                cout<<"1. n log n"<<endl;
                cout<<"2. n^2"<<endl;
                cout<<"Opcion: ";
                cin>>prediccion;


                auto inicioChrono = chrono::high_resolution_clock::now();
                lista.ordenarLogs();

                auto finChrono = chrono::high_resolution_clock::now();
                chrono::duration<double, milli> tiempoChrono = finChrono - inicioChrono;
                ordenado = true;
                cout<< "Algotitmo: Merge Sort "<<endl;
                cout<< "Archivo: "<<nombreArchivo<<endl;
                cout<< "Tiempo de ejecución: "<<tiempoChrono.count()<<" ms"<<endl;
                cout<<"Logs ordenados: "<<lista.getSize()<<endl;
                cout<<"Comparaciones: "<<lista.getComparaciones()<<endl;
                cout<<"Profundidad maxima: "<<lista.getProfundidadMaxima()<<endl;

                if(prediccion == 1){
                    cout<<"La prediccion coincide con Merge Sort (n log n)"<<endl;
                } else if(prediccion ==2){
                    cout<<"La prediccion no coincide con Merge Sort"<<endl;
                } else{
                    cout<<"Error, Prediccion invalida"<<endl;
                }

                lista.generarArchivo("output608.out");
                cout<<"Archivo output608.out creado"<<endl;
            }
        } else if(opcion == 2){
            if(ordenado == false){
                cout<<"Primero debes ordenar los logs con la opcion 1"<<endl;
            } else{
                    int encontrado = 0;

                    cout<< "Mes a buscar: ";
                    cin>>buscarMes;
                    cout<<"Buscar fecha: ";
                    cin>>buscarFecha;
                    cout<< "Buscar Año: ";
                    cin>>buscarAnno;

                    buscandoFecha = true;

                    for (int i =0; i<lista.getSize(); i++){
                        Log aux = lista.getData(i);

                        if(aux.mes == buscarMes && aux.fecha == buscarFecha && aux.anno == buscarAnno){
                            cout<<aux.mes<<" "<<aux.fecha<<" "<<aux.anno<<" "<<aux.hora<<" "<<aux.ip<<" "<<aux.mensaje<<endl;
                            encontrado ++;
                        }
                    }
                    if(encontrado == 0){
                        cout<<"No se encontraron los registros"<<endl;

                    }else{
                        cout<<"Registros encontrados: "<<encontrado<<endl;
                    }

                    
            }    
        }  else if(opcion == 3){
            if(ordenado == false){
                cout<<"Primero se deben de ordenar los archivos"<<endl;
            } else{
                Stack<Log> pila;
                
                if(buscarFecha == false){
                    cout<<"Mes: ";
                    cin>> buscarMes;
                    cout<< "Dia: ";
                    cin>>buscarFecha;
                    cout<<"Anno: ";
                    cin>>buscarAnno;

                }
                

                buscandoFecha = true;

                for (int i=0; i<lista.getSize();i++ ){
                    Log aux = lista.getData(i);

                    if(aux.mes == buscarMes && aux.fecha == buscarFecha && aux.anno == buscarAnno){
                        pila.push(aux);
                    }

                }

                int encontrado = pila.getSize();
                while(pila.getSize()>0){
                    Log aux = pila.pop();
                    cout<<aux.mes<<" "<<aux.fecha<<" "<<aux.anno<<" "<<aux.hora<<" "<<aux.ip<<" "<<aux.mensaje<<endl;
                    
                }

                cout<<"Registros encontrados: "<<encontrado<<endl;



            }
        }  else if(opcion ==4){
            map<string, int> fechas;
            map<string, int> mensajes;
            map<string, int> ips;

            cout<<"Total de registros: "<<lista.getSize()<<endl;

            for(int i =0; i>lista.getSize(); i++){
                Log aux = lista.getData(i);

                string fecha = aux.mes + " " + to_string(aux.fecha) + " " + to_string(aux.anno);

                fechas[fecha]++;
                mensajes[aux.mensaje]++;
                ips[aux.ip]++;
            }

            int fechaMax = 0;
            for(auto dato: fechas){
                if(dato.second > fechaMax){
                    fechaMax = dato.second;

                }
            }

            cout<<"Fecha con mas incidentes: "<<endl;
            for(auto dato: fechas){
                if(dato.second == fechaMax){
                    cout<<dato.first<<"-"<<dato.second<<" registros"<<endl;
                }
            }


        }   else if(opcion ==5){
            cout<<"Fin del programa"<<endl;
        } else{
            cout<<"Error, opcion invalida"<<endl;
        }
            
                    
    } 
        



    return 0;
}