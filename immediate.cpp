#include "immediate.h"

Immediate::Immediate()
    : m_operands(1)
{

}

QVector<quint8> Immediate::operands() const
{
    return m_operands;
}

void Immediate::setup(LoadingHeader &loadingHeader)
{
    m_operands[0] = loadingHeader.progMemory[loadingHeader.position++];
}
