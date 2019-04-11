#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	Form("ShrubberyCreation", 145 , 137, target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

// Create a file called <target>_shrubbery, and write ASCII trees inside it, in
// the current directory.
void 	ShrubberyCreationForm::executeTrue(void) const
{
	std::ofstream 	out;
	std::string		filename = "_shrubbery";

	out.open(m_target + filename, std::ios::app);
	if (!out) {
		return ;
	}
	out << "oxoxoo    ooxoo" << std::endl;
	out << "ooxoxo oo  oxoxooo" << std::endl;
	out << "oooo xxoxoo ooo ooox" << std::endl;
	out << "oxo o oxoxo  xoxxoxo" << std::endl;
	out << "oxo xooxoooo o ooo" << std::endl;
	out << "ooo\\oo\\  /o/o" << std::endl;
	out << "	\\  \\/ /" << std::endl;
	out << "	 |   /" << std::endl;
	out << "	 |  |" << std::endl;
	out << "	 | D|" << std::endl;
	out << "	 |  |" << std::endl;
	out << "	 |  |" << std::endl;
	out << "______/____\\____" << std::endl;
	out << std::endl;
	out << "oxoxoo    ooxoo" << std::endl;
	out << "ooxoxo oo  oxoxooo" << std::endl;
	out << "oooo xxoxoo ooo ooox" << std::endl;
	out << "oxo o oxoxo  xoxxoxo" << std::endl;
	out << "oxo xooxoooo o ooo" << std::endl;
	out << "ooo\\oo\\  /o/o" << std::endl;
	out << "	\\  \\/ /" << std::endl;
	out << "	 |   /" << std::endl;
	out << "	 |  |" << std::endl;
	out << "	 | D|" << std::endl;
	out << "	 |  |" << std::endl;
	out << "	 |  |" << std::endl;
	out << "______/____\\____" << std::endl;
}
