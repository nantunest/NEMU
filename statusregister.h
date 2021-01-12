#ifndef STATUSREGISTER_H
#define STATUSREGISTER_H

class StatusRegister
{
public:
    StatusRegister();

    bool carry_flag() const;
    void carry_flag(bool carry_flag);

    bool zero_flag() const;
    void zero_flag(bool zero_flag);

    bool interrupt_disable() const;
    void interrupt_disable(bool interrupt_disable);

    bool decimal_mode() const;
    void decimal_mode(bool decimal_mode);

    bool break_command() const;
    void break_command(bool break_command);

    bool not_used() const;
    void not_used(bool not_used);

    bool overflow_flag() const;
    void overflow_flag(bool overflow_flag);

    bool negative_flag() const;
    void negative_flag(bool negative_flag);

private:

    bool m_carry_flag;
    bool m_zero_flag;
    bool m_interrupt_disable;
    bool m_decimal_mode;
    bool m_break_command;
    bool m_not_used;
    bool m_overflow_flag;
    bool m_negative_flag;

};

#endif // STATUSREGISTER_H
