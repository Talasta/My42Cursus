#include "InstructionAdd.hpp"

/*
** Builtin functions
*/

InstructionAdd::InstructionAdd() : Instruction(InstructionAdd::s_type)
{
}

InstructionAdd::~InstructionAdd()
{
}

/*
** Class Specific functions
*/


unsigned char*	InstructionAdd::execute(unsigned char* mem, Instruction::Status* status)
{
    // std::cout << "+ ";
    *mem += 1;
    *status = Instruction::SEmpty;
    return mem;
}
