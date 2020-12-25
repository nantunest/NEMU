#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QTypeInfo>

class Instruction {

public:
    Instruction(quint8 opcode) : m_opcode(opcode) {}
    virtual void execute() = 0;
private:
    const quint8 m_opcode;
};

#endif // INSTRUCTION_H
