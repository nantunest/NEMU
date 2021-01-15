#ifndef ADDRESSINGMODE_H
#define ADDRESSINGMODE_H

#include <QVector>
#include <cpu6502types.h>

#include <cpustate.h>

class AddressingMode
{
public:
    AddressingMode();

    virtual QVector<quint8>& fetchOperands(CpuState &cpuState);

    virtual void setup(LoadingHeader &loadingHeader) = 0;

protected:
        QVector<quint8> m_operands;

};

#endif // ADDRESSINGMODE_H

