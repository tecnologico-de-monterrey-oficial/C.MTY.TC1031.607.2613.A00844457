//Allison Charlize Arriaza Chachagua
//A00844457

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.h"
using namespace std;

int main() {
    int tipoLista;
    int tipoLlenado;
    int tamanno;
    srand(time(0));
    cout << "Tipo de lista" << endl;
    cout << "1. int" << endl;
    cout << "2. double" << endl;
    cin >> tipoLista;
    cout << "Llenado" << endl;
    cout << "1. Manual" << endl;
    cout << "2. Aleatorio" << endl;
    cin >> tipoLlenado;
    cout << "Tamano de la lista: ";
    cin >> tamanno;

    if (tipoLista == 1) {
        LinkedList<int> lista;
        LinkedList<int> lista2;

        if (tipoLlenado == 1) {
            for (int i = 0; i < tamanno; i++) {
                int dato;

                cout << "Dato: ";
                cin >> dato;

                lista.push_back(dato);
            }
        } else {
            for (int i = 0; i < tamanno; i++) {
                int dato = rand() % 100 + 1;
                lista.push_back(dato);
            }
        }

        int opcion = -1;
        int dato;
        int nuevoDato;
        int index;

        while (opcion != 0) {
        cout << "====================MENU=================" << endl;
        cout << "1. Agregar al inicio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar despues de un indice" << endl;
        cout << "4. Borrar un  dato" << endl;
        cout << "5. Borrar por posicion " << endl;
        cout << "6. Obtener dato por posicion " << endl;
        cout << "7. Actualizar un dato" << endl;
        cout << "8. Actualizar por posicion" << endl;
        cout << "9. Buscar un dato" << endl;
        cout << "10. Obtener dato con []" << endl;
        cout << "11. Actualizar dato con []" << endl;
        cout << "12. Copiar lista " << endl;
        cout << "13. Imprimir lista" << endl;
        cout << "0. Salir" << endl;
        cout<<endl;

        cout<<"Opción: ";
        cin>>opcion;

            if (opcion == 1) {
                cout << "Dato: ";
                cin >> dato;
                lista.push_front(dato);
            }else if (opcion == 2) {
                cout << "Dato: ";
                cin >> dato;

                lista.push_back(dato);
            }else if (opcion == 3) {
                cout << "Indice: ";
                cin >> index;
                cout << "Dato: ";
                cin >> dato;

                lista.insert(index, dato);
            }else if (opcion == 4) {
                cout << "Dato: ";
                cin >> dato;

                lista.deleteData(dato);
            }else if (opcion == 5) {
                cout << "Indice: ";
                cin >> index;

                lista.deleteAt(index);
            }else if (opcion == 6) {
                cout << "Indice: ";
                cin >> index;

                cout << lista.getData(index) << endl;
            }else if (opcion == 7) {
                cout << "Dato actual: ";
                cin >> dato;

                cout << "Dato nuevo: ";
                cin >> nuevoDato;

                lista.updateData(dato, nuevoDato);
            }else if (opcion == 8) {
                cout << "Indice: ";
                cin >> index;

                cout << "Dato nuevo: ";
                cin >> dato;

                lista.updateAt(index, dato);
            }else if (opcion == 9) {
                cout << "Dato: ";
                cin >> dato;
                index = lista.findData(dato);

                if (index != -1) {
                    cout << "Indice: " << index << endl;
                } else {
                    cout << "No encontrado" << endl;
                }
            }else if (opcion == 10) {
                cout << "Indice: ";
                cin >> index;

                cout << lista[index] << endl;
            }else if (opcion == 11) {
                cout << "Indice: ";
                cin >> index;

                cout << "Dato nuevo: ";
                cin >> dato;

                lista[index] = dato;
            }else if (opcion == 12) {
                lista2 = lista;

                cout << "Lista copiada: ";
                lista2.print();
            }else if (opcion == 13) {
                lista.print();
            }
        }
    }

    else if (tipoLista == 2) {
        LinkedList<double> lista;
        LinkedList<double> lista2;

        if (tipoLlenado == 1) {
            for (int i = 0; i < tamanno; i++) {
                double dato;

                cout << "Dato: ";
                cin >> dato;

                lista.push_back(dato);
            }
        } else {
            for (int i = 0; i < tamanno; i++) {
                double dato = (rand() % 1000) / 10.0;
                lista.push_back(dato);
            }
        }

        int opcion = -1;
        double dato;
        double nuevoDato;
        int index;

        while (opcion != 0) {
        cout << "====================MENU=================" << endl;
        cout << "1. Agregar al inicio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Insertar despues de un indice" << endl;
        cout << "4. Borrar un  dato" << endl;
        cout << "5. Borrar por posicion " << endl;
        cout << "6. Obtener dato por posicion " << endl;
        cout << "7. Actualizar un dato" << endl;
        cout << "8. Actualizar por posicion" << endl;
        cout << "9. Buscar un dato" << endl;
        cout << "10. Obtener dato con []" << endl;
        cout << "11. Actualizar dato con []" << endl;
        cout << "12. Copiar lista " << endl;
        cout << "13. Imprimir lista" << endl;
        cout << "0. Salir" << endl;

            if (opcion == 1) {
                cout << "Dato: ";
                cin >> dato;

                lista.push_front(dato);
            }

            else if (opcion == 2) {
                cout << "Dato: ";
                cin >> dato;

                lista.push_back(dato);
            }

            else if (opcion == 3) {
                cout << "Indice: ";
                cin >> index;

                cout << "Dato: ";
                cin >> dato;

                lista.insert(index, dato);
            }

            else if (opcion == 4) {
                cout << "Dato: ";
                cin >> dato;

                lista.deleteData(dato);
            }

            else if (opcion == 5) {
                cout << "Indice: ";
                cin >> index;

                lista.deleteAt(index);
            }

            else if (opcion == 6) {
                cout << "Indice: ";
                cin >> index;

                cout << lista.getData(index) << endl;
            }

            else if (opcion == 7) {
                cout << "Dato actual: ";
                cin >> dato;

                cout << "Dato nuevo: ";
                cin >> nuevoDato;

                lista.updateData(dato, nuevoDato);
            }

            else if (opcion == 8) {
                cout << "Indice: ";
                cin >> index;

                cout << "Dato nuevo: ";
                cin >> dato;

                lista.updateAt(index, dato);
            }

            else if (opcion == 9) {
                cout << "Dato: ";
                cin >> dato;

                index = lista.findData(dato);

                if (index != -1) {
                    cout << "Indice: " << index << endl;
                } else {
                    cout << "No encontrado" << endl;
                }
            }

            else if (opcion == 10) {
                cout << "Indice: ";
                cin >> index;

                cout << lista[index] << endl;
            }

            else if (opcion == 11) {
                cout << "Indice: ";
                cin >> index;

                cout << "Dato nuevo: ";
                cin >> dato;

                lista[index] = dato;
            }

            else if (opcion == 12) {
                lista2 = lista;

                cout << "Lista copiada: ";
                lista2.print();
            }

            else if (opcion == 13) {
                lista.print();
            }
        }
    }

    return 0;
}