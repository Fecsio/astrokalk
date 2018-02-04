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

OggettoCeleste* Model::getObj(int tipo, int index) const{
    switch (tipo) {
    case 1:
        return getAsteroide(index);
        break;
    case 2:
        return getStella(index);
        break;
    case 3:
        return getPianeta(index);
        break;
    case 4:
        return getSatellite(index);
        break;
    }
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

void Model::calcola(OggettoCeleste *obj, const QString& op, const QString & paramgvfikkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk   ){
    if(op == "Volume"){
        result = QString::number(obj->Volume());
    }

    if(op == "Superficie"){
        result = QString::number(obj->Superficie());
    }

    if(op == "Massa"){
        result = QString::number(obj->Massa());
    }

    if(op == "VelFuga"){
        result = QString::number(static_cast<CorpoCeleste*>(obj)->VelFuga());
    }

    if(op == "Peso"){
        result = QString::number(static_cast<CorpoCeleste*>(obj)->CalcPeso(param.toDouble()));
    }

    if(op == "Collisione"){
        ConseguenzaCollisione aux = static_cast<Asteroide*>(obj)->Collisione();
        result = "La collisione rilascia " + QString::number(aux.getEn()) + "megaton di energia e provoca una magnitudo " + QString::number(aux.getMa());
    }

    if(op == "DistTerra"){
        result = QString::number(static_cast<Stella*>(obj)->distanzaTerra());
    }

    if(op == "DistSole"){
        result = QString::number(static_cast<Orbitante*>(obj)->distanzaSole());
    }

    if(op == "Anno"){
        result = QString::number(static_cast<Orbitante*>(obj)->periodoOrbitale().AnniFraz());
    }

    if(op == "Abitabile"){
        if(static_cast<Pianeta*>(obj)->Abitabile()){
            result = "Il pianeta potrebbe essere abitabile";
        }

        else{
            result = "Il pianeta non è abitabile";
        }
    }

    if(op == "Eta"){
      //  result = static_cast<Pianeta*>(obj)->etaExtraTerrestre()
    }
}

QString Model::getResult() const{
    return result;
}
