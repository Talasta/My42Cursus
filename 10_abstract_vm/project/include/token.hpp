#ifndef TOKEN_HPP
# define TOKEN_HPP

#include <string>

# define BM(x) (1 << x)

class Token
{
public:
    enum TokenID
    {
        Inst1 = 0,
        Inst2,  // 1
        FInt,   // 2
        FFloat, // 3
        VInt,   // 4
        VFloat, // 5
        Space,  // 6
        Eol,    // 7
        Error,  // 8
        COUNT
    };

public:
    Token(std::string &value, TokenID id, size_t line);
    ~Token(void);

    std::string getValue(void) const ;
    size_t      getLine(void) const ;
    TokenID     getId(void) const ;

private:
    std::string m_value;
    size_t      m_line;
    TokenID     m_id;
    char        pad[4];

public:
    Token(void);
    Token &operator=(const Token &src);
    Token(const Token &src);

};

#endif
