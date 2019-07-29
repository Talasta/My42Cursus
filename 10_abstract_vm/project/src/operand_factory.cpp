
#include "operand_factory.hpp"
#include "operand.tpp"

/* Singleton methods **********************************************************/

OperandFactory::OperandFactory(void)
{}

OperandFactory::~OperandFactory(void)
{}

OperandFactory &OperandFactory::get() {
    static OperandFactory inst;
    return inst;
}

/* Factory method *************************************************************/

IOperand const * OperandFactory::createOperand(IOperand::eOperandType type, std::string const & value) const {
    typedef IOperand const *(OperandFactory::*func)(std::string const &) const;
    func    builders[IOperand::COUNT] = {
        &OperandFactory::createInt8,
        &OperandFactory::createInt16,
        &OperandFactory::createInt32,
        &OperandFactory::createFloat,
		&OperandFactory::createDouble
	};

    return (OperandFactory::get().*builders[type])(value);
}


IOperand const * OperandFactory::createInt8(std::string const & value) const {
    Operand<int8_t> *operand = new Operand<int8_t>(value, IOperand::Int8);
    return reinterpret_cast<IOperand*>(operand);
}

IOperand const * OperandFactory::createInt16(std::string const & value) const {
    Operand<int16_t> *operand = new Operand<int16_t>(value, IOperand::Int16);
    return reinterpret_cast<IOperand*>(operand);
}

IOperand const * OperandFactory::createInt32(std::string const & value) const {
    Operand<int32_t> *operand = new Operand<int32_t>(value, IOperand::Int32);
    return reinterpret_cast<IOperand*>(operand);
}

IOperand const * OperandFactory::createFloat(std::string const & value) const {
    Operand<float> *operand = new Operand<float>(value, IOperand::Float);
    return reinterpret_cast<IOperand*>(operand);
}

IOperand const * OperandFactory::createDouble(std::string const & value) const {
    Operand<double> *operand = new Operand<double>(value, IOperand::Double);
    return reinterpret_cast<IOperand*>(operand);
}
