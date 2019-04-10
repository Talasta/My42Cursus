#ifndef INSTRUCTIONBACKWARD_HPP
# define INSTRUCTIONBACKWARD_HPP

# include "Instruction.hpp"

class InstructionBackward : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::Backward;

	InstructionBackward();
	virtual ~InstructionBackward();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);

private:
	InstructionBackward(const InstructionBackward&);
	InstructionBackward & operator=(const InstructionBackward&);

};

#endif
