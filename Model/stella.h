#ifndef STELLA_H
#define STELLA_H
#include "corpoceleste.h"

class Stella: public CorpoCeleste
{
private:
    double magnitudineAss; //cioè magnitudine a 10 parsec di distanza, da -20 a 10
    double magnitudineApp; // cioè magnitudine dalla terra, da -26.74(sole) a 10
public:
    Stella(long double, double, double, unsigned int, double, double, double);
    Stella(const CorpoCeleste&, double, double);

    double getMAss() const;
    double getMApp() const;

    double distanzaTerra() const;
    static vector<array<QString,2>> disegnoDistanti(vector<const Stella*>&); //terra al centro e orbite/stelle

    virtual Stella operator+(const Stella&) const;

    QString paramDisegnoBase() const;
    array<QString,2> paramDisegnoDim() const;
    array<QString,2> paramDisegnoDist() const;

};

#endif // STELLA_H
