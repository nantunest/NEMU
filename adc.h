#ifndef ADC_H
#define ADC_H

#include <instruction.h>

/*#
 * \brief Class to implement the instruction ADC of the 6062.
 */
class ADC : public Instruction
{
public:

    ADC(quint8 opcode, AddressingMode *addressingMode);

    void execute(CpuState &cpuState);

    void setup(LoadingHeader &loadingHeader);

};

#endif // ADC_H
