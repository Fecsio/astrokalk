#ifndef MODEL_H
#define MODEL_H

#include "asteroide.h"
#include "stella.h"
#include "pianeta.h"
#include "satellite.h"

class Model
{
public:
    Model();
    void newAsteroide(double, double, double , unsigned long int, double);
    void newStella(double, double, double, unsigned long int, double, double, double);
    void newPianeta(double, double, double, unsigned long int, double,double, int ,int ,int , Stella&);
    void newSatellite(double, double, double, unsigned long int, double,double, Pianeta&);

    int getSizeCreati(int ) const;
    int getSizeInsiemiCreati() const;

    Asteroide* getAsteroide(int ) const;
    Stella* getStella(int ) const;
    Pianeta* getPianeta(int ) const;
    Satellite* getSatellite(int ) const;
    OggettoCeleste* getObj(int, int) const;

    int getPos(OggettoCeleste*) const;

    void calcola(OggettoCeleste*, const QString&, const QString& = "");
    void calcola(OggettoCeleste*, OggettoCeleste*, const QString&);

    QString getResult() const;
private:
    vector<Asteroide*> astCreati;
    vector<Stella*> steCreate;
    vector<Pianeta*> piaCreati;
    vector<Satellite*> satCreati;
    vector<vector<OggettoCeleste*>> insiemiCreati;
    QString result;

};

#endif // MODEL_H
