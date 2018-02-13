#ifndef SATELLITE_H
#define SATELLITE_H
#include "orbitante.h"
#include "pianeta.h"

class Satellite: public Orbitante
{
private:
    const Pianeta& pianeta;
public:
    Satellite(double, double, double, unsigned int, double, double, const Pianeta&);
    Satellite(const Orbitante&, const Pianeta&);

    const Pianeta& getPianeta() const;

    int rivoluzioniAnnue() const;
    bool rotazioneSincrona() const;

    Satellite operator+(const Satellite&) const;

    DataOraTerrestre periodoOrbitale() const;
    double velOrbitale() const;
    double distanzaSole() const;

};

#endif // SATELLITE_H
