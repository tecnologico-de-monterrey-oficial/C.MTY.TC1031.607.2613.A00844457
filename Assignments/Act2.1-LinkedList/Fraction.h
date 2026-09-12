# ifdef Fraction_h
#ifndef Fraction_h


class Fraction{

    private:
        int numerador;
        int denominador;

    public:
        // Constructor
        Fraction(int num = 0, int den = 1) {
            numerador = num;

            if (den != 0) {
                denominador = den;
            } else {
                denominador = 1;
            }
        }

        // Getters
        int getNumerador() {
            return numerador;
        }

        int getDenominador() {
            return denominador;
        }

        // Setters
        void setNumerador(int num) {
            numerador = num;
        }

        void setDenominador(int den) {
            if (den != 0) {
                denominador = den;
            }
        }

        // Imprimir fracción
        void imprimir() {
            cout << numerador << "/" << denominador << endl;
        }
    };

int main() {
    Fraction f1(3, 4);

    f1.imprimir();

    cout << "Numerador: " << f1.getNumerador() << endl;
    cout << "Denominador: " << f1.getDenominador() << endl;


}







#endif /* Fraction_h*/