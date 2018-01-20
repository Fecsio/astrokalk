#ifndef DATAORATERRESTRE_H
#define DATAORATERRESTRE_H
#include<QTime>
#include "dataterrestre.h"

class DataOraTerrestre: public QTime, public DataTerrestre{

public:
    DataOraTerrestre(int );

};

std::ostream& operator << (std::ostream& , const DataOraTerrestre&);

#endif // DATAORATERRESTRE_H
