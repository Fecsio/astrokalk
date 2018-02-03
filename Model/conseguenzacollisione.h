#ifndef CONSEGUENZACOLLISIONE_H
#define CONSEGUENZACOLLISIONE_H

class ConseguenzaCollisione
{
private:
    unsigned int energia; //megaton
    double magnitudo;
public:
    ConseguenzaCollisione(unsigned int, double);
    unsigned int getEn() const;
    double getMa() const;
};

#endif // CONSEGUENZACOLLISIONE_H
