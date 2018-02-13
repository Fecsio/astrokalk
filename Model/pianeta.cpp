#include "pianeta.h"

Pianeta::Pianeta(double r, double ts, double dm, unsigned int e, double vRot, double semiA, double ossigeno, double azoto, double altro, const Stella& s):
    Orbitante(r,ts,dm,e,vRot,semiA), atmosfera(Atmosfera(ossigeno,azoto,altro)), sole(s){}

Pianeta::Pianeta(const Orbitante& c, const Atmosfera& a, const Stella& s):
    Orbitante(c), atmosfera(a), sole(s){}

Atmosfera Pianeta::getAtm() const{
    return atmosfera;
}

const Stella &Pianeta::getStella() const{
    return sole;
}

double Pianeta::ESI() const{
    double r = pow(1 - abs((getRaggio()- 6371)/(getRaggio()+6371)),0.57/3); //6371 = raggio terrestre
    double d = pow(1 - abs((getDens()-5.51)/(getDens()+5.51)), 1.07/3); //5.51 = densita terra
    double vf = pow(1 - abs((VelFuga()-11.2)/(VelFuga()+11.2)), 0.7/3); // 11.2 = velocita fuga terra in km/s
    return r*d*vf;
}

bool Pianeta::Abitabile() const{
    return ESI()>=0.8
           && getTemp() >= -80 && getTemp() <= 100
           && atmosfera.getAz() >=70 && atmosfera.getAz() <=85   //valori riferiti alla composizione atmosferica terrestre, calcolo inventato
           && atmosfera.getAl() >= 0.5 && atmosfera.getAl() <= 1.5
           && atmosfera.getO() >= 18 && atmosfera.getO() <= 30;
}

DataOraTerrestre Pianeta::periodoOrbitale() const{
    long double num = 4*pow(pi,2)*pow(getAsse()/6.684587123e-12,3);
    long double den = G*(Massa()*pow(10,12)+sole.Massa()*pow(10,12));
    long double result = sqrt(num/den)*(3.168753579e-08)*365;
    return DataOraTerrestre(result*86400);
}

DataTerrestre Pianeta::etaExtraTerrestre(int g, int m, int a) const{
    QDate oggi = QDate::currentDate();
    QDate compleanno(a,m,g);
    double etaG = compleanno.daysTo(oggi);
    return DataTerrestre((((double)etaG) / (periodoOrbitale().AnniFraz())));
}

double Pianeta::velOrbitale() const{
    return sqrt((G*sole.Massa())/(sole.getRaggio()*pow(10,3)+getAsse()*1.5e+11))*pow(10,3);
}

double Pianeta::distanzaSole() const{
    return getAsse();
}

Pianeta Pianeta::operator+ (const Pianeta& p) const{
    Pianeta aux(*this);
    aux.fusione(p);
    aux.atmosfera = atmosfera+p.atmosfera;
    return aux;
}

