#ifndef DATATERRESTRE_H
#define DATATERRESTRE_H
#include <iostream>

//definisco perchè ho bisogno dell'anno 0
class DataTerrestre{
private:
    int giorni;
public:
    double AnniFraz() const;
    int AnniInteri() const;
    int Giorni() const;

    DataTerrestre(int);
};

std::ostream& operator<<(std::ostream& , const DataTerrestre& );

#endif // DATATERRESTRE_H
//31 536 000
