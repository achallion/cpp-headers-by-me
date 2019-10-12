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
        public:
        
            T value;
            vector<tree_node<T> *> children;

            tree_node(T &val);  // constructor
            tree_node(T &val, vector<tree_node<T> *> children); // constructor
            ~tree_node();  // destructor

            
    };

} // namespace maurya
#endif