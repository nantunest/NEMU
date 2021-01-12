#ifndef IMMEDIATE_H
#define IMMEDIATE_H

#include <QTypeInfo>
#include <addressingmode.h>

#include <cpustate.h>

class Immediate : public AddressingMode
{
public:
    Immediate();

    virtual QVector<quint8> &fetchOperands(CpuState &cpuState);

    QVector<quint8> operands() const;

    void setup(LoadingHeader &loadingHeader);

private:
    QVector<quint8> m_operands;

};

#endif // IMMEDIATE_H
