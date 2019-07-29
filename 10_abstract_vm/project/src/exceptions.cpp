#include "exceptions.hpp"

#define WHAT(class, msg) \
    const char* class::what() const throw() \
    { \
        return msg; \
    }

WHAT(Exception, "an error has occured")

WHAT(ParsingException, "parsing error")
WHAT(SyntaxError, "syntax error")
WHAT(LexicalError, "lexical error")
WHAT(UnknownInstruction, "instruction doesn't exist")

WHAT(OperandException, "abort ./avm\noperand exception: operand error")
WHAT(OverflowError, "abort ./avm\noperand exception: overflow occured")
WHAT(UnderflowError, "abort ./avm\noperand exception: underflow occured")

WHAT(InstructionException, "avm.++prog: terminating with exception: instruction error")
WHAT(PopEmptyStack, "avm.++prog: terminating with exception: pop on empty stack")
WHAT(DivisionByZero, "avm.++prog: terminating with exception: division by zero")
WHAT(ModuloByZero, "avm.++prog: terminating with exception: modulo by zero")
WHAT(NoExitInstruction, "avm.++prog: terminating with exception: no exit instruction")
WHAT(AssertError, "avm.++prog: terminating with exception: assertion failed")
WHAT(StackSizeError, "avm.++prog: terminating with exception: not enought item in stack")
WHAT(TypeError, "avm.++prog: terminating with exception: wrong type")
