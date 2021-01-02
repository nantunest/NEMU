#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H

#include <QMap>

#include <instruction.h>
#include <cpu6502types.h>

class InstructionFactory
{
public:

    typedef Instruction* (*CreateInstructionCallback)();

    InstructionFactory();

    static bool RegisterInstruction(OpCodes opCode, CreateInstructionCallback createInstructionCallback);

    static bool UnregisterInstruction(OpCodes opCode);

    static Instruction * Create(OpCodes opCode);

    typedef QMap<OpCodes, CreateInstructionCallback> CreateCallbackMap;

    static CreateCallbackMap s_createCallbackMap;

};

#endif // INSTRUCTIONFACTORY_H
