#include "dataoraterrestre.h"

DataOraTerrestre::DataOraTerrestre(int s): QTime((s%86400)/3600, (s/60)%60,  (s%60)),DataTerrestre(s/86400){}


std::ostream& operator << (std::ostream& os, const DataOraTerrestre& dot){

    return os << static_cast<const DataTerrestre&>(dot) << "e " << static_cast<const QTime&>(dot).toString().toStdString() << " ore";

}
