#include "InstructionSub.hpp"

/*
** Builtin functions
*/

InstructionSub::InstructionSub() : Instruction(InstructionSub::s_type)
{
}

InstructionSub::~InstructionSub()
{
}

/*
** Class Specific functions
*/

unsigned char*	InstructionSub::execute(unsigned char* mem, Instruction::Status* status)
{
    // std::cout << "- ";
    *mem -= 1;
    *status = Instruction::SEmpty;
    return mem;
}
