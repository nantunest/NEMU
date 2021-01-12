#include "cpustate.h"

CpuState::CpuState()
{

}

QVector<quint8> CpuState::prog_memory() const
{
    return m_prog_memory;
}

StatusRegister &CpuState::status_register()
{
    return m_status_register;
}

quint8 CpuState::index_register_y() const
{
    return m_index_register_y;
}

quint8 CpuState::index_register_x() const
{
    return m_index_register_x;
}

quint8 CpuState::accumulator() const
{
    return m_accumulator;
}

void CpuState::accumulator(quint8 _accumulator)
{
    m_accumulator = _accumulator;
}

quint8 CpuState::stack_pointer() const
{
    return m_stack_pointer;
}

quint16 CpuState::program_counter() const
{
    return m_program_counter;
}

void CpuState::program_counter(quint16 _program_counter)
{
    m_program_counter = _program_counter;
}
