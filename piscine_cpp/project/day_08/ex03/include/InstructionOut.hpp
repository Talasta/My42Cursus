#ifndef INSTRUCTIONOUT_HPP
# define INSTRUCTIONOUT_HPP

# include "Instruction.hpp"

class InstructionOut : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::Out;

	InstructionOut();
	virtual ~InstructionOut();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);

private:
	InstructionOut(const InstructionOut&);
	InstructionOut & operator=(const InstructionOut&);

};

#endif
