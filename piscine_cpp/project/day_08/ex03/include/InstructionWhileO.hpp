#ifndef INSTRUCTIONWHILEO_HPP
# define INSTRUCTIONWHILEO_HPP

# include "Instruction.hpp"

class InstructionWhileO : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::WhileO;

	InstructionWhileO();
	~InstructionWhileO();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);

private:
	InstructionWhileO(const InstructionWhileO&);
	InstructionWhileO & operator=(const InstructionWhileO&);

};

#endif
