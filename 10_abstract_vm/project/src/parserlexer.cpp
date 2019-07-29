#include <iostream>
#include <regex>

#include "color.hpp"
#include "utils.hpp"
#include "parserlexer.hpp"
#include "exceptions.hpp"

/*
** BM(4) => 10000
** BM(1) => 00010
**     | => 10010
*/

const rule  g_rules[] = {
    { Token::Inst1, BM(Token::Space), "(assert|push)", "require type definition : int8, int10, int32, float or double.", 0, "" },
    { Token::Inst2, BM(Token::Space) | BM(Token::Eol), "(pop|dump|add|sub|mul|div|mod|print|exit)", "shouldn't be followed by any expression.", 0, "" },
    { Token::FInt, BM(Token::VInt), "(int8|int16|int32)", "require int value : ([-]?[0-9]+).", BM(Token::Inst1), "" },
    { Token::FFloat, BM(Token::VFloat), "(float|double)", "require float value : ([-]?[0-9]+.[0-9]+).", BM(Token::Inst1), "" },
    { Token::VInt, BM(Token::Space) | BM(Token::Eol),"\\(([-]?[0-9]+)\\)", "shouldn't be followed by any expression.", BM(Token::Inst1) | BM(Token::FInt), "" },
    { Token::VFloat, BM(Token::Space) | BM(Token::Eol), "\\(([-]?[0-9]+\\.[0-9]+)\\)", "shouldn't be followed by any expression.", BM(Token::Inst1) | BM(Token::FFloat), "" },
    { Token::Space, BM(Token::Eol) | BM(Token::Space) | BM(Token::FInt) | BM(Token::FFloat), "([ \t]+)", "bad expression.", 0, "" },
    { Token::Eol, BM(Token::Space) | BM(Token::Eol) | BM(Token::Inst1) | BM(Token::Inst2), "(\n)", "should start with the following expressions : assert, push, pop, dump, add, sub, mul, div, mod, print or exit.", 0, "" },
    { Token::Error, 0, "([^ \n\t]+)", "bad expression.", 0, "" }
};

/* Public methods *************************************************************/

ParserLexer::ParserLexer(void) : m_err(false)
{}

ParserLexer::~ParserLexer(void) {
    pad[0] = '\0';
    m_token.clear();
    m_instructions.clear();
}

void        ParserLexer::process_data(std::deque<std::string> &data) {
    std::deque<std::string>::iterator iter(data.begin()), end(data.end());
    size_t  nbline = 1;
    int     ret;

    // Lexer Part
    // Loop over every lines of the file
    while (iter != end) {
        if (!tokenize(*iter, nbline))
            break;
        iter++;
        nbline++;
    }
    // Parser Part
    if (!m_err)
        ret = parse(data);
    if (m_err) {
        m_instructions.clear();
        print_errors();
    }
    // Delete the end of data deque
    while (data.size() > 0)
        data.pop_back();
    return ;
}

bool        ParserLexer::compiled(void) { return !m_err; }

std::deque<Instruction> ParserLexer::getInstructions(void) { return m_instructions; }

/* Member methods *************************************************************/

/*
** @utils for Parser
*/
int         ParserLexer::parse(std::deque<std::string> const &data) {
    uint32_t    mask = 0;
    Token       token;
    rule        status(g_rules[7]);
    std::string line;
    size_t      nbline = 0;

    while (m_token.size() > 0) {
        // Update the line if we are on a new line
        token = m_token.front();
        if (nbline != token.getLine()) {
            nbline = token.getLine();
            line = data[nbline - 1];
            line.pop_back();
        }

        mask = use_token(nbline, line, token, status, mask);
        token = clear_line(mask, token);

        // New line
            // Evaluate if expression is good and build instruction
        if (token.getId() == Token::Eol)
            mask = end_of_line(nbline, line, mask);
        status = g_rules[token.getId()];
        m_token.pop_front();
    }
    if (mask &= 0x80000000)
        m_err = true;
    return 0;
}

uint32_t    ParserLexer::end_of_line(size_t nbline, std::string const &line, uint32_t mask) {
    try
    {
        if (!(mask & 0x80000000) && m_instruction.compile())
            m_instructions.push_back(m_instruction);
    }
    catch (UnknownInstruction &e)
    {
        parsingerror(nbline, line, "\n", "cannot compile.", e.what());
        mask |= 0x80000000;
    }
    m_instruction = Instruction();
    mask &= 0x80000000;
    return mask;
}

