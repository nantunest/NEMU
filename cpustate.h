#ifndef CPUSTATE_H
#define CPUSTATE_H

#include <QTypeInfo>
#include <QVector>

#include <statusregister.h>

class CpuState
{

public:
    CpuState();

    quint16 program_counter() const;

    void program_counter(quint16 _program_counter);

    quint8 stack_pointer() const;

    quint8 accumulator() const;
    void accumulator(quint8 _accumulator);

    quint8 index_register_x() const;

    quint8 index_register_y() const;

    StatusRegister& status_register();

    QVector<quint8> prog_memory() const;

private:
    quint16 m_program_counter;               // Program Counter
    quint8 m_stack_pointer;                  // Stack Pointer
    quint8 m_accumulator;                  // Accumulator
    quint8 m_index_register_x;                  // Index Register X
    quint8 m_index_register_y;                  // Index Register Y
    StatusRegister m_status_register;

    QVector<quint8> m_prog_memory;

};

#endif // CPUSTATE_H
