#include "token.hpp"

/* Public methods *************************************************************/

Token::Token(std::string &value, Token::TokenID id, size_t line) : m_value(value), m_line(line), m_id(id)
{}

Token::~Token(void)
{}

/* Getters methods ************************************************************/

std::string     Token::getValue(void) const { return m_value; }
size_t          Token::getLine(void) const { return m_line; }
Token::TokenID  Token::getId(void) const { return m_id; }

/* Compliant methods **********************************************************/

Token::Token(void) {
    pad[0] = '\0';
}

Token::Token(const Token & src) {
	*this = src;
}

Token &Token::operator=(const Token & src) {
    if (this != & src) {
        m_value = src.m_value;
        m_line = src.m_line;
        m_id = src.m_id;
    }
	return *this;
}
