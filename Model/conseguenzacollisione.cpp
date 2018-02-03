#include "conseguenzacollisione.h"

ConseguenzaCollisione::ConseguenzaCollisione(unsigned int e, double m): energia(e), magnitudo(m){}

unsigned int ConseguenzaCollisione::getEn() const{
    return energia;
}

double ConseguenzaCollisione::getMa() const {
    return magnitudo;
}
