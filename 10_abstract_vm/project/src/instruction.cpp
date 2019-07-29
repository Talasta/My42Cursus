#include <iostream>

#include "instruction.hpp"
#include "exceptions.hpp"

/* Public methods *************************************************************/

Instruction::Instruction(void)
{}

Instruction::~Instruction(void)
{}

std::string Instruction::getCmd(void) const { return m_cmd; }
std::string Instruction::getCast(void) const { return m_cast; }
std::string Instruction::getVal(void) const { return m_val; }

void        Instruction::setCmd(std::string val) { m_cmd = val; }
void        Instruction::setCast(std::string val) { m_cast = val; }
void        Instruction::setVal(std::string val) {
    // Check if val is good in function of cast
    if (m_cast.compare(""))
        m_val = val;
}

int         Instruction::compile(void) {
    if (!m_cmd.compare(""))
        return 0;
    if (need_val() && (!m_cast.compare("") || !m_val.compare("")))
        throw UnknownInstruction();
    return 1;
}

void        Instruction::print(void) {
    std::cout << m_cmd << " | " << m_cast << " | " << m_val << std::endl;
}


/* Member methods *************************************************************/
int         Instruction::need_val(void) {
    if (!m_cmd.compare("assert") || !m_cmd.compare("push"))
        return 1;
    return 0;
}

/* Compliant methods **********************************************************/

Instruction::Instruction(const Instruction &src) {
	*this = src;
}

Instruction &Instruction::operator=(const Instruction &src) {
    if (this != &src) {
        m_cmd = src.m_cmd;
        m_cast = src.m_cast;
        m_val = src.m_val;
    }
	return *this;
}
