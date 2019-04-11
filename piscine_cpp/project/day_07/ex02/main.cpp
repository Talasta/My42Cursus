#include <iostream>
#include <string>
#include "Array.tpp"

template<typename T>
void    printArr(Array<T> arr)
{
    std::cout << "Array = { ";
    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i];
        if (i != arr.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << " };" << std::endl;
}

template<typename T>
Array<T>    increment(Array<T> arr)
{
    std::cout << "Increment function called." << std::endl;
    for (unsigned int i = 0; i < arr.size(); ++i)
    {
        arr[i] += 1;
    }
    return arr;
}

int main(void)
{
    std::cout << "Normal instanciation testing :" << std::endl;
    Array<int> arr(10);
    printArr(arr);
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = i * 2;
    }
    printArr(arr);
    arr = increment(arr);
    printArr(arr);
    arr = increment(arr);
    printArr(arr);
    std::cout << std::endl;

    std::cout << "Copy constructor testing :" << std::endl;
    Array<int> arr2(arr);
    for (int i = 0; i < 10; ++i)
    {
        arr2[i] = i * 10;
    }
    printArr(arr2);
    arr2 = increment(arr2);
    printArr(arr2);
    std::cout << std::endl;


    std::cout << "'=' sign testing :" << std::endl;
    Array<int> arr3;
    arr3 = arr2;
    printArr(arr3);
    arr2 = increment(arr2);
    printArr(arr2);
    printArr(arr3);
    std::cout << std::endl;

    std::cout << "+---------------+" << std::endl;
    std::cout << "| Error testing |" << std::endl;
    std::cout << "+---------------+" << std::endl;

    std::cout << "'-1' index testing: Index out of range" << std::endl;
    try
    {
        arr[-1] = 10;
    }
    catch (std::exception& e)
    {
        std::cout << "Error catched: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "'20' index testing: arr[20] = 10;" << std::endl;
    try
    {
        arr[20] = 10;
    }
    catch (std::exception& e)
    {
        std::cout << "Error catched: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Empty array acces testing: empty[0] = 10;" << std::endl;
    try
    {
        Array<char> empty;
        empty[0] = 10;
    }
    catch (std::exception& e)
    {
        std::cout << "Error catched: " << e.what() << std::endl;
    }

    return 0;
}
