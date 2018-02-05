#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "oggettoceleste.h"
#include "conseguenzacollisione.h"

class Asteroide: public OggettoCeleste
{
private:
    double velocita; //km/s
public:
    Asteroide(long double, double, double , unsigned int, double);
    Asteroide(const OggettoCeleste&, double);

    double getVel() const;

    Asteroide operator+(const Asteroide&) const;
    QString paramDisegnoBase() const;
    array<QString,2> paramDisegnoDim() const;
    ConseguenzaCollisione Collisione() const;
};

#endif // ASTEROIDE_H
