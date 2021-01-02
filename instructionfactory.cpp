#include "instructionfactory.h"

InstructionFactory::CreateCallbackMap InstructionFactory::s_createCallbackMap;

InstructionFactory::InstructionFactory()
{

}

bool InstructionFactory::RegisterInstruction(OpCodes opCode, InstructionFactory::CreateInstructionCallback createInstructionCallback)
{
    bool mapNotContainsKey = !(s_createCallbackMap.contains(opCode));

    // if map not contains key, then insert
    if (mapNotContainsKey) {
        s_createCallbackMap.insert(opCode, createInstructionCallback);
    }

    // if map not contains key, return success, else fail
    return mapNotContainsKey;
}

bool InstructionFactory::UnregisterInstruction(OpCodes opCode)
{
    return s_createCallbackMap.remove(opCode) == 1;
}

Instruction *InstructionFactory::Create(OpCodes opCode)
{
    CreateCallbackMap::Iterator it = s_createCallbackMap.find(opCode);

    if (it == s_createCallbackMap.end()) {

        // TODO: Raise an exception instead of return nullptr

        return nullptr;
    }

    // the instruction creation function exists so lets call it

    return it.value()();
}
