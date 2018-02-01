#include "stella.h"

Stella::Stella(long double d, int ts, double dm, unsigned int e, double vRot, double mAss, double mApp):
    CorpoCeleste(d, ts, dm, e, vRot){
    if(mAss < -20 || mAss >10 || mApp < -26.74 || mApp > 10)
        throw std::invalid_argument("Valori per le magnitudi invalidi; rispettivamente: -20 <= assoluta <= 10, -26.74 <= apparente <= 10");
     magnitudineAss= mAss;
     magnitudineApp = mApp;
}

Stella::Stella(const CorpoCeleste& c, double mAss, double mApp): CorpoCeleste(c){
    if(mAss < -20 || mAss >10 || mApp < -26.74 || mApp > 10)
        throw std::invalid_argument("Valori per le magnitudi invalidi; rispettivamente: -20 <= assoluta <= 10, -26.74 <= apparente <= 10");
     magnitudineAss= mAss;
     magnitudineApp = mApp;
}

double Stella::getMAss() const{
    return magnitudineAss;
}

double Stella::getMApp() const{
    return magnitudineApp;
}

double Stella::distanzaTerra() const{
    return pow(10, (magnitudineApp-magnitudineAss+5)/5)*206265; //*206265 -> parsec * 206265 = UA
}

Stella Stella::operator+ (const Stella& s) const{
    Stella aux(*this);
    aux.fusione(s);
    aux.magnitudineAss = (magnitudineAss+s.magnitudineAss)/2;
    aux.magnitudineApp = (magnitudineApp+s.magnitudineApp)/2;
    return aux;
}

QString Stella::paramDisegnoBase() const{
    return QString("Stella");
}

array<QString,2> Stella::paramDisegnoDim() const{ //potrei aggiungere età?
    QString r = QString::number(getRaggio());
    array<QString,2> aux = {paramDisegnoBase(), r};
    return aux;
}

array<QString, 2> Stella::paramDisegnoDist() const{
    QString d = QString::number(distanzaTerra());
    array<QString, 2> aux = {paramDisegnoBase(), d};
    return aux;
}

vector<array<QString,2>> Stella::disegnoDistanti(vector<const Stella*>& v){
    vector<array<QString,2>> aux;
    for(vector<const Stella*>::iterator it = v.begin(); it!= v.end(); ++it){
        aux.push_back((*it)->paramDisegnoDist());
    }
    return aux;
 }
