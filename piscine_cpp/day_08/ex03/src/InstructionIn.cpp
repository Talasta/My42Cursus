#include "InstructionIn.hpp"
#include <iostream>

/*
** Builtin functions
*/

InstructionIn::InstructionIn() : Instruction(InstructionIn::s_type)
{
}

InstructionIn::~InstructionIn()
{
}

/*
** Class Specific functions
*/

unsigned char*	InstructionIn::execute(unsigned char* mem, Instruction::Status* status)
{
    char    c;

    // std::cout << ", ";
    std::cin >> c;
    *mem = c;
    *status = Instruction::SEmpty;
    return mem;
}
