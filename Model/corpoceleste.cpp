#include "corpoceleste.h"
#include <math.h>
#include <typeinfo>

const double CorpoCeleste::G=6.67191e-11;

CorpoCeleste::CorpoCeleste(long double d, double ts, double dm, unsigned int e, double vRot):
    OggettoCeleste(d,ts,dm,e), velRotazione(vRot){
    if(vRot <= 0){
        throw EccInput("Velocità di rotazione deve essere > 0");
    }
}


double CorpoCeleste::getVRot() const{
    return velRotazione;
}


double CorpoCeleste::AccelerazioneGravita() const{
    return G*Massa()/pow(getRaggio(), 2);
}

double CorpoCeleste::CalcPeso(double peso) const{
     double aux = peso/9.80665;
     return aux*AccelerazioneGravita()*pow(10,6);
}

double CorpoCeleste::VelFuga() const{
    return sqrt((2*G*Massa()*pow(10,9))/getRaggio())*pow(10,-3);
}

DataOraTerrestre CorpoCeleste::Giorno() const{
    return DataOraTerrestre(((getRaggio()*2*pi)/velRotazione)*3600); //*3600 perchè diametro/velrot mi dà le ore
}

void CorpoCeleste::fusione(const OggettoCeleste& o){
    const CorpoCeleste& aux = dynamic_cast<const CorpoCeleste&>(o); //potevo mettere static_cast perchè con i miei metodi ho la certezza che i tipi siano giusti, ma per il futuro ho tenuto dynamic. Cioè se in futuro fusione potrà venire chiamata con tipi diversi (es: stella d'invocazione e asteroide passato come argomento), l'esecuzione porterebbe a un std::bad_cast
    this->OggettoCeleste::fusione(o);
    velRotazione = (velRotazione+aux.velRotazione)/2;
}







