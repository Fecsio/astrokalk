#include "oggettoceleste.h"
#include <algorithm>
#include <math.h>
#include <typeinfo>

const double OggettoCeleste::pi= 3.141592653589793;

OggettoCeleste::OggettoCeleste(long double r, double ts, double dm, unsigned int e): raggio(r),
    temperaturaSuperficiale(ts), densitaMedia(dm), eta(e){}

OggettoCeleste::~OggettoCeleste(){}

double OggettoCeleste::getRaggio() const{
    return raggio;
}

double OggettoCeleste::getTemp() const{
    return temperaturaSuperficiale;
}

double OggettoCeleste::getDens() const{
    return densitaMedia;
}

unsigned long OggettoCeleste::getEta() const{
    return eta;
}


vector<const OggettoCeleste*> OggettoCeleste::ordinaPer(vector<const OggettoCeleste*>& v, char condizione){

    std::sort(v.begin(), v.end(),
              [condizione](const OggettoCeleste* primo,const OggettoCeleste* secondo){

                if(condizione == 'v') return *primo < *secondo;
                else return primo->eta < secondo->eta;
                //else throw exception
            }
    );

    return v;
}

vector<array<QString,2>> OggettoCeleste::disegnoInScala(vector<const OggettoCeleste *>& vec){
    vector<array<QString,2>> aux;
    vec=ordinaPer(vec,'v');
    for(vector<const OggettoCeleste*>::iterator it = vec.begin(); it!=vec.end(); ++it){
        aux.push_back((*it)->paramDisegnoDim());
    }
    return aux;
}


double OggettoCeleste::Volume()const{
    return (pi/6)*pow(raggio*2, 3);
}

double OggettoCeleste::rapportaVolume(const OggettoCeleste& ogg) const{
    return (*this).Volume()/ogg.Volume();
}

double OggettoCeleste::Massa() const{
    return densitaMedia*Volume();
}

double OggettoCeleste::Superficie() const{
    return 4*pi*pow(raggio,2);
}

void OggettoCeleste::fusione(const OggettoCeleste& ogg){
    raggio+=ogg.raggio;
    densitaMedia=(densitaMedia+ogg.densitaMedia)/2;
    temperaturaSuperficiale=(temperaturaSuperficiale+ogg.temperaturaSuperficiale)/2;
    eta=0;
}

bool OggettoCeleste::operator>(const OggettoCeleste& ogg) const{
    return raggio > ogg.raggio;
}

bool OggettoCeleste::operator<(const OggettoCeleste& ogg) const{
    return raggio < ogg.raggio;
}






