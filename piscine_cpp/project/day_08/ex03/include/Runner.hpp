#ifndef RUNNER_HPP
# define RUNNER_HPP

# include <vector>
# include "Instruction.hpp"
# include "InstructionAdd.hpp"
# include "InstructionSub.hpp"
# include "InstructionBackward.hpp"
# include "InstructionForeward.hpp"
# include "InstructionIn.hpp"
# include "InstructionOut.hpp"
# include "InstructionWhileI.hpp"
# include "InstructionWhileO.hpp"

class Runner
{
public:

	Runner();
	~Runner();

	void		read(char*);
	void		execute(void);

private:

	typedef std::vector<Instruction*>::iterator iterator;

	Runner(const Runner&);
	Runner & operator=(const Runner&);

	void			createInstruction(char c);
	unsigned char*	loop(iterator* instruction, unsigned char* mem);
	void        debug(unsigned char * str);

	std::vector<Instruction*>	m_instructions;
	unsigned char*				m_mem;
};

# define MEM_SIZE 30000

#endif
