#include "adc.h"
#include "immediate.h"

#include <QVector>
#include <Cpu6502Types.h>
#include <instructionfactory.h>
#include <statusregister.h>

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

    // Preliminary result of the addition
    quint8 prevAcc = cpuState.accumulator();
    quint16 sum = cpuState.accumulator() + opers[0];

    // Check the carry flag
    if (true == cpuState.status_register().carry_flag())
    {
        // Carry flag set -> add 1 to the result
        sum += 1;
    }

    if (true == cpuState.status_register().decimal_mode())
    {
        // CPU in decimal mode, test carry against 100 result

        if (sum >= 100)
        {
            cpuState.accumulator(sum % 100);
            cpuState.status_register().carry_flag(true);
        }
        else
        {
            cpuState.accumulator(sum);
            cpuState.status_register().carry_flag(false);
        }
    }
    else
    {
        // CPU in binary mode, test carry against 256 result

        if (sum >= 256)
        {
            cpuState.accumulator(sum % 256);
            cpuState.status_register().carry_flag(true);
        }
        else
        {
            cpuState.accumulator(sum);
            cpuState.status_register().carry_flag(false);
        }
    }

    // test if negative

    if (0 > static_cast<qint8>(cpuState.accumulator()))
    {
        cpuState.status_register().negative_flag(true);
    }
    else
    {
        cpuState.status_register().negative_flag(false);
    }

    // test if overflow (effectivelly if 7th bit flipped)

    if ( (prevAcc <= 127 && cpuState.accumulator() > 127)
       ||(prevAcc > 127  && cpuState.accumulator() < 255) )
    {
        cpuState.status_register().overflow_flag(true);
    }
    else
    {
        cpuState.status_register().overflow_flag(false);
    }
}

void ADC::setup(LoadingHeader &loadingHeader)
{
    m_opcodeAddress = loadingHeader.position++;

    m_addressingMode->setup(loadingHeader);
}
