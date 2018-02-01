#include "dettagli.h"

Dettagli::Dettagli(Model* m, const OggettoCeleste * const c) : model(m), raggio (c->getRaggio()),
    temp(c->getTemp()), dens (c->getDens()), eta(c->getEta()){

    const Asteroide *a = dynamic_cast<const Asteroide* const>(c);
    const Stella *s = dynamic_cast<const Stella* const>(c);
    const Pianeta *p = dynamic_cast<const Pianeta* const>(c);
    const Satellite *sat = dynamic_cast<const Satellite* const>(c);

    if(a){
        vel = a->getVel();
    }

    if(s){
        velRot = s->getVRot();
        mAss = s->getMAss();
        mApp = s->getMApp();
    }

    if(p){
        velRot = p->getVRot();
        semiA = p->getAsse();
        az = p->getAtm().getAz();
        oss = p->getAtm().getO();
        ar = p->getAtm().getAr();
        sole = model->getPos(&(p->getStella()));
    }

    if(sat){
        velRot = sat->getVRot();
        pia = model->getPos(&(sat->getPianeta()));
    }

}

double Dettagli::getRaggio() const{
    return raggio;
}

int Dettagli::getTemp() const{
    return temp;
}

double Dettagli::getDens() const{
    return dens;
}

unsigned long int Dettagli::getEta() const{
    return eta;
}

double Dettagli::getVelRot() const{
    return velRot;
}

double Dettagli::getSemiA() const{
    return semiA;
}

double Dettagli::getAz() const{
    return az;
}

double Dettagli::getOss() const{
    return oss;
}

double Dettagli::getAr() const{
    return ar;
}

double Dettagli::getVel() const{
    return vel;
}

double Dettagli::getMAss() const{
    return mAss;
}

double Dettagli::getMApp() const{
    return mApp;
}

int Dettagli::getSole() const{
    return sole;
}

int Dettagli::getPia() const{
    return pia;
}
