#ifndef INSTRUCTIONWHILEI_HPP
# define INSTRUCTIONWHILEI_HPP

# include "Instruction.hpp"

class InstructionWhileI : public Instruction
{
public:

	static const Instruction::Type 	s_type = Instruction::WhileI;

	InstructionWhileI();
	virtual ~InstructionWhileI();

	virtual unsigned char*	execute(unsigned char* mem, Instruction::Status* status);

private:
	InstructionWhileI(const InstructionWhileI&);
	InstructionWhileI & operator=(const InstructionWhileI&);

};

#endif
