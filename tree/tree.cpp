#ifndef TREE_CPP
#define TREE_CPP

#include "tree.hpp"

namespace maurya
{
    // tree_node
    template <class T>
    tree_node<T> :: tree_node(T &val) : value(val)
    {
    }

    template<class T>
    tree_node<T> :: tree_node(T &val, vector<tree_node<T> *> child) : value(val) , children(child)
    {
    }

    template<class T>
    tree_node<T> :: ~tree_node()
    {
    }

//#################################################
    
} // namespace maurya
#endif