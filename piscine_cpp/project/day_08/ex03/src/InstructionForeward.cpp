#include "InstructionForeward.hpp"

/*
** Builtin functions
*/

InstructionForeward::InstructionForeward() : Instruction(InstructionForeward::s_type)
{
}

InstructionForeward::~InstructionForeward()
{
}

/*
** Class Specific functions
*/

unsigned char*	InstructionForeward::execute(unsigned char* mem, Instruction::Status* status)
{
    // std::cout << "> ";
    mem += 1;
    *status = Instruction::SEmpty;
    return mem;
}
