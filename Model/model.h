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

    const Asteroide* getAsteroide(int ) const;
    const Stella* getStella(int ) const;
    const Pianeta* getPianeta(int ) const;
    const Satellite* getSatellite(int ) const;
    const OggettoCeleste *getObj(int, int) const;

    int getPos(const OggettoCeleste*) const;

    void calcola(const OggettoCeleste*, const QString&, const QString& = "");
    void calcola(const OggettoCeleste*, const OggettoCeleste*, const QString&);

    QString getResult() const;

    vector<array<QString,2>> disegna(const QString&, const QString&);
private:
    vector<const Asteroide*> astCreati;
    vector<const Stella*> steCreate;
    vector<const Pianeta*> piaCreati;
    vector<const Satellite*> satCreati;
    QString result;

};

#endif // MODEL_H
