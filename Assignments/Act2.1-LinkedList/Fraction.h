#ifndef Fraction_H
#define Fraction_H
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerador;
    int denominador;

public:
    Fraction(int num = 0, int den = 1) {
        numerador = num;

        if (den != 0){
            denominador = den;

        }else {

            denominador = 1;

        }      
    }

    int getNumerador() const {
        return numerador;
    }

    int getDenominador() const {
        return denominador;
    }

    void setNumerador(int num) {
        numerador = num;
    }

    void setDenominador(int den) {
        if (den != 0)
            denominador = den;
    }

    void imprimir() const {
        cout << numerador << "/" << denominador << endl;
    }

    bool operator==(const Fraction& otra) const {
        return numerador == otra.numerador && denominador == otra.denominador;
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerador << "/" << f.denominador;
        return os;
    }
};

#endif
