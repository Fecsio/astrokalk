#ifndef PIANETA_H
#define PIANETA_H
#include "orbitante.h"
#include "stella.h"
#include "atmosfera.h"

class Pianeta: public Orbitante
{
private:
    Atmosfera atmosfera;
    Stella& sole;
public:
    Pianeta(long double, double, double, unsigned int, double, double, int , int , int , Stella&);
    Pianeta(const Orbitante&, const Atmosfera&, Stella&);

    Atmosfera getAtm() const;
    Stella& getStella() const;

    double ESI() const;
    bool Abitabile() const;

    void disegnaConOrb() const;
    DataTerrestre etaExtraTerrestre(int , int, int) const;

    DataOraTerrestre periodoOrbitale() const;
    double velOrbitale() const;
    double distanzaSole() const;

    virtual Pianeta operator+(const Pianeta&) const;
    QString paramDisegnoBase() const;
    array<QString,2> paramDisegnoDim() const;
};

#endif // PIANETA_H
