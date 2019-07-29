#include <iostream>
#include <deque>

#include "virtual_machine.hpp"
#include "exceptions.hpp"

const VirtualMachine::OpeMap    VirtualMachine::s_ope = VirtualMachine::create_opemap();

const VirtualMachine::CmdMap    VirtualMachine::s_cmd = VirtualMachine::create_cmdmap();

/* Public methods *************************************************************/

VirtualMachine::VirtualMachine(void) : m_end(false)
{}

VirtualMachine::~VirtualMachine(void) {
    while (m_pile.size() > 0) {
        delete m_pile.front();
        m_pile.pop_front();
    }
}

void            VirtualMachine::run(std::deque<Instruction> instructions) {
    std::deque<Instruction>::iterator       iter(instructions.begin()), end(instructions.end());
    VirtualMachine::CmdMap::const_iterator  cmd;

    while (iter != end) {
        cmd = s_cmd.find(iter->getCmd());
        if (cmd != s_cmd.end())
            (this->*(cmd->second))(*iter);
        if (m_end)
            return ;
        iter++;
    }
    if (iter == end)
        throw NoExitInstruction();
}

/* Member methods *************************************************************/

void            VirtualMachine::push(Instruction const &nst) {
    IOperand::eOperandType                  type;
    VirtualMachine::OpeMap::const_iterator  cit;

    cit = s_ope.find(nst.getCast());
    if (cit != s_ope.end())
        type = cit->second;
    else
        throw TypeError();
    m_pile.push_front(OperandFactory::get().createOperand(type, nst.getVal()));
}

void            VirtualMachine::assert(Instruction const &nst) {
    IOperand::eOperandType                  type;
    VirtualMachine::OpeMap::const_iterator  cit;

    cit = s_ope.find(nst.getCast());
    if (cit != s_ope.end())
        type = cit->second;
    else
        throw TypeError();
    const IOperand    *ope1 = top();
    if (ope1->getType() != type)
        throw AssertError();
    const IOperand    *ope2 = OperandFactory::get().createOperand(type, nst.getVal());
    if (ope1->toString() != ope2->toString())
        throw AssertError();
    delete ope2;
    m_pile.push_front(ope1);
}

void            VirtualMachine::pop(Instruction const &nst) {
    (void)nst;
    const IOperand    *ope = top();
    delete ope;
}

void            VirtualMachine::dump(Instruction const &nst) {
    (void)nst;
    std::deque<const IOperand*>::const_iterator iter(m_pile.begin()), end(m_pile.end());

    while (iter != end) {
        std::cout << (*iter)->toString() << std::endl;
        iter++;
    }
}

void            VirtualMachine::add(Instruction const &nst) {
    (void)nst;
    const IOperand    *ope1 = top();
    const IOperand    *ope2 = top();
    m_pile.push_front(*ope1 + *ope2);
    delete ope1;
    delete ope2;
}

void            VirtualMachine::sub(Instruction const &nst) {
    (void)nst;
    const IOperand    *ope1 = top();
    const IOperand    *ope2 = top();
    m_pile.push_front(*ope1 - *ope2);
    delete ope1;
    delete ope2;
}

void            VirtualMachine::mul(Instruction const &nst) {
    (void)nst;
    const IOperand    *ope1 = top();
    const IOperand    *ope2 = top();
    m_pile.push_front(*ope1 * *ope2);
    delete ope1;
    delete ope2;
}

void            VirtualMachine::div(Instruction const &nst) {
    (void)nst;
    const IOperand    *ope1 = top();
    const IOperand    *ope2 = top();
    m_pile.push_front(*ope1 / *ope2);
    delete ope1;
    delete ope2;
}

void            VirtualMachine::mod(Instruction const &nst) {
    (void)nst;
    const IOperand    *ope1 = top();
    const IOperand    *ope2 = top();
    m_pile.push_front(*ope1 % *ope2);
    delete ope1;
    delete ope2;
}

void            VirtualMachine::print(Instruction const &nst) {
    (void)nst;
    const IOperand    *ope = top();
    if (ope->getType() != IOperand::Int8)
        throw TypeError();
    std::cout << static_cast<char>(std::stoi(ope->toString())) << std::endl;
    m_pile.push_front(ope);
}

void            VirtualMachine::exit(Instruction const &nst) {
    (void)nst;
    m_end = true;
}

VirtualMachine::OpeMap          VirtualMachine::create_opemap(void) {
    VirtualMachine::OpeMap  m;

    m["int8"] = IOperand::Int8;
    m["int16"] = IOperand::Int16;
    m["int32"] = IOperand::Int32;
    m["float"] = IOperand::Float;
    m["double"] = IOperand::Double;
    return m;
}

VirtualMachine::CmdMap          VirtualMachine::create_cmdmap(void) {
    VirtualMachine::CmdMap  m;

    m["push"] = &VirtualMachine::push;
    m["assert"] = &VirtualMachine::assert;
    m["pop"] = &VirtualMachine::pop;
    m["dump"] = &VirtualMachine::dump;
    m["add"] = &VirtualMachine::add;
    m["sub"] = &VirtualMachine::sub;
    m["mul"] = &VirtualMachine::mul;
    m["div"] = &VirtualMachine::div;
    m["mod"] = &VirtualMachine::mod;
    m["print"] = &VirtualMachine::print;
    m["exit"] = &VirtualMachine::exit;
    return m;
}

const IOperand      *VirtualMachine::top(void) {
    const IOperand    *ope;

    if (m_pile.size() < 1)
        throw StackSizeError();
    ope = m_pile.front();
    m_pile.pop_front();
    return ope;
}

/* Compliant methods **********************************************************/

VirtualMachine::VirtualMachine(const VirtualMachine &src) {
	*this = src;
	return;
}

VirtualMachine &VirtualMachine::operator=(const VirtualMachine &src) {
    if (this != &src)
        m_pile = src.m_pile;
	return *this;
}
