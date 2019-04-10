#include "InstructionOut.hpp"
#include <iostream>

/*
** Builtin functions
*/

InstructionOut::InstructionOut() : Instruction(InstructionOut::s_type)
{
}

InstructionOut::~InstructionOut()
{
}

/*
** Class Specific functions
*/

unsigned char*	InstructionOut::execute(unsigned char* mem, Instruction::Status* status)
{
    char    out[] = {*mem, '\0'};

    // std::cerr << static_cast<int>(*mem) << std::endl;
    std::cout << out;
    *status = Instruction::SEmpty;
    // std::cout << ". ";
    return mem;
}
