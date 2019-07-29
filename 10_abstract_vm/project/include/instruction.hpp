#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <string>

class Instruction
{

/* Public methods *************************************************************/
public:
    Instruction(void);
    ~Instruction(void);

    int         compile(void);

    std::string getCmd(void) const;
    std::string getCast(void) const;
    std::string getVal(void) const;

    void        setCmd(std::string val);
    void        setCast(std::string val);
    void        setVal(std::string val);

    void        print(void);

/* Member methods *************************************************************/
private:
    int         need_val(void);

/* Member Variables ***********************************************************/
private:
    std::string     m_cmd;
    std::string     m_val;
    std::string     m_cast;

/* Compliant methods **********************************************************/
public:
    Instruction(const Instruction &src);
    Instruction &operator=(const Instruction &src);

};

#endif
