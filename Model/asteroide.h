#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include "oggettoceleste.h"
#include "conseguenzacollisione.h"

class Asteroide: public OggettoCeleste
{
private:
    double velocita; //km/s
public:
    Asteroide(long double, int, double , unsigned long int, double);
    Asteroide(const OggettoCeleste&, double);

    Asteroide operator+(const Asteroide&) const;
    QString paramDisegnoBase() const;
    array<QString,2> paramDisegnoDim() const;
    ConseguenzaCollisione Collisione() const;
};

#endif // ASTEROIDE_H
