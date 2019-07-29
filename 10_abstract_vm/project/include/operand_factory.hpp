#ifndef OPERAND_FACTORY_HPP
# define OPERAND_FACTORY_HPP

#include <string>

#include <ioperand.hpp>

class OperandFactory
{

/* Singleton methods **********************************************************/
public:
    static OperandFactory &get(void);

private:
    OperandFactory();
    OperandFactory(const OperandFactory&);
    OperandFactory& operator=(const OperandFactory&);
    ~OperandFactory();

/* Factory method *************************************************************/
public:
    IOperand const * createOperand(IOperand::eOperandType type,
            std::string const & value) const;

private:
    IOperand const * createInt8(std::string const & value) const;
    IOperand const * createInt16(std::string const & value) const;
    IOperand const * createInt32(std::string const & value) const;
    IOperand const * createFloat(std::string const & value) const;
    IOperand const * createDouble(std::string const & value) const;

};

#endif
