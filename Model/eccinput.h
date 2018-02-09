#ifndef ECCINPUT_H
#define ECCINPUT_H
#include <stdexcept>
using std::string;

class EccInput: public std::logic_error
{
public:
    EccInput(const string&);
    string why()const;
private:
    string motivo;
};

#endif // ECCINPUT_H
