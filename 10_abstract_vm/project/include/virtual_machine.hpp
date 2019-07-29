#ifndef VIRTUAL_MACHINE_HPP
# define VIRTUAL_MACHINE_HPP

# include <deque>
# include <map>

# include <instruction.hpp>
# include <operand.tpp>

/*
** Class description
*/
class VirtualMachine
{
    typedef std::map<std::string, IOperand::eOperandType> OpeMap;
    typedef std::map<std::string, void (VirtualMachine::*)(Instruction const &)> CmdMap;

private:
    static const OpeMap   s_ope;
    static const CmdMap   s_cmd;

/* Public methods *************************************************************/
public:
    VirtualMachine(void);
    ~VirtualMachine(void);

    void    run(std::deque<Instruction> instructions);
    void    info(void);

/* Member methods *************************************************************/
private:
    void    push(Instruction const &instruction);
    void    assert(Instruction const &instruction);
    void    pop(Instruction const &instruction);
    void    dump(Instruction const &instruction);
    void    add(Instruction const &instruction);
    void    sub(Instruction const &instruction);
    void    mul(Instruction const &instruction);
    void    div(Instruction const &instruction);
    void    mod(Instruction const &instruction);
    void    print(Instruction const &instruction);
    void    exit(Instruction const &instruction);

    static OpeMap   create_opemap(void);
    static CmdMap   create_cmdmap(void);

    const IOperand  *top(void);

/* Member Variables ***********************************************************/
private:
    std::deque<const IOperand*>                    m_pile;
    bool                                           m_end;
    char                                           pad[7];

/* Compliant methods **********************************************************/
private:
    VirtualMachine &operator=(const VirtualMachine &src);
    VirtualMachine(const VirtualMachine &src);

};

#endif
