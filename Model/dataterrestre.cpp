#include "dataterrestre.h"

double DataTerrestre::AnniFraz() const{return (double)giorni/365;}
int DataTerrestre::AnniInteri() const {return giorni/365;}
int DataTerrestre::Giorni() const {return giorni%365;}

DataTerrestre::DataTerrestre(int g): giorni(g){
    if(giorni < 0) giorni=0;
}


