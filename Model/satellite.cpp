#include "satellite.h"

Satellite::Satellite(double r, double ts, double dm, unsigned int e, double vRot, double semiA, const Pianeta &p):
    Orbitante(r,ts,dm,e,vRot, semiA), pianeta(p){}

Satellite::Satellite(const Orbitante& o, const Pianeta& p): Orbitante(o), pianeta(p) {}

const Pianeta &Satellite::getPianeta() const{
    return pianeta;
}

int Satellite::rivoluzioniAnnue() const{
    return (pianeta.periodoOrbitale().AnniFraz()*8760+pianeta.periodoOrbitale().hour())/(periodoOrbitale().AnniFraz()*8760 + periodoOrbitale().hour());
}

DataOraTerrestre Satellite::periodoOrbitale() const{
    long double num = 4*pow(pi,2)*pow(getAsse()/6.684587123e-12,3);
    long double den = G*(Massa()*pow(10,12)+pianeta.Massa()*pow(10,12));
    long double result = sqrt(num/den)*(3.168753579e-08)*365;
    return DataOraTerrestre(result*86400);
}


bool Satellite::rotazioneSincrona() const{ //dato che l'approssimazione puo non essere perfetta, confronto solo le ore
    return Giorno().hour() + Giorno().Giorni()*24 <= (periodoOrbitale().hour() + periodoOrbitale().Giorni()*24 + 0.1*(periodoOrbitale().Giorni()*24 + periodoOrbitale().hour())) &&
            Giorno().hour() + Giorno().Giorni()*24 >= (periodoOrbitale().hour() + periodoOrbitale().Giorni()*24 - 0.1*(periodoOrbitale().Giorni()*24 + periodoOrbitale().hour())) ;
}

double Satellite::velOrbitale() const{
    return sqrt((G*pianeta.Massa())/(pianeta.getRaggio()*pow(10,3)+getAsse()*1.5e+11))*pow(10,3);
}

double Satellite::distanzaSole() const{
    return pianeta.distanzaSole()+getAsse();
}


Satellite Satellite::operator+(const Satellite& o) const{
    Satellite aux(*this);
    aux.fusione(o);
    return aux;
}
