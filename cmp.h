#ifndef CMP_H
#define CMP_H

#include <instruction.h>
#include <cpustate.h>

/*#
 * \brief Class to implement the instruction CMP of the 6062.
 */
class CMP : public Instruction
{
public:

    CMP(quint8 opcode, AddressingMode *addressingMode);

    void setup(LoadingHeader &loadingHeader);

    void execute(CpuState &cpuState);
};

#endif // CMP_H
