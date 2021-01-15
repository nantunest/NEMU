#include "addressingmode.h"

AddressingMode::AddressingMode()
{

}

QVector<quint8> &AddressingMode::fetchOperands(CpuState &cpuState)
{
    return m_operands;
}
