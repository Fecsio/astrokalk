#include "model.h"

Model::Model(){}

void Model::newAsteroide(double r, double ts, double dm, unsigned long int e, double v){
    Asteroide *aux = new Asteroide(r,ts,dm,e,v);
    astCreati.push_back(aux);
}

void Model::newStella(double d, double ts, double dm, unsigned long int e, double vRot, double mAss, double mApp){
    Stella *aux = new Stella(d,ts,dm,e,vRot, mAss, mApp);
    steCreate.push_back(aux);
}

void Model::newPianeta(double d, double ts, double dm, unsigned long int e, double vRot,double semiA, int ossigeno, int azoto, int argon, Stella& s){
    Pianeta *aux = new Pianeta(d,ts,dm,e,vRot,semiA,ossigeno,azoto,argon,s);
    piaCreati.push_back(aux);
}

void Model::newSatellite(double d, double ts, double dm, unsigned long int e, double vRot, double semiA, Pianeta& p){
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

void Model::calcola(OggettoCeleste *obj, const QString& op, const QString & param){

    if(op == "Volume"){
        result = QString::number(obj->Volume()) + " miliardi di m^3";
    }

    else if(op == "Superficie"){
        result = QString::number(obj->Superficie()) + " chilometri quadrati";
    }

    else if(op == "Massa"){
        result = QString::number(obj->Massa()) + " miliardi di tonnellate";
    }

    else if(op == "Vel. di fuga"){
        result = QString::number(static_cast<CorpoCeleste*>(obj)->VelFuga()) + " km/s";
    }

    else if(op == "Peso Extraterrestre"){
        result = "Su questo corpo celeste peseresti " + QString::number(static_cast<CorpoCeleste*>(obj)->CalcPeso(param.toDouble())) + " chili ";
    }

    else if(op == "Collisione"){
        ConseguenzaCollisione aux = static_cast<Asteroide*>(obj)->Collisione();
        result = "La collisione rilascia " + QString::number(aux.getEn()) + " milioni di megaton di energia e provoca una magnitudo " + QString::number(aux.getMa());
    }

    else if(op == "Distanza dalla Terra"){
        result = QString::number(static_cast<Stella*>(obj)->distanzaTerra()) + " AU";
    }

    else if(op == "Distanza dalla stella"){
        result = QString::number(static_cast<Orbitante*>(obj)->distanzaSole()) + " AU";
    }

    else if(op == "Durata anno"){
        result = QString::number(static_cast<Orbitante*>(obj)->periodoOrbitale().AnniFraz()) + " anni terrestri";
    }

    else if(op == "Abitabile?"){
        if(static_cast<Pianeta*>(obj)->Abitabile()){
            result = "Il pianeta potrebbe essere abitabile";
        }

        else{
            result = "Il pianeta non è abitabile";
        }
    }

    else if(op == "Eta extraterrestre"){
      QStringList ql = param.split(QRegExp("[/]"));
      QString g = ql.at(0);
      QString m = ql.at(1);
      QString a = ql.at(2);

      DataTerrestre e = static_cast<Pianeta*>(obj)->etaExtraTerrestre(g.toInt(), m.toInt(), a.toInt());
      result = "Su questo pianeta avresti: " + QString::number(e.AnniInteri()) + "anni terrestri";
    }

    else if(op == "Rotazione sincrona?"){
        bool x = static_cast<Satellite*>(obj)->rotazioneSincrona();
        if(x){
            result = "Satellite e pianeta hanno rotazione sincrona";
        }

        else{
            result = "Satellite e pianeta non hanno rotazione sincrona";
        }
    }

    else if(op == "Rivoluzioni in un anno"){
        result = "Il satellite compie " + QString::number(static_cast<Satellite*>(obj)->rivoluzioniAnnue()) + " in un anno del pianeta";
    }

    else if(op == "Durata giorno"){
        DataOraTerrestre aux = static_cast<Orbitante*>(obj)->Giorno();
        result = "Un giorno dura " + QString::number(aux.AnniInteri()) + " anni, " + QString::number(aux.Giorni()) + " giorni, " + QString::number(aux.hour()) + " ore e " + QString::number(aux.minute()) + " minuti terrestri";
    }

    else if(op == "Vel. orbitale"){
        result = QString::number(static_cast<Orbitante*>(obj)->velOrbitale());
    }

}

void Model::calcola(OggettoCeleste *primo, OggettoCeleste *secondo, const QString &op){
    if(op == "Somma"){
        Asteroide *a = dynamic_cast<Asteroide*>(primo);
        Stella *s = dynamic_cast<Stella*>(primo);
        Pianeta *p = dynamic_cast<Pianeta*>(primo);
        Satellite *sat = dynamic_cast<Satellite*>(primo);

        if(a){
            Asteroide *aux = new Asteroide(*a+*static_cast<Asteroide*>(secondo));
            astCreati.push_back(aux);
        }

        else if(s){
            Stella *aux = new Stella(*s+*static_cast<Stella*>(secondo));
            steCreate.push_back(aux);
        }

        else if(p){
            Pianeta *aux = new Pianeta(*p+*static_cast<Pianeta*>(secondo));
            piaCreati.push_back(aux);
        }

        else if(sat){
            Satellite *aux = new Satellite(*sat+*static_cast<Satellite*>(secondo));
            satCreati.push_back(aux);
        }

        result = "Nuovo oggetto creato, vedi lista";
    }

    else if(op == "Rapporto volume"){
        result = "Il primo operando è " + QString::number(primo->rapportaVolume(*secondo)) + " volte il secondo";
    }
}


QString Model::getResult() const{
    return result;
}
