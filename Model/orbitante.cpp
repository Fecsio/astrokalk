#include "orbitante.h"

Orbitante::Orbitante(long double d, int ts, double dm, unsigned int e, double vRot, int semiA):
    CorpoCeleste(d,ts,dm,e,vRot),semiAsseOrbita(semiA){}


void Orbitante::fusione(const OggettoCeleste& o){
    const Orbitante& aux = dynamic_cast<const Orbitante&>(o);
    this->CorpoCeleste::fusione(o);
    semiAsseOrbita = (semiAsseOrbita + aux.semiAsseOrbita)/2;
}

int Orbitante::getAsse() const{
    return semiAsseOrbita;
}

/*
 * Da copiare in ogni sottoclasse
 *
 *
 * DataOraTerrestre Orbitante::periodoOrbitale() const{
    long double num = 4*pow(pi,2)*pow(semiAsseOrbita,3);
    long double den = G*(Massa()+Sole->Massa());
}
*/
