#ifndef ORBITANTE_H
#define ORBITANTE_H
#include "corpoceleste.h"

class Orbitante: public CorpoCeleste
{
private:
    double semiAsseOrbita; //in unita astronomiche (1 UA = 150.000.000 km)
public:
    Orbitante(long double, int, double, unsigned int, double, int);

    void fusione(const OggettoCeleste&);

    int getAsse() const;
    virtual double velOrbitale() const = 0;
    virtual double distanzaSole() const = 0;
    virtual DataOraTerrestre periodoOrbitale() const = 0;

};

#endif // ORBITANTE_H
