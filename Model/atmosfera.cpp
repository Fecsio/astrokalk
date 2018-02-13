#include "atmosfera.h"

Atmosfera::Atmosfera(double o, double a, double ar): ossigeno(o), azoto(a), altro(ar){
    if(a+o+ar != 100 || o < 0 || a <0 || ar < 0){
        ossigeno = 21;
        azoto = 78;
        altro = 1;
    }
}

double Atmosfera::getAl() const{
    return altro;
}

double Atmosfera::getAz() const{
    return azoto;
}
double Atmosfera::getO() const{
    return ossigeno;
}

Atmosfera Atmosfera::operator+(const Atmosfera& a) const{
    return Atmosfera((ossigeno+a.ossigeno)/2, (azoto+a.azoto)/2, (altro+a.altro)/2);
}
