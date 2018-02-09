#ifndef ECCINPUT_H
#define ECCINPUT_H
#include <stdexcept>

class EccInput: public std::logic_error
{
public:
    EccInput();
};

#endif // ECCINPUT_H
