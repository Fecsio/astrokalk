#ifndef ORBITANTE_H
#define ORBITANTE_H
#include "corpoceleste.h"

class Orbitante: public CorpoCeleste
{
private:
    double semiAsseOrbita; //in unita astronomiche (1 UA = 150.000.000 km)
public:
    Orbitante(double, double, double, unsigned int, double, double);

    void fusione(const OggettoCeleste&);

    double getAsse() const;
    virtual double velOrbitale() const = 0;
    virtual double distanzaSole() const = 0;
    virtual DataOraTerrestre periodoOrbitale() const = 0;
};

#endif // ORBITANTE_H
