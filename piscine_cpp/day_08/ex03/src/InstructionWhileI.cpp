#include "InstructionWhileI.hpp"

/*
** Builtin functions
*/

InstructionWhileI::InstructionWhileI() : Instruction(InstructionWhileI::s_type)
{
}

InstructionWhileI::~InstructionWhileI()
{
}

/*
** Class Specific functions
*/

unsigned char*	InstructionWhileI::execute(unsigned char* mem, Instruction::Status* status)
{
    // std::cout << "[ ";
    *status = Instruction::SNew;
    return mem;
}
