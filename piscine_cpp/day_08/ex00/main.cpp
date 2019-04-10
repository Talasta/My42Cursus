#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <deque>
#include <forward_list>

int main()
{
    std::list<int> list;
    std::vector<int> vect;
    std::array<int, 10> arr;
    std::deque<int> deq;
    std::forward_list<int> flist;

    for (int i = 0; i < 10; i++)
    {
        list.push_back(i);
        vect.push_back(12 * i);
        arr[i] = (i);
        deq.push_back(i);
        flist.push_front(9 - i);
    }

    try
    {
        std::cout << easyfind(list, 3) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }

    try
    {
        std::cout << easyfind(list, 42) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }

    try
    {
        std::cout << easyfind(vect, 0) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }

    try
    {
        std::cout << easyfind(vect, 13) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }

    try
    {
        std::cout << easyfind(arr, 7) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }

    try
    {
        std::cout << easyfind(deq, 8) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }

    try
    {
        std::cout << easyfind(flist, 10) << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }
    return 0;
}
