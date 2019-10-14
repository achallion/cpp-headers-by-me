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

    template <class T>
    class tree
    {
        private:
            tree_node<T> *root;
        
        public:
            tree();  // constructor
            ~tree(); // destructor

            tree_node<T> *build(int arr[]);      // build a tree from an array
            void eraseall(tree_node<T> *ptr = NULL); // delete whole tree
    };

} // namespace maurya
#endif