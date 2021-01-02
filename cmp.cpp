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

    qint8 res = cpuState.A - opers[0];

    if (0 == res)
    {
        cpuState.status_register[StatusRegisterBitNames::kZeroFlag] = true;
        cpuState.status_register[StatusRegisterBitNames::kNegativeFlag] = false;
        cpuState.status_register[StatusRegisterBitNames::kCarryFlag] = true;
    }
    else if (0 > res)
    {
        cpuState.status_register[StatusRegisterBitNames::kZeroFlag] = false;
        cpuState.status_register[StatusRegisterBitNames::kNegativeFlag] = true;
        cpuState.status_register[StatusRegisterBitNames::kCarryFlag] = false;
    }
    else
    {
        cpuState.status_register[StatusRegisterBitNames::kZeroFlag] = false;
        cpuState.status_register[StatusRegisterBitNames::kNegativeFlag] = false;
        cpuState.status_register[StatusRegisterBitNames::kCarryFlag] = true;
    }

}
