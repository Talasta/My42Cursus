#include "Instruction.hpp"

/*
** Builtin functions
*/

Instruction::Instruction(Type itype) : m_type(itype)
{
}

Instruction::~Instruction()
{
}

/*
** Class Specific functions
*/

Instruction::Type   Instruction::getType() const
{
    return m_type;
}
