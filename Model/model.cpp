#include "model.h"
#include "eccinput.h"
#include <QRegularExpression>

Model::Model(){}

Model::~Model(){
    auto citA = astCreati.begin();
    auto citS = steCreate.begin();
    auto citP = piaCreati.begin();
    auto citSA = satCreati.begin();

    for(; citA!=astCreati.end(); ++citA){
        delete *citA;
    }

    for(; citS!=steCreate.end(); ++citS){
        delete *citS;
    }

    for(; citP!=piaCreati.end(); ++citP){
        delete *citP;
    }

    for(; citSA!=satCreati.end(); ++citSA){
        delete *citSA;
    }

}
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

const Asteroide* Model::getAsteroide(int index) const{
    return astCreati[index];
}

const Stella* Model::getStella(int index) const{
    return steCreate[index];
}

const Pianeta* Model::getPianeta(int index) const{
    return piaCreati[index];
}

const Satellite* Model::getSatellite(int index) const{
    return satCreati[index];
}

const OggettoCeleste* Model::getObj(int tipo, int index) const{
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

    return 0;
}

int Model::getSizeCreati(int x) const{
   if(x == 0) return astCreati.size();
   if(x == 1) return steCreate.size();
   if(x == 2) return piaCreati.size();
   if(x == 3) return satCreati.size();
   return 0;
}

int Model::getPos(const OggettoCeleste* o) const{
    bool trovato = false;
    unsigned int i = 0;

    if(dynamic_cast<const Asteroide*>(o)){
        for(; i< astCreati.size() && !trovato ; ++i){
           if(astCreati[i] == o) trovato = true;
        }
    }

    if(dynamic_cast<const Stella*>(o)){
        for(; i< steCreate.size() && !trovato ; ++i){
           if(steCreate[i] == o) trovato = true;
        }
    }

    if(dynamic_cast<const Pianeta*>(o)){
        for(; i< piaCreati.size() && !trovato ; ++i){
           if(piaCreati[i] == o) trovato = true;
        }
    }

    if(dynamic_cast<const Satellite*>(o)){
        for(; i< satCreati.size() && !trovato ; ++i){
           if(satCreati[i] == o) trovato = true;
        }
    }

    if(trovato) return i-1;
    else return -1;
}

void Model::calcola(const OggettoCeleste *obj, const QString& op, const QString & param){

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
        result = QString::number(static_cast<const CorpoCeleste*>(obj)->VelFuga()) + " km/s";
    }

    else if(op == "Peso Extraterrestre"){
        result = "Su questo corpo celeste peseresti " + QString::number(static_cast<const CorpoCeleste*>(obj)->CalcPeso(param.toDouble())) + " chili ";
    }

    else if(op == "Collisione"){
        ConseguenzaCollisione aux = static_cast<const Asteroide*>(obj)->Collisione();
        result = "La collisione rilascia " + QString::number(aux.getEn()) + " milioni di megaton di energia e provoca una magnitudo " + QString::number(aux.getMa());
    }

    else if(op == "Distanza dalla Terra"){
        result = QString::number(static_cast<const Stella*>(obj)->distanzaTerra()) + " AU";
    }

    else if(op == "Distanza dalla stella"){
        result = QString::number(static_cast<const Orbitante*>(obj)->distanzaSole()) + " AU";
    }

    else if(op == "Durata anno"){
        result = QString::number(static_cast<const Orbitante*>(obj)->periodoOrbitale().AnniFraz()) + " anni terrestri";
    }

    else if(op == "Abitabile?"){
        if(static_cast<const Pianeta*>(obj)->Abitabile()){
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

      DataTerrestre e = static_cast<const Pianeta*>(obj)->etaExtraTerrestre(g.toInt(), m.toInt(), a.toInt());
      result = "Su questo pianeta avresti: " + QString::number(e.AnniInteri()) + "anni terrestri";
    }

    else if(op == "Rotazione sincrona?"){
        bool x = static_cast<const Satellite*>(obj)->rotazioneSincrona();
        if(x){
            result = "Satellite e pianeta hanno rotazione sincrona";
        }

        else{
            result = "Satellite e pianeta non hanno rotazione sincrona";
        }
    }

    else if(op == "Rivoluzioni in un anno"){
        result = "Il satellite compie " + QString::number(static_cast<const Satellite*>(obj)->rivoluzioniAnnue()) + " in un anno del pianeta";
    }

    else if(op == "Durata giorno"){
        DataOraTerrestre aux = static_cast<const Orbitante*>(obj)->Giorno();
        result = "Un giorno dura " + QString::number(aux.AnniInteri()) + " anni, " + QString::number(aux.Giorni()) + " giorni, " + QString::number(aux.hour()) + " ore e " + QString::number(aux.minute()) + " minuti terrestri";
    }

    else if(op == "Vel. orbitale"){
        result = QString::number(static_cast<const Orbitante*>(obj)->velOrbitale());
    }

}

void Model::calcola(const OggettoCeleste *primo, const OggettoCeleste *secondo, const QString &op){
    if(op == "Somma"){
        const Asteroide *a = dynamic_cast<const Asteroide*>(primo);
        const Stella *s = dynamic_cast<const Stella*>(primo);
        const Pianeta *p = dynamic_cast<const Pianeta*>(primo);
        const Satellite *sat = dynamic_cast<const Satellite*>(primo);

        if(a){
            const Asteroide *aux = new Asteroide(*a+*static_cast<const Asteroide*>(secondo));
            astCreati.push_back(aux);
        }

        else if(s){
            const Stella *aux = new Stella(*s+*static_cast<const Stella*>(secondo));
            steCreate.push_back(aux);
        }

        else if(p){
            const Pianeta *aux = new Pianeta(*p+*static_cast<const Pianeta*>(secondo));
            piaCreati.push_back(aux);
        }

        else if(sat){
            const Satellite *aux = new Satellite(*sat+*static_cast<const Satellite*>(secondo));
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

vector<array<QString,2>> Model::disegna(const QString& tipo, const QString& elem){
    QStringList ql = elem.split(QRegExp("[, | .]"));
    vector<const OggettoCeleste*> aux;

    for(int i=0; i<ql.size()-1; ++i){
        QString s = ql.at(i);
        QStringList qls = s.split(QRegExp("[-]"));
        QString t = qls.at(0);
        QString p = qls.at(1);
        unsigned int pos = p.toInt();
        bool ok = true;

        if(t == "A"){
            if(pos >= astCreati.size()) {
                ok = false;
            }
            else{
                aux.push_back(astCreati[pos]);
            }
        }

        else if(t == "S" && ok){
            if(pos >= steCreate.size()) {
                ok = false;
            }
            aux.push_back(steCreate[pos]);
        }

        else if(t == "P" && ok){
            if(pos >= piaCreati.size()) {
                ok = false;
            }
            aux.push_back(piaCreati[pos]);
        }

        else if(t == "SA" && ok){
            if(pos >= satCreati.size()) {
                ok = false;
            }
            aux.push_back(satCreati[pos]);
        }

        if(!ok) throw EccInput();
    }

    vector<array<QString,2>> ret;

    if(tipo == "Disegna in scala"){
        ret = OggettoCeleste::disegnoInScala(aux);
    }

    else{
       ret = OggettoCeleste::disegnoInScalaEta(aux);
    }

    auto it = aux.begin();
    QString tipoOgg;
    result.clear();
    result = "Indici in ordine: ";
    for(; it!=aux.end(); ++it){
        result = result + " " + QString::number(getPos(*it));
    }

    return ret;

}