uint32_t    ParserLexer::use_token(size_t nbline, std::string const &line, Token &token, rule &status, uint32_t mask) {
    try
    {
        mask = evaluate_operation(token, status, mask);
        update_instruction(token);
    }
    catch (SyntaxError &e)
	{
        parsingerror(nbline, line, token.getValue(), status.msg, e.what());
        mask |= 0xC0000000;
        mask |= 0x80000000;
    }
    return mask;
}

void        ParserLexer::update_instruction(Token &token) {
    if (token.getId() <= Token::Inst2)
        m_instruction.setCmd(token.getValue());
    else if (token.getId() <= Token::FFloat)
        m_instruction.setCast(token.getValue());
    else if (token.getId() <= Token::VFloat)
        m_instruction.setVal(token.getValue());
}

uint32_t    ParserLexer::evaluate_operation(Token &token, rule &status, uint32_t mask) {
    uint32_t    tmp(g_rules[token.getId()].auth);

    if (tmp & ~(mask) || (token.getId() < Token::Space
            && !(status.mask & BM(token.getId()))))
    {
        throw SyntaxError();
    }
    mask |= BM(token.getId());
    return mask;
}

Token       &ParserLexer::clear_line(uint32_t mask, Token &token) {
    if (mask & 0x40000000) {
        while (token.getId() != Token::Eol) {
            m_token.pop_front();
            token = m_token.front();
        }
    }
    return token;
}

void        ParserLexer::parsingerror(size_t pos, std::string const &data, std::string const &error, std::string const &msg, char const *xpt) {
    m_error << COLOR_WHITE << "line " << pos << ": ";
    m_error << COLOR_RED << xpt << ": " << COLOR_WHITE;
    m_error << msg << COLOR_END << std::endl;
    m_error << data << std::endl;
    m_error << COLOR_GREEN << error_liner(data, error);
    m_error << COLOR_END << std::endl << std::endl;
}

void        ParserLexer::print_errors(void) {
    std::string     out;

    out = m_error.str();
    std::cout << out;
}

/*
** @utils for Lexer
*/
int         ParserLexer::tokenize(std::string const &data, size_t nbline) {
    int         ret = 0;
    std::string line(data);

    ret = clean_comments(line);
    line_to_tokens(line, nbline, data);
    return ret;
}

int         ParserLexer::clean_comments(std::string &line) {
    std::regex re(RE_COM);
    std::sregex_iterator next(line.begin(), line.end(), re);
    std::sregex_iterator end;
    std::smatch match;
    int ret = 1;

    if (next != end) {
        match = *next;
        // Check if it is an end of file `;;`
        if (!match[1].str().empty())
            ret = 0;
        // Split on comment char to keep only the needed part
        line = line.substr(0, line.find_first_of(";")) + "\n";
    }
    return ret;
}

std::string ParserLexer::regex_builder(void) {
    std::string str;

    str = g_rules[0].expr;
    for (int i = 1 ; i < Token::COUNT ; i++)
        str = join(str, g_rules[i].expr, "|");
    return str;
}

void        ParserLexer::line_to_tokens(std::string line, size_t nbline, std::string const &data) {
    std::regex re(regex_builder());
    std::sregex_iterator next(line.begin(), line.end(), re);
    std::sregex_iterator end;
    std::smatch match;

    while (next != end) {
        match = *next;
        for (size_t index = 1; index < match.size(); ++index ) {
            if (!match[index].str().empty()) {
                try
                {
                    push_token(match[index].str(), index - 1, nbline);
                }
                catch (LexicalError &e)
                {
                    syntaxerror(nbline, data, match[index].str(), e.what());
                }
            }
        }
        next++;
    }
}

void        ParserLexer::push_token(std::string value, size_t id, size_t nbline) {
    Token   token(value, static_cast<Token::TokenID>(id), nbline);

    if (token.getId() == Token::Error) {
        m_err = true;
        throw LexicalError();
    }
    m_token.push_back(token);
    return ;
}

void        ParserLexer::syntaxerror(size_t pos, std::string const &data, std::string const &error, char const *xpt) {
    std::string line(data);

    line.pop_back();
    m_error << COLOR_WHITE << "line " << pos << ": ";
    m_error << COLOR_RED << xpt << ": " << COLOR_WHITE;
    m_error << "bad syntax, doesn't match any expressions.";
    m_error << COLOR_END << std::endl;
    m_error << line << std::endl;
    m_error << COLOR_GREEN << error_liner(line, error);
    m_error << COLOR_END << std::endl << std::endl;
}

/* Compliant methods **********************************************************/

ParserLexer::ParserLexer(const ParserLexer &src) {
	*this = src;
	return;
}

ParserLexer &ParserLexer::operator=(const ParserLexer &src)
{

    if (this != &src)
    m_token = src.m_token;
	return *this;
}
