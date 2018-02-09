#include "eccinput.h"

EccInput::EccInput(const string& m):logic_error("Errore input"), motivo(m){}

string EccInput::why()const{
    return motivo;
}
