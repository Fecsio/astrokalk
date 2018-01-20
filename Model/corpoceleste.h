#ifndef CORPOCELESTE_H
#define CORPOCELESTE_H
#include "oggettoceleste.h"
#include "dataoraterrestre.h"


class CorpoCeleste: public OggettoCeleste
{
private:
    double velRotazione; //in kh/h
public:
    CorpoCeleste(long double, int, double, unsigned long int, double);

    double getVRot() const;

    double AccelerazioneGravita() const;
    double CalcPeso(double) const;
    double VelFuga() const;
    DataOraTerrestre Giorno() const;

    void fusione(const OggettoCeleste&);

protected:
    static const double G;


};

#endif // CORPOCELESTE_H
