#include <iostream>
#include <deque>

#include "parserlexer.hpp"
#include "utils.hpp"
#include "virtual_machine.hpp"
#include "exceptions.hpp"

int     main(int ac, char *av[])
{
    int                     ret;
    std::deque<std::string> data;
    ParserLexer             pl;
    VirtualMachine          vm;

    if ((ret = readprog(ac, av, data)) < 0)
        return ret;

    pl.process_data(data);
    if (!pl.compiled())
        return -3;
    if (pl.getInstructions().size() == 0)
        return 0;

    try {
        vm.run(pl.getInstructions());
    }
    catch (OperandException &e) {
        std::cout << e.what() << std::endl;
        return -2;
    }
    catch (InstructionException &e) {
        std::cout << e.what() << std::endl;
        return -1;
    }
    return 0;
}
