#include "Runner.hpp"
#include <iostream>
#include <fstream>

/*
** Builtin functions
*/

Runner::Runner() : m_instructions(std::vector<Instruction*>()), m_mem(new unsigned char[MEM_SIZE])
{
    for (unsigned int i = 0; i < MEM_SIZE; ++i)
    {
        m_mem[i] = 0;
    }
}

Runner::~Runner()
{
    delete [] m_mem;
}

/*
** Class Specific functions
*/

void        Runner::createInstruction(char c)
{
    switch (c)
    {
        // case '+':
        case 'a':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionAdd()));
            break;
        // case '-':
        case 's':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionSub()));
            break;
        // case '<':
        case 'b':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionBackward()));
            break;
        // case '>':
        case 'f':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionForeward()));
            break;
        // case ',':
        case 'i':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionIn()));
            break;
        // case '.':
        case 'o':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionOut()));
            break;
        // case '[':
        case 'w':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionWhileI()));
            break;
        // case ']':
        case 'r':
            m_instructions.push_back(dynamic_cast<Instruction*>(new InstructionWhileO()));
            break;
        default:
            break;
    }
}

void		Runner::read(char* cfile)
{
    std::string filename(cfile), line;
    std::ifstream in(filename);

    while (getline(in, line))
    {
        for(std::string::iterator it = line.begin(); it != line.end(); ++it)
        {
            createInstruction(*it);
        }
    }
}

void        Runner::debug(unsigned char * str)
{
    std::cout << "pos ::\t" << static_cast<int>(str - m_mem) << "\t::\t";
    for (int i = 0; i < 20; ++i)
    {
        std::cout << static_cast<int>(m_mem[i]) << " ";
    }
    std::cout << std::endl;
}

unsigned char*        Runner::loop(Runner::iterator* instruction, unsigned char* mem)
{
    Instruction::Status     status = Instruction::SEmpty;
    Instruction::Type       itype;
    Runner::iterator        first(*instruction);

    while (*(*instruction) && *instruction != m_instructions.end())
    {
        itype = (*(*instruction))->getType();
        switch (itype)
        {
            case Instruction::Forward:
                mem = (dynamic_cast<InstructionForeward*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::Backward:
                mem = (dynamic_cast<InstructionBackward*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::Add:
                mem = (dynamic_cast<InstructionAdd*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::Sub:
                mem = (dynamic_cast<InstructionSub*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::In:
                mem = (dynamic_cast<InstructionIn*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::Out:
                mem = (dynamic_cast<InstructionOut*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::WhileI:
                mem = (dynamic_cast<InstructionWhileI*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::WhileO:
                mem = (dynamic_cast<InstructionWhileO*>(*(*instruction)))->execute(mem, &status);
                break;
            case Instruction::COUNT:
                break;
        }
        // debug(mem);
        if (status == Instruction::SRestart)
        {
            *instruction = Runner::iterator(first);
        }
        else if (status == Instruction::SNew)
        {
            ++(*instruction);
            mem = loop(instruction, mem);
        }
        else if (status == Instruction::SBreak)
        {
            ++(*instruction);
            return mem;
        }
        else
        {
            ++(*instruction);
        }
    }
    return mem;
}

void		Runner::execute(void)
{
    unsigned char* mem = m_mem;
    if (m_instructions.size() == 0)
        return ;
    Runner::iterator first = m_instructions.begin();
    mem = loop(&first, mem);
}
