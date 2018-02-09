#include "orbitante.h"

Orbitante::Orbitante(long double d, double ts, double dm, unsigned int e, double vRot, double semiA):
    CorpoCeleste(d,ts,dm,e,vRot),semiAsseOrbita(semiA){
    if(semiA <= 0){
        throw EccInput("Semiasse deve essere > 0");
    }
}


void Orbitante::fusione(const OggettoCeleste& o){
    const Orbitante& aux = dynamic_cast<const Orbitante&>(o);
    this->CorpoCeleste::fusione(o);
    semiAsseOrbita = (semiAsseOrbita + aux.semiAsseOrbita)/2;
}

double Orbitante::getAsse() const{
    return semiAsseOrbita;
}
