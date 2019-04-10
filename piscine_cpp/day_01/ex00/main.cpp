#include "Pony.hpp"


int     main(void) {
    Pony    *heap = Pony::ponyOnTheHeap("Hihan");
    Pony    stack = Pony::ponyOnTheStack("Belle de jour");

    heap->dataPony();
    stack.dataPony();

    delete heap;

    return 0;
}
