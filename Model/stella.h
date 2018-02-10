#ifndef STELLA_H
#define STELLA_H
#include "corpoceleste.h"

class Stella: public CorpoCeleste
{
private:
    double magnitudineAss; //cioè magnitudine a 10 parsec di distanza, da -20 a 10
    double magnitudineApp; // cioè magnitudine dalla terra, da -26.74(sole) a 10
public:
    Stella(double, double, double, unsigned int, double, double, double);
    Stella(const CorpoCeleste&, double, double);

    double getMAss() const;
    double getMApp() const;

    double distanzaTerra() const;
    virtual Stella operator+(const Stella&) const;

    QString paramDisegnoBase() const;

};

#endif // STELLA_H
