#include "stella.h"

Stella::Stella(long double d, double ts, double dm, unsigned int e, double vRot, double mAss, double mApp):
    CorpoCeleste(d, ts, dm, e, vRot), magnitudineAss(mAss), magnitudineApp(mApp){
    if(mAss < -20 || mAss >10 || mApp < -26.74 || mApp > 10){
            throw EccInput();
    }
}

Stella::Stella(const CorpoCeleste& c, double mAss, double mApp): CorpoCeleste(c),magnitudineAss(mAss), magnitudineApp(mApp){
    if(mAss < -20 || mAss >10 || mApp < -26.74 || mApp > 10)
        throw EccInput();
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

array<QString,2> Stella::paramDisegnoDim() const{
    QString r = QString::number(getRaggio());
    array<QString,2> aux = {paramDisegnoBase(), r};
    return aux;
}

array<QString, 2> Stella::paramDisegnoEt() const{
    QString e = QString::number(getEta());
    array<QString, 2> aux = {paramDisegnoBase(), e};
    return aux;
}

