#ifndef ABSOLUTE_H
#define ABSOLUTE_H

#include <addressingmode.h>

class Absolute : public AddressingMode
{
public:
    Absolute();

    // AddressingMode interface
public:

    void setup(LoadingHeader &loadingHeader);
};

#endif // ABSOLUTE_H
