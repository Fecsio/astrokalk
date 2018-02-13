#ifndef STELLA_H
#define STELLA_H
#include "corpoceleste.h"

class Stella: public CorpoCeleste
{
private:
    double magnitudineAss; //cioè magnitudine a 10 parsec di distanza, da -30 a 30
    double magnitudineApp; // cioè magnitudine dalla terra, da -38(sole) a 35
public:
    Stella(double, double, double, unsigned int, double, double, double);
    Stella(const CorpoCeleste&, double, double);

    double getMAss() const;
    double getMApp() const;

    double distanzaTerra() const;
    Stella operator+(const Stella&) const;


};

#endif // STELLA_H
