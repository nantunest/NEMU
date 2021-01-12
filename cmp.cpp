#include "cmp.h"

CMP::CMP(quint8 opcode, AddressingMode *addressingMode)
    : Instruction(opcode, addressingMode)
{

}

void CMP::setup(LoadingHeader &loadingHeader)
{
    m_opcodeAddress = loadingHeader.position++;

    m_addressingMode->setup(loadingHeader);
}

void CMP::execute(CpuState &cpuState)
{
    QVector<quint8> &opers = m_addressingMode->fetchOperands(cpuState);

    qint8 res = cpuState.accumulator() - opers[0];

    if (0 == res)
    {
        cpuState.status_register().zero_flag(true);
        cpuState.status_register().negative_flag(false);
        cpuState.status_register().carry_flag(true);
    }
    else if (0 > res)
    {
        cpuState.status_register().zero_flag(false);
        cpuState.status_register().negative_flag(true);
        cpuState.status_register().carry_flag(false);
    }
    else
    {
        cpuState.status_register().zero_flag(false);
        cpuState.status_register().negative_flag(false);
        cpuState.status_register().carry_flag(true);
    }

}
