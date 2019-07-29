#ifndef UTILS_HPP
# define UTILS_HPP

# define ERR_ARGS 1
# define ERR_OPEN 2

# define WHITESPACE " \n\r\t\f\v"

# include <deque>
# include <string>

int         readprog(int ac, char *av[], std::deque<std::string> &data);

std::string error_liner(std::string const &line, std::string const &error);

std::string trim(const std::string &s);
std::string ltrim(const std::string &s);
std::string rtrim(const std::string &s);

std::string join(std::string& str, const std::string& part, const char *glue);

#endif
