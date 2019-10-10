#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>

using namespace std;

namespace maurya
{
    template <class T>
    class tree_node
    {
        T value;
        vector<T> child;
    };
} // namespace maurya
#endif