#include <QCoreApplication>

#include "adc.h"
#include "instruction.h"
#include "instructionfactory.h"

int main(int argc, char *argv[])
{

    CpuState cpu = {0};

    cpu.progMemory.reserve(10);

    cpu.progMemory.append(0x69);

    cpu.progMemory.append(0x1E);

    Instruction * inst = InstructionFactory::Create(OpCodes::ADCi);

    LoadingHeader lh = {0, cpu.progMemory};

    inst->setup(lh);

    inst->execute(cpu);

    QCoreApplication a(argc, argv);

    return a.exec();
}
