#include "dataoraterrestre.h"

DataOraTerrestre::DataOraTerrestre(int s): QTime((s%86400)/3600, (s/60)%60,  (s%60)),DataTerrestre(s/86400){}
