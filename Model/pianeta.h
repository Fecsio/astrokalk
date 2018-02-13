#ifndef PIANETA_H
#define PIANETA_H
#include "orbitante.h"
#include "stella.h"
#include "atmosfera.h"

class Pianeta: public Orbitante
{
private:
    Atmosfera atmosfera;
    const Stella& sole;
public:
    Pianeta(double, double, double, unsigned int, double, double, double , double , double , const Stella &);
    Pianeta(const Orbitante&, const Atmosfera&, const Stella&);

    Atmosfera getAtm() const;
    const Stella& getStella() const;

    double ESI() const;
    bool Abitabile() const;

    DataTerrestre etaExtraTerrestre(int , int, int) const;

    DataOraTerrestre periodoOrbitale() const;
    double velOrbitale() const;
    double distanzaSole() const;

    Pianeta operator+(const Pianeta&) const;
};

#endif // PIANETA_H
