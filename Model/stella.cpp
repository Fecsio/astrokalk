#include "stella.h"

Stella::Stella(double r, double ts, double dm, unsigned int e, double vRot, double mAss, double mApp):
    CorpoCeleste(r, ts, dm, e, vRot), magnitudineAss(mAss), magnitudineApp(mApp){
    if(mAss < -30 || mAss >30 || mApp < -38 || mApp > 35){
            throw EccInput("Valori per le magnitudi invalidi; rispettivamente: -30 <= assoluta <= 30, -38 <= apparente <= 35");
    }
}

Stella::Stella(const CorpoCeleste& c, double mAss, double mApp): CorpoCeleste(c),magnitudineAss(mAss), magnitudineApp(mApp){
    if(mAss < -30 || mAss >30 || mApp < -38 || mApp > 35)
        throw EccInput("Valori per le magnitudi invalidi; rispettivamente: -30 <= assoluta <= 30, -38 <= apparente <= 35");
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
