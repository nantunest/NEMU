#include <QCoreApplication>

enum class StatusRegister{
    kCarryFlag = 0,
    kZeroFlag = 1,
    kInterruptDisable = 2,
    kDecimalMode = 3,
    kBreakCommand = 4,
    kNotUsed = 5,
    kOverflowFlag = 6,
    kNegativeFlag = 7
};

struct CpuState {
    quint16 PC;                // Program Counter
    quint8 SP;                 // Stack Pointer
    quint8 A;                  // Accumulator
    quint8 X;                  // Index Register X
    quint8 Y;                  // Index Register Y
    bool status_register[8];
};

namespace opcodes {
    enum class Immediate {
        ADC = 0x69, // Adds the immediate to the accumulator
        CMP = 0xC9, // Compares the immediate with accumulator
        LDA = 0xA9, // Load the immediate in the accumulator
    };
};

class Instruction {

public:
    Instruction(quint8 opcode) : m_opcode(opcode) {}
    virtual void execute() = 0;
private:
    const quint8 m_opcode;
};

class AddressingMode {

};

class ADC : public Instruction{
    ADC();

};

/*
 * Class used to decode the comming instruction and call the execute
 */
class OpDecoder {

private:

    // Instruction map
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
