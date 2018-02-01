#include "model.h"

Model::Model(){}

void Model::newAsteroide(long double r, int ts, double dm, unsigned long int e, double v){
    Asteroide *aux = new Asteroide(r,ts,dm,e,v);
    astCreati.push_back(aux);
}

void Model::newStella(long double d, int ts, double dm, unsigned long int e, double vRot, double mAss, double mApp){
    Stella *aux = new Stella(d,ts,dm,e,vRot, mAss, mApp);
    steCreate.push_back(aux);
}

void Model::newPianeta(long double d, int ts, double dm, unsigned long int e, double vRot,double semiA, int ossigeno, int azoto, int argon, Stella& s){
    Pianeta *aux = new Pianeta(d,ts,dm,e,vRot,semiA,ossigeno,azoto,argon,s);
    piaCreati.push_back(aux);
}

void Model::newSatellite(long double d, int ts, double dm, unsigned long int e, double vRot,double semiA, Pianeta& p){
    Satellite *aux = new Satellite(d,ts,dm,e,vRot,semiA,p);
    satCreati.push_back(aux);
}

Asteroide* Model::getAsteroide(int index) const{
    return astCreati[index];
}

Stella* Model::getStella(int index) const{
    return steCreate[index];
}

Pianeta* Model::getPianeta(int index) const{
    return piaCreati[index];
}

Satellite* Model::getSatellite(int index) const{
    return satCreati[index];
}


int Model::getSizeCreati(int x) const{
   if(x == 0) return astCreati.size();
   if(x == 1) return steCreate.size();
   if(x == 2) return piaCreati.size();
   if(x == 3) return satCreati.size();
   return 0;
}

int Model::getSizeInsiemiCreati() const{
    int s = insiemiCreati.size();
    if(s<=0) s = 0;
    return s;
}

int Model::getPos(OggettoCeleste* o) const{
    bool trovato = false;
    int i = 0;

    if(dynamic_cast<Asteroide*>(o)){
        for(; i< astCreati.size() && !trovato ; ++i){
           if(astCreati[i] == o) trovato = true;
        }
    }

    if(dynamic_cast<Stella*>(o)){
        for(; i< steCreate.size() && !trovato ; ++i){
           if(steCreate[i] == o) trovato = true;
        }
    }

    if(dynamic_cast<Pianeta*>(o)){
        for(; i< piaCreati.size() && !trovato ; ++i){
           if(piaCreati[i] == o) trovato = true;
        }
    }

    if(dynamic_cast<Satellite*>(o)){
        for(; i< satCreati.size() && !trovato ; ++i){
           if(satCreati[i] == o) trovato = true;
        }
    }

    if(trovato) return i-1;
    else return -1;
}

