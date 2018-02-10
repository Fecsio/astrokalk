#ifndef DATAORATERRESTRE_H
#define DATAORATERRESTRE_H
#include<QTime>
#include "dataterrestre.h"

class DataOraTerrestre: public QTime, public DataTerrestre{

public:
    DataOraTerrestre(int );

};

#endif // DATAORATERRESTRE_H
