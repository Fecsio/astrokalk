#ifndef DETTAGLI_H
#define DETTAGLI_H

#include "oggettoceleste.h"
#include "model.h"

//implementata per mantenere piu separazione tra logica e vista

class Dettagli
{
private:
    Model *model;
    double raggio;
    double temp;
    double dens;
    unsigned int eta;
    double velRot;
    double semiA;
    double az;
    double oss;
    double al;
    double vel;
    double mAss;
    double mApp;
    int pia;
    int sole;

public:
    Dettagli(Model *, const OggettoCeleste * const);

    double getRaggio() const;
    double getTemp() const;
    double getDens() const;
    unsigned int getEta() const;
    double getVelRot() const;
    double getSemiA() const;
    double getAz() const;
    double getOss() const;
    double getAl() const;
    double getVel() const;
    double getMAss() const;
    double getMApp() const;
    int getSole() const;
    int getPia() const;
};

#endif // DETTAGLI_H
