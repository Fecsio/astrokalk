#include "asteroide.h"
#include <math.h>

Asteroide::Asteroide(double r, double ts, double dm, unsigned int e, double v):
    OggettoCeleste(r,ts,dm,e), velocita(v){
    if(v <= 0){
        throw EccInput("Velocità deve essere > 0");
    }
}

Asteroide::Asteroide(const OggettoCeleste& o, double v): OggettoCeleste(o), velocita(v) {
    if(v <= 0){
        throw EccInput("Velocità deve essere > 0");
    }
}

double Asteroide::getVel() const{
    return velocita;
}


ConseguenzaCollisione Asteroide::Collisione() const{
    double vC = velocita;

    if(vC< 11.2){
        vC = 11.2;
    }

    else if(vC >72.8){
        vC = 72.8;
    }

    long double ej = ((0.5)*Massa()*pow(10,12)*pow(vC,2));
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


