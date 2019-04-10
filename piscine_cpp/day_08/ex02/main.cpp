#include "mutantstack.hpp"
#include <iostream>

bool compareIters(MutantStack<int>::iterator a, MutantStack<int>::iterator b)
{
    std::cout << *a << " and " << *b;
    if (a == b)
    {
        std::cout << " are similar." << std::endl;
        return true;
    }
    else
    {
        std::cout << " are different." << std::endl;
        return false;
    }
}

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    for (int i = 0; i < 30000; ++i)
    {
        mstack.push(i);
    }
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;
    for (int i = 0; i < 30000; ++i)
    {
        mstack.pop();
    }
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;


    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);


    MutantStack<int>::iterator a(mstack.begin());
    MutantStack<int>::iterator b = mstack.begin();
    a++;
    compareIters(a, b);

    return 0;
}
