#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <fstream>

class Logger {

public:

	Logger(std::string);
	~Logger(void);

	void 				log(std::string const &, std::string const &);

	std::string const	getName(void) const ;

private:
	std::string const	_name;

	void 				logToConsole(std::string);
	void 				logToFile(std::string);

	std::string			makeLogEntry(std::string) const ;

};

#endif
