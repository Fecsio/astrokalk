#ifndef ATMOSFERA_H
#define ATMOSFERA_H


class Atmosfera
{
    double ossigeno;
    double azoto;
    double altro;
public:
    Atmosfera(double =21, double =78, double = 1);

    Atmosfera operator+(const Atmosfera&) const;
    double getO() const;
    double getAz() const;
    double getAl() const;

};

#endif // ATMOSFERA_H
