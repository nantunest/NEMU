#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QTypeInfo>
#include <QVector>
#include <QMap>

#include <addressingmode.h>
#include <cpustate.h>

/*#
 * \class Instruction
 * \brief The Instruction class is the base class of all 6562 instructions.
 */
class Instruction {

public:
    Instruction(quint8 opcode, AddressingMode* addressingMode);

    virtual void setup(LoadingHeader& loadingHeader) = 0;

    virtual void execute(CpuState &cpuState) = 0;

protected:
    AddressingMode * m_addressingMode;

    quint16 m_opcodeAddress;

    quint8 m_opcode;

};

#endif // INSTRUCTION_H
