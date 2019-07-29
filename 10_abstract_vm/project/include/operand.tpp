#ifndef OPERAND_TPP
# define OPERAND_TPP

# include <string>
# include <stdlib.h>
# include <tgmath.h>
# include <iomanip>

# include <cfenv>
# include <iostream>

# include <virtual_machine.hpp>
# include <operand_factory.hpp>
# include <ioperand.hpp>
# include <exceptions.hpp>

# define EPSILON 10e-20

template<typename T>
class Operand: public IOperand
{

/* Public methods *************************************************************/
public:

    Operand(std::string v, eOperandType type) : m_type(type) {
        double tmp;

        try
        {
            tmp = std::stod(v);
        }
        catch (std::exception)
        {
            throw OverflowError();
        }

        if (tmp < static_cast<double>(std::numeric_limits<T>::lowest())
                || tmp > static_cast<double>(std::numeric_limits<T>::max())) {
            throw OverflowError();
        }
        if (std::fabs(tmp) < static_cast<double>(std::numeric_limits<T>::min())) {
            throw UnderflowError();
        }
        m_repr = v;
        return ;
    }

    virtual ~Operand(void) {}

    virtual int getPrecision(void) const { return m_type; }

    virtual eOperandType getType(void) const { return m_type; }

    virtual IOperand const *operator+(IOperand const &rhs) const {
        int     err = std::fetestexcept(FE_ALL_EXCEPT);
        double  a = std::stod(m_repr);
        double  b = std::stod(rhs.toString());
        int     type = rhs.getPrecision() > m_type ? rhs.getPrecision() : m_type;

        a = a + b;
        if(err & FE_UNDERFLOW) {
            throw UnderflowError();
        }
        if(err & FE_OVERFLOW) {
            throw OverflowError();
        }
        return OperandFactory::get().createOperand(
                static_cast<IOperand::eOperandType>(type), to_string(a));
    }

    virtual IOperand const *operator-(IOperand const &rhs) const {
        int     err = std::fetestexcept(FE_ALL_EXCEPT);
        double  a = std::stod(m_repr);
        double  b = std::stod(rhs.toString());
        int     type = rhs.getPrecision() > m_type ? rhs.getPrecision() : m_type;

        a = a - b;
        if(err & FE_UNDERFLOW) {
            throw UnderflowError();
        }
        if(err & FE_OVERFLOW) {
            throw OverflowError();
        }
        return OperandFactory::get().createOperand(
                static_cast<IOperand::eOperandType>(type), to_string(a));
    }

    virtual IOperand const *operator*(IOperand const &rhs) const {
        int     err = std::fetestexcept(FE_ALL_EXCEPT);
        double  a = std::stod(m_repr);
        double  b = std::stod(rhs.toString());
        int     type = rhs.getPrecision() > m_type ? rhs.getPrecision() : m_type;

        a = a * b;
        if(err & FE_UNDERFLOW) {
            throw UnderflowError();
        }
        if(err & FE_OVERFLOW) {
            throw OverflowError();
        }
        return OperandFactory::get().createOperand(
                static_cast<IOperand::eOperandType>(type), to_string(a));
    }

    virtual IOperand const *operator/(IOperand const &rhs) const {
        int     err = std::fetestexcept(FE_ALL_EXCEPT);
        double  a = std::stod(m_repr);
        double  b = std::stod(rhs.toString());
        int     type = rhs.getPrecision() > m_type ? rhs.getPrecision() : m_type;

        a = a / b;
        if(err & FE_UNDERFLOW) {
            throw UnderflowError();
        }
        if(err & FE_OVERFLOW) {
            throw OverflowError();
        }
        return OperandFactory::get().createOperand(
                static_cast<IOperand::eOperandType>(type), to_string(a));
    }

    virtual IOperand const *operator%(IOperand const &rhs) const {
        int     type;

        type = rhs.getPrecision() > m_type ? rhs.getPrecision() : m_type;
        // Value overflow
        if (type > IOperand::Int32) {
            double a = std::stod(m_repr);
            double b = std::stod(rhs.toString());
            if (b == 0.0) {
                throw ModuloByZero();
            }
            return OperandFactory::get().createOperand(
                    static_cast<IOperand::eOperandType>(type), to_string(std::fmod(a, b)));
        }
        int32_t a = std::stoi(m_repr);
        int32_t b = std::stoi(rhs.toString());
        if (b == 0) {
            throw ModuloByZero();
        }
        return OperandFactory::get().createOperand(
                static_cast<IOperand::eOperandType>(type), to_string(static_cast<double>(a % b)));
    }

    virtual std::string const   &toString(void) const { return m_repr; }

    std::string                 to_string(double value) const {
        std::stringstream   ss;
        std::string         str;

        if (m_type > IOperand::Int32) {
            ss.precision(std::numeric_limits<double>::max_digits10);
            ss << std::fixed << value;
            str = ss.str();
            if (str.find(".") == std::string::npos) {
                str.append(".0");
            }
            else {
                size_t end = str.find_last_not_of('0');
                str = (end == std::string::npos) ? str : str.substr(0, end + 1);
                if (str.back() == '.')
                    str.append("0");
            }
        }
        else
        {
            ss << static_cast<int32_t>(value);
            str = ss.str();
        }
        return str;
    }

/* Member Variables ***********************************************************/
private:
    std::string             m_repr;
    IOperand::eOperandType  m_type;
    char                    pad[4];

/* Compliant methods **********************************************************/
public:
    Operand(const Operand &src) {
        *this = src;
        return;
    }

    Operand &operator=(const Operand<T> &src) {
        if (this != &src) {
            m_repr = src.m_repr;
            m_type = src.m_type;
        }
        return *this;
    }

    Operand(void)
    {}

};

#endif
