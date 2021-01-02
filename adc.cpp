#include "adc.h"
#include "immediate.h"

#include <QVector>
#include <Cpu6502Types.h>
#include <instructionfactory.h>

namespace {
    Instruction * CreateADCImmediate() {
        return new ADC(opcodes::immediate::ADC, new Immediate()); // new Immediate is not the best approach but lets do like this for now.
    };

    const bool registered = InstructionFactory::RegisterInstruction(OpCodes::ADCi, CreateADCImmediate);
}

ADC::ADC(quint8 opcode, AddressingMode *addressingMode)
    : Instruction(opcode, addressingMode)
{

}

void ADC::execute(CpuState &cpuState)
{
    QVector<quint8> &opers = m_addressingMode->fetchOperands(cpuState);

    quint16 sum = cpuState.A + opers[0];

    if (sum > 255)
    {
        cpuState.A = sum % 256;
        cpuState.status_register[StatusRegisterBitNames::kCarryFlag] = true;
    }
    else
    {
        cpuState.A = sum;
        cpuState.status_register[StatusRegisterBitNames::kCarryFlag] = false;
    }
}

void ADC::setup(LoadingHeader &loadingHeader)
{
    m_opcodeAddress = loadingHeader.position++;

    m_addressingMode->setup(loadingHeader);
}
