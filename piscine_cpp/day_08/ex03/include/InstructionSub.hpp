#ifndef INSTRUCTIONSUB_HPP
# define INSTRUCTIONSUB_HPP

# include "Instruction.hpp"

class InstructionSub : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::Sub;

	InstructionSub();
	virtual ~InstructionSub();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);

private:
	InstructionSub(const InstructionSub&);
	InstructionSub & operator=(const InstructionSub&);

};

#endif
