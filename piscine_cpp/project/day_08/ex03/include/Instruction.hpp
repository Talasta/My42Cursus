#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <iostream>

class Instruction
{

public:

	enum	Type
	{
		Forward  = 0,
		Backward,
		Add,
		Sub,
		In,
		Out,
		WhileI,
		WhileO,
		COUNT
	};

	enum Status
	{
		SEmpty = 0,
		SRestart,
		SBreak,
		SNew,
		SCOUNT
	};

	Instruction(Type);
	virtual ~Instruction();

	Type 			getType() const;
	virtual unsigned char*	execute(unsigned char* mem, Status* status) = 0;

protected:

	Type		m_type;

private:

	Instruction();
	Instruction(const Instruction&);
	Instruction & operator=(const Instruction&);


};

#endif
