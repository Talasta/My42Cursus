#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <string>

# define DECLARE(name, parent) \
    class name: public parent \
    { \
    public: \
        virtual const char* what() const throw(); \
    };

DECLARE(Exception, std::exception)

// • The assembly program includes one or several lexical errors or syntactic errors.
// • An instruction is unknown
DECLARE(ParsingException, Exception)
DECLARE(SyntaxError, ParsingException)
DECLARE(LexicalError, ParsingException)
DECLARE(UnknownInstruction, ParsingException)

// • Overflow on a value
// • Underflow on a value
DECLARE(OperandException, Exception)
DECLARE(OverflowError, OperandException)
DECLARE(UnderflowError, OperandException)

// • Instruction pop on an empty stack
// • Division/modulo by 0
// • The program doesn’t have an exit instruction
// • An assert instruction is not true
// • The stack is composed of strictly less that two values when an arithmetic instruction
// is executed.
DECLARE(InstructionException, Exception)
DECLARE(PopEmptyStack, InstructionException)
DECLARE(DivisionByZero, InstructionException)
DECLARE(ModuloByZero, InstructionException)
DECLARE(NoExitInstruction, InstructionException)
DECLARE(AssertError, InstructionException)
DECLARE(StackSizeError, InstructionException)
DECLARE(TypeError, InstructionException)

#endif
