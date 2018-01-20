#include "satellite.h"

Satellite::Satellite(long double d, int ts, double dm, unsigned long int e, double vRot,int semiA, Pianeta& p):
    Orbitante(d,ts,dm,e,vRot, semiA), pianeta(p){}

Satellite::Satellite(const Orbitante& o, Pianeta& p): Orbitante(o), pianeta(p) {}


int Satellite::rivoluzioniAnnue() const{
    return periodoOrbitale().AnniFraz()/pianeta.periodoOrbitale().AnniFraz();
}

DataOraTerrestre Satellite::periodoOrbitale() const{
    long double num = 4*pow(pi,2)*pow(getAsse(),3);
    long double den = G*(Massa()+pianeta.Massa());
    long double result = sqrt(num/den)*3.168753579e-08*365;
    return DataOraTerrestre(ceil(result));
}


bool Satellite::rotazioneSincrona() const{ //dato che l'approssimazione puo non essere perfetta, confronto solo le ore
    return Giorno().hour() == periodoOrbitale().hour();
}

double Satellite::velOrbitale() const{
    return sqrt((G*pianeta.Massa())/(pianeta.getRaggio()+getAsse()));
}

double Satellite::distanzaSole() const{
    return pianeta.distanzaSole()+getAsse();
}


Satellite Satellite::operator+(const Satellite& o) const{
    Satellite aux(*this);
    aux.fusione(o);
    return aux;
}

QString Satellite::paramDisegnoBase() const{
    return QString("Satellite");
}

array<QString,2> Satellite::paramDisegnoDim() const{
    QString r = QString::number(getRaggio());
    array<QString,2> aux = {paramDisegnoBase(), r};
    return aux;
}
