#include "instruction.h"

Instruction::Instruction(quint8 opcode, AddressingMode* addressingMode)
    : m_addressingMode(addressingMode)
    , m_opcode(opcode)

{

}
