# Evidencia 1
Este programa trabaja con archivos de logs y permite ordenarlos por fecha y hora usando diferentes algoritmos de ordenamiento.

Los archivos utilizados fueron:
- log607-1.txt
- log607-2.txt

## Algoritmos utilizados
- Swap Sort
- Bubble Sort
- Selection Sort
- Insertion Sort
- Shell Sort
- Merge Sort
- Quick Sort

El programa también utiliza búsqueda binaria para encontrar registros dentro de un rango de fechas.

## ¿Qué hace el programa?
Primero se selecciona uno de los archivos y después el algoritmo que se quiere utilizar. Antes de ejecutarlo, el programa pide una predicción sobre si se espera que sea rápido o lento.

Después se mide el tiempo de ejecución y se muestran algunos datos como el algoritmo utilizado, la cantidad de registros y su complejidad.

Los registros ordenados se guardan en:
`output608.txt`

Después se puede ingresar una fecha inicial y una fecha final para buscar registros dentro de ese rango. Los resultados se guardan en:
`range607.txt`

Al final también se puede realizar otra corrida sin tener que cerrar el programa.

## Compilación
```bash
g++ main.cpp -o programa
```
## Ejecución
```bash
./programa
```

## Video
https://youtu.be/Osi02lBqhKs


