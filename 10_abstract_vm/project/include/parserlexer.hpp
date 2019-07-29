#ifndef PARSERLEXER_HPP
# define PARSERLEXER_HPP

# include <deque>
# include <string>
# include <ostream>
# include <sstream>

# include <token.hpp>
# include <instruction.hpp>

# define RE_COM   "[^;]*(;;)|(;).*"

/*
** Struct description
*/
typedef struct
{
    Token::TokenID  id;
    uint32_t        mask;
    std::string     expr;
    std::string     msg;
    uint32_t        auth;
    char            pad[4];
}                   rule;

extern const rule  g_rules[9];
/*
** Class description
*/
class ParserLexer
{

/* Public methods *************************************************************/
public:

    ParserLexer(void);
    ~ParserLexer(void);

    // Main function
    void        process_data(std::deque<std::string> &data);
    std::deque<Instruction> getInstructions(void);
    bool        compiled(void);

/* Member methods *************************************************************/
private:
    int         tokenize(std::string const &data, size_t nbline);
    int         parse(std::deque<std::string> const &data);
    void        print_errors(void);

    // Parser functions
    uint32_t    use_token(size_t nbline, std::string const &line, Token &token, rule &status, uint32_t mask);
    uint32_t    evaluate_operation(Token &token, rule &status, uint32_t mask);
    void        update_instruction(Token &token);
    Token       &clear_line(uint32_t mask, Token &token);
    uint32_t    end_of_line(size_t nbline, std::string const &line, uint32_t mask);
    void        parsingerror(size_t pos, std::string const &data, std::string const &error, std::string const &msg, char const *xpt);

    // Lexer functions
    int         clean_comments(std::string &line);
    std::string regex_builder(void);
    void        line_to_tokens(std::string line, size_t nbline, std::string const &data);
    void        push_token(std::string value, size_t id, size_t nbline);
    void        syntaxerror(size_t pos, std::string const &line, std::string  const &error, char const *xpt);

/* Member Variables ***********************************************************/
private:
    std::ostringstream      m_error;
    std::deque<Token>       m_token;
    std::deque<Instruction> m_instructions;
    Instruction             m_instruction;
    bool                    m_err;
    char                    pad[7];

/* Compliant methods **********************************************************/
private:
    ParserLexer &operator=(const ParserLexer &src);
    ParserLexer(const ParserLexer &src);

};

#endif
