#include <iostream>
#include "bst.hpp"

int main()
{
    std::cout << "what ";
    return 0;


    bst<int> x;
    x.insert(2);
    x.insert(3);
    for (auto& it : x)
    {
        std::cout << it << " ";
    }
    return 0;
}