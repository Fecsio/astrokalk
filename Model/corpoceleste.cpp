#include "corpoceleste.h"
#include <math.h>
#include <typeinfo>

const double CorpoCeleste::G=6.67191e-11;

CorpoCeleste::CorpoCeleste(long double d, int ts, double dm, unsigned long int e, double vRot):
    OggettoCeleste(d,ts,dm,e), velRotazione(vRot){}


double CorpoCeleste::getVRot() const{
    return velRotazione;
}


double CorpoCeleste::AccelerazioneGravita() const{
    return G*Massa()/pow(getRaggio(), 2);
}

double CorpoCeleste::CalcPeso(double peso) const{
     double aux = peso/9.80665;
     return aux*AccelerazioneGravita();
}

double CorpoCeleste::VelFuga() const{
    return sqrt((2*G*Massa())/getRaggio());
}

DataOraTerrestre CorpoCeleste::Giorno() const{
    return DataOraTerrestre(((getRaggio()*2)/velRotazione)*3600); //*3600 perchè diametro/velrot mi dà le ore
}

void CorpoCeleste::fusione(const OggettoCeleste& o){
    const CorpoCeleste& aux = dynamic_cast<const CorpoCeleste&>(o); //potevo mettere static_cast perchè con i miei metodi ho la certezza che i tipi siano giusti, ma per il futuro ho tenuto dynamic. Cioè se in futuro fusione potrà venire chiamata con tipi diversi (es: stella d'invocazione e asteroide passato come argomento), l'esecuzione porterebbe a un std::bad_cast
    this->OggettoCeleste::fusione(o);
    velRotazione = (velRotazione+aux.velRotazione)/2;
}

    /*

    if(this->OggettoCeleste::operator==(o)){
        const CorpoCeleste& aux = dynamic_cast<const CorpoCeleste&>(o);
        return velRotazione == aux.velRotazione;
    }
    return false;*/






