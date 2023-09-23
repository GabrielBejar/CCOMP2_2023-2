#include <iostream>
using namespace std;

string ConvMenCien(int n) {
    string unid[] = { "cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve" };

    string dec[] = { "diez","veinte","treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa" };

    string casosesp[] = { "diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho",
                         "diecinueve","veinte","veintiuno","veintidos","veintitres","veinticuatro","veinticinco",
                         "veintiseis","veintisiete" ,"veintiocho" ,"veintinueve" };

    if (n < 10) {
        return unid[n];
    }
    else {
        int unidad = n % 10;
        int decena = n / 10;
        string res;

        if (decena == 1 || decena == 2) {
            if (unidad == 0) {
                res = dec[decena - 1];
            }
            else {
                if (decena == 1) {
                    res = casosesp[unidad];
                }
                else {
                    res = casosesp[unidad + 10];
                }

            }
            return res;
        }
        res = dec[decena - 1];
        if (unidad != 0) {
            res += " y " + unid[unidad];
        }
        return res;
    }
}

string ConvMenMil(int n) {
    if (n < 100) {
        return ConvMenCien(n);
    }
    else {
        int centenas = n / 100;
        int resto = n % 100;
        string res;

        if (n == 100) {
            res = "ciento";
            return res;
        }

        if (centenas == 1) {
            if (resto == 0) {
                return "mil";
            }
            else {
                return "ciento " + ConvMenCien(resto);
            }
        }

        if (centenas == 5) {
            res = "quinientos";
        }
        else if (centenas == 7) {
            res = "setecientos";
        }
        else if (centenas == 9) {
            res = "novecientos";
        }
        else {
            res = ConvMenCien(centenas) + "cientos";
        }
        if (resto != 0) {
            res += " " + ConvMenCien(resto);
        }
        return res;
    }
}

int main() {
    int numero;
    cout << "Ingrese un numero entre 0 y 1 000 000: ";
    cin >> numero;

    if (numero == 1000000) {
        cout << "Un millon";
    }
    else {
        string res;
        if (numero < 1000) {
            res = ConvMenMil(numero);
        }
        else {
            int miles = numero / 1000;
            int resto = numero % 1000;
            int esp{ numero };
            esp = esp / 1000;
            esp = esp % 10;
            if (miles == 1) {
                res = "mil";
            }
            else {
                if (esp == 1) {
                    res = ConvMenMil(miles - 1) + " un mil";
                }
                else {
                    res = ConvMenMil(miles) + " mil";
                }
            }
            if (resto != 0) {
                res += " " + ConvMenMil(resto);
            }
        }
        cout << "El numero se lee: " << endl << res << endl;
    }
    return 0;
}
