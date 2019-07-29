#include <iostream>
#include <fstream>
#include <algorithm>

#include "utils.hpp"

/*
** Function to reada file and store all the lines in a deque
** @return: 0 [SUCCESS]
**      [ERR] < 0
*/

int         readprog(int ac, char *av[], std::deque<std::string> &data) {
    std::ifstream myfile;
    std::string line;

    if (ac == 2) {
        std::string filename(av[1]);
        myfile.open(filename, std::ifstream::in);
        if (!myfile.is_open()) {
            std::cout << "Unable to open file" << std::endl;
            return -ERR_OPEN;
        }
        else {
            while (getline(myfile, line))
                data.push_back(line + "\n");
            myfile.close();
        }
    }
    else if (ac == 1) {
        while (getline(std::cin, line)) {
            data.push_back(line + "\n");
            if (0 == data.back().compare(";;\n"))
                break;
        }
    }
    else
        return -ERR_ARGS;
    return 0;
}

/*
**
*/

std::string error_liner(std::string const &line, std::string const &error) {
    size_t      len;
    size_t      pos;

    if (error.compare("\n")) {
        pos = line.find(error);
        len = error.size();
    }
    else {
        pos = line.size() - 1;
        len = 1;
    }

    std::string errstr(pos, ' ');

    errstr += "^";
    if (len > 1)
        errstr += std::string(len - 1, '~');
    return errstr;
}

/*
** Trim function for string sanitizing
*/

std::string trim(const std::string& s) {
	return rtrim(ltrim(s));
}

std::string ltrim(const std::string& s) {
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s) {
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

/*
** Join function for regex string creation
*/

std::string join(std::string& str, const std::string& part, const char *glue) {
    std::string p(part);
    std::string g(glue);

	return str + g + p;
}
