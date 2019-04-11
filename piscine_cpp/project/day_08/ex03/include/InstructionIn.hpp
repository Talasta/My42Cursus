#ifndef INSTRUCTIONIN_HPP
# define INSTRUCTIONIN_HPP

# include "Instruction.hpp"

class InstructionIn : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::In;

	InstructionIn();
	virtual ~InstructionIn();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);

private:
	InstructionIn(const InstructionIn&);
	InstructionIn & operator=(const InstructionIn&);

};

#endif
