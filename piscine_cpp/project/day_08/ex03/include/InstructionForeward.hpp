#ifndef INSTRUCTIONFOREWARD_HPP
# define INSTRUCTIONFOREWARD_HPP

# include "Instruction.hpp"

class InstructionForeward : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::Forward;

	InstructionForeward();
	virtual ~InstructionForeward();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);

private:
	InstructionForeward(const InstructionForeward&);
	InstructionForeward & operator=(const InstructionForeward&);

};

#endif
