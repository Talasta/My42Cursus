#include "InstructionBackward.hpp"

/*
** Builtin functions
*/

InstructionBackward::InstructionBackward() : Instruction(InstructionBackward::s_type)
{
}

InstructionBackward::~InstructionBackward()
{
}

/*
** Class Specific functions
*/

unsigned char*	InstructionBackward::execute(unsigned char* mem, Instruction::Status* status)
{
    // std::cout << "< ";
    mem -= 1;
    *status = Instruction::SEmpty;
    return mem;
}
