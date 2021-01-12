#include "statusregister.h"

StatusRegister::StatusRegister()
    : m_carry_flag(false)
    , m_zero_flag(false)
    , m_interrupt_disable(false)
    , m_decimal_mode(false)
    , m_break_command(false)
    , m_not_used(false)
    , m_overflow_flag(false)
    , m_negative_flag(false)
{

}

bool StatusRegister::negative_flag() const
{
    return m_negative_flag;
}

void StatusRegister::negative_flag(bool negative_flag)
{
    m_negative_flag = negative_flag;
}

bool StatusRegister::overflow_flag() const
{
    return m_overflow_flag;
}

void StatusRegister::overflow_flag(bool overflow_flag)
{
    m_overflow_flag = overflow_flag;
}

bool StatusRegister::not_used() const
{
    return m_not_used;
}

void StatusRegister::not_used(bool not_used)
{
    m_not_used = not_used;
}

bool StatusRegister::break_command() const
{
    return m_break_command;
}

void StatusRegister::break_command(bool break_command)
{
    m_break_command = break_command;
}

bool StatusRegister::decimal_mode() const
{
    return m_decimal_mode;
}

void StatusRegister::decimal_mode(bool decimal_mode)
{
    m_decimal_mode = decimal_mode;
}

bool StatusRegister::interrupt_disable() const
{
    return m_interrupt_disable;
}

void StatusRegister::interrupt_disable(bool interrupt_disable)
{
    m_interrupt_disable = interrupt_disable;
}

bool StatusRegister::zero_flag() const
{
    return m_zero_flag;
}

void StatusRegister::zero_flag(bool zero_flag)
{
    m_zero_flag = zero_flag;
}

bool StatusRegister::carry_flag() const
{
    return m_carry_flag;
}

void StatusRegister::carry_flag(bool carry_flag)
{
    m_carry_flag = carry_flag;
}
