#include "Logger.hpp"

Logger::Logger(std::string name) : _name(name) {
	std::cout << "Constructed" << std::endl;
}

Logger::~Logger(void) {
	std::cout << "Destructed" << std::endl;
}

void 				Logger::log(std::string const  & dest, std::string const & message) {
	std::string list[] = {"logfile", "console"};
	void(Logger::*func[])(std::string) = {&Logger::logToFile, &Logger::logToConsole};

	std::string formated_message = this->makeLogEntry(message);

	int i = 0;
	for (i = 0; i < 2; i++) {
		if (list[i].compare(dest) == 0) {
			(this->*(func[i]))(formated_message);
			break;
		}
	}
	if (i == 2) {
		std::cerr << "Could not write log on " << dest << "." << std::endl;
	}
}


void 				Logger::logToConsole(std::string str) {
	std::cout << str << std::endl << std::flush;
}

void 				Logger::logToFile(std::string str) {
	std::ofstream out;

	out.open(this->getName(), std::ios::app);
	if (!out) {
        std::cerr << "Could not open " << this->getName() << ".replace" << std::endl;
        return ;
    }
	out << str << std::endl;
}

std::string			Logger::makeLogEntry(std::string msg)  const {
	char buff[20];
	struct tm *sTm;
	time_t now = time (0);
	sTm = gmtime (&now);
	strftime(buff, sizeof(buff), "[%Y%m%d::%H%M%S] ", sTm);
	std::string log_entry(buff);
	log_entry += msg;
	return log_entry;
}

std::string const	Logger::getName(void) const { return this->_name; }
