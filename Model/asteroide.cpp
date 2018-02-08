#include "asteroide.h"
#include <math.h>

Asteroide::Asteroide(long double r, double ts, double dm, unsigned int e, double v):
    OggettoCeleste(r,ts,dm,e), velocita(v){}

Asteroide::Asteroide(const OggettoCeleste& o, double v): OggettoCeleste(o), velocita(v) {}

double Asteroide::getVel() const{
    return velocita;
}


ConseguenzaCollisione Asteroide::Collisione() const{
    long double ej = ((0.5)*Massa()*pow(10,12)*pow(velocita,2));
    unsigned int eMT = (2.39e-16)*ej;
    double m = 0.67*log10(ej)-0.87;
    return ConseguenzaCollisione(eMT,m);
}


Asteroide Asteroide::operator+(const Asteroide& a) const{
    Asteroide aux(*this);
    aux.fusione(a);
    aux.velocita = (velocita+a.velocita)/2;
    return aux;
}

QString Asteroide::paramDisegnoBase() const{
    return QString("Asteroide");
}

array<QString,2> Asteroide::paramDisegnoDim() const{
    QString r = QString::number(getRaggio());
    array<QString,2> aux = {paramDisegnoBase(),r};
    return aux;
}

array<QString,2> Asteroide::paramDisegnoEt() const{
    QString r = QString::number(getEta());
    array<QString,2> aux = {paramDisegnoBase(),r};
    return aux;
}

