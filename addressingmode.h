#ifndef ADDRESSINGMODE_H
#define ADDRESSINGMODE_H

#include <QVector>
#include <cpu6502types.h>

class AddressingMode
{
public:
    AddressingMode();

    virtual QVector<quint8>& fetchOperands(CpuState &cpuState) = 0;

    virtual void setup(LoadingHeader &loadingHeader) = 0;

};

#endif // ADDRESSINGMODE_H

