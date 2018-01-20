#include "pianeta.h"

Pianeta::Pianeta(long double d, int ts, double dm, unsigned long int e, double vRot,int semiA, int ossigeno, int azoto, int argon, Stella& s):
    Orbitante(d,ts,dm,e,vRot,semiA), atmosfera(Atmosfera(ossigeno,azoto,argon)), sole(s){}

Pianeta::Pianeta(const Orbitante& c, const Atmosfera& a, Stella& s):
    Orbitante(c), atmosfera(a), sole(s){}


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
           && atmosfera.getAr() >= 0.5 && atmosfera.getAr() <= 1.5
           && atmosfera.getO() >= 18 && atmosfera.getO() <= 30;
}

DataOraTerrestre Pianeta::periodoOrbitale() const{
    long double num = 4*pow(pi,2)*pow(getAsse(),3);
    long double den = G*(Massa()+sole.Massa());
    long double result = sqrt(num/den)*3.168753579e-08*365;
    return DataOraTerrestre(ceil(result));
}

DataTerrestre Pianeta::etaExtraTerrestre(int g, int m, int a) const{
    QDate oggi = QDate::currentDate();
    QDate compleanno(a,m,g);
    unsigned int etaG = compleanno.daysTo(oggi);
    return DataTerrestre((etaG/365)/(periodoOrbitale().AnniFraz()));

}

double Pianeta::velOrbitale() const{
    return sqrt((G*sole.Massa())/(sole.getRaggio()+getAsse()));
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

QString Pianeta::paramDisegnoBase() const{
    return QString("Pianeta");
}

array<QString,2> Pianeta::paramDisegnoDim() const{
    QString r = QString::number(getRaggio());
    array<QString,2> aux = {paramDisegnoBase(), r};
    return aux;
}
