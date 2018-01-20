#ifndef SATELLITE_H
#define SATELLITE_H
#include "orbitante.h"
#include "pianeta.h"

class Satellite: public Orbitante
{
private:
    Pianeta& pianeta;
public:
    Satellite(long double, int, double, unsigned long int, double,int, Pianeta&);
    Satellite(const Orbitante&, Pianeta&);

    int rivoluzioniAnnue() const;
    bool rotazioneSincrona() const;

    virtual Satellite operator+(const Satellite&) const;

    DataOraTerrestre periodoOrbitale() const;
    double velOrbitale() const;
    double distanzaSole() const;
    QString paramDisegnoBase() const;
    array<QString,2> paramDisegnoDim() const;


};

#endif // SATELLITE_H
