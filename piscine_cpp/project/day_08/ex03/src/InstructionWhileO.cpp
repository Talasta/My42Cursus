#include "InstructionWhileO.hpp"

/*
** Builtin functions
*/

InstructionWhileO::InstructionWhileO() : Instruction(InstructionWhileO::s_type)
{
}

InstructionWhileO::~InstructionWhileO()
{
}

/*
** Class Specific functions
*/

unsigned char*	InstructionWhileO::execute(unsigned char* mem, Instruction::Status* status)
{
    // std::cout << "] ";
    if (*mem == 0)
    {
        *status = Instruction::SBreak;
    }
    else
    {
        *status = Instruction::SRestart;
    }
    return mem;
}
