#include "atmosfera.h"

Atmosfera::Atmosfera(double o, double a, double ar): ossigeno(o), azoto(a), argon(ar){
    if(a+o+ar != 100 || o < 0 || a <0 || ar < 0){
        ossigeno = 21;
        azoto = 78;
        argon = 1;
    }
}

double Atmosfera::getAr() const{
    return argon;
}

double Atmosfera::getAz() const{
    return azoto;
}
double Atmosfera::getO() const{
    return ossigeno;
}

Atmosfera Atmosfera::operator+(const Atmosfera& a) const{
    return Atmosfera((ossigeno+a.ossigeno)/2, (azoto+a.azoto)/2, (argon+a.argon)/2);
}
