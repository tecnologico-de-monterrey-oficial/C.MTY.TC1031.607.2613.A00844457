//Allison Charlize Arriaza Chachagua 
//A00844457

#ifndef Log_h
#define Log_h
#include <string>
using namespace std;

struct Log{
    string mes;
    int fecha;
    int anno;
    string hora;
    string ip;
    string mensaje;

};

int numerosMeses(string mes){
    if(mes == "Jan") return 1;
    if(mes == "Feb") return 2;
    if(mes == "Mar") return 3;
    if(mes == "Apr") return 4;
    if(mes == "May") return 5;
    if(mes == "Jun") return 6;
    if(mes == "Jul") return 7;
    if(mes == "Aug") return 8;
    if(mes == "Sep") return 9;
    if(mes == "Oct") return 10;
    if(mes == "Nov") return 11;
    if(mes == "Dec") return 12;


    return 0;
}

bool compararFecha(Log a, Log b){
    if (a.anno != b.anno){
        return a.anno < b.anno;
    }

    if(numerosMeses(a.mes) != numerosMeses(b.mes)){
        return numerosMeses(a.mes) < numerosMeses(b.mes);
    }

    if(a.fecha != b.fecha){
        return a.fecha < b.fecha;
    }

    return a.hora < b.hora;
}



#endif