#include <QCoreApplication>

#include "adc.h"
#include "instruction.h"
#include "instructionfactory.h"

int main(int argc, char *argv[])
{

    CpuState cpu;

    cpu.prog_memory().reserve(10);

    cpu.prog_memory().append(0x69);

    cpu.prog_memory().append(0x1E);

    Instruction * inst = InstructionFactory::Create(OpCodes::ADCi);

    LoadingHeader lh = {0, static_cast<const QVector<quint8> >(cpu.prog_memory())};

    inst->setup(lh);

    inst->execute(cpu);

    QCoreApplication a(argc, argv);

    return a.exec();
}
