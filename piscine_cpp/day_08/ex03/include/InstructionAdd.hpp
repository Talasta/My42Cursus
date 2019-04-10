#ifndef INSTRUCTIONADD_HPP
# define INSTRUCTIONADD_HPP

# include "Instruction.hpp"

class InstructionAdd : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::Add;

	InstructionAdd();
	virtual ~InstructionAdd();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);


private:
	InstructionAdd(const InstructionAdd&);
	InstructionAdd & operator=(const InstructionAdd&);

};

#endif
