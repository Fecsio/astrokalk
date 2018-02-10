#ifndef OGGETTOCELESTE_H
#define OGGETTOCELESTE_H
#include <iostream>
#include <vector>
#include <array>
#include <QString>
#include "eccinput.h"
using std::vector;
using std::array;

class OggettoCeleste
{
private:
    double raggio;
    double temperaturaSuperficiale;
    double densitaMedia;
    unsigned int eta;
public:

    OggettoCeleste(double, double, double, unsigned int);
    virtual ~OggettoCeleste() = default;

    double getRaggio() const;
    double getTemp() const;
    double getDens() const;
    unsigned int getEta() const;

    static vector<const OggettoCeleste *> ordinaPer(vector<const OggettoCeleste *>&, char );
    static vector<array<QString,2>> disegnoInScala(vector<const OggettoCeleste *>&);
    static vector<array<QString,2>> disegnoInScalaEta(vector<const OggettoCeleste *>&);

    double Volume() const;
    double Massa() const;
    double Superficie() const;

    double rapportaVolume(const OggettoCeleste&) const;

    virtual QString paramDisegnoBase() const = 0;
    array<QString, 2> paramDisegnoDim() const;
    array<QString, 2> paramDisegnoEt() const;

    virtual void fusione(const OggettoCeleste&); //funziona con oggetti >= nella gerarchia

    bool operator>(const OggettoCeleste&) const; //confronto dimensioni
    bool operator<(const OggettoCeleste&) const; //confronto dimensioni

protected:
    static const double pi;
};



//std::ostream& operator<<(std::ostream&, const OggettoCeleste&);

#endif // OGGETTOCELESTE_H
