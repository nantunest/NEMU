#ifndef CPU6502TYPES_H
#define CPU6502TYPES_H

#include <QTypeInfo>
#include <QVector>

enum StatusRegisterBitNames{
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

    QVector<quint8> progMemory;
};

namespace opcodes {
    enum immediate {
        ADC = 0x69, // Adds the immediate to the accumulator
        CMP = 0xC9, // Compares the immediate with accumulator
        LDA = 0xA9, // Load the immediate in the accumulator
    };
};

enum class OpCodes
{
    ADCi,
    CMPi,
    LDAi
};

struct LoadingHeader {
    quint16 position;
    QVector<quint8> &progMemory;
};

#endif // CPU6502TYPES_H
