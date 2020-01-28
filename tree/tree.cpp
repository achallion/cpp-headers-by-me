#ifndef TREE_CPP
#define TREE_CPP

#include "tree.hpp"

namespace maurya
{
    // tree_node
    int temp = 444;
    template <class T>
    tree_node<T>::tree_node(T &val) : value(val)
    {
    }

    template <class T>
    tree_node<T>::tree_node(T &val, vector<tree_node<T> *> child) : value(val), children(child)
    {
    }

    template <class T>
    tree_node<T>::~tree_node()
    {
    }

    //#################################################



    // tree

    template <class T>
    tree<T>::tree() : root(NULL)
    {
    }

    template <class T>
    tree<T>::~tree()
    {
        eraseall();
    }

    template <class T>
    tree_node<T> *tree<T>::build(int arr[])
    {
        static int i = 0;
        bool isroot = false;
        if (i == 0)
            isroot = true;

        // base case
        if(arr[i] == -1)
        {
            if(isroot == true)
                root = NULL;
            return NULL;
        }

        // rec case
        // make a tree node and insert val
        tree_node<T> *ptr = new tree_node<T>(arr[i]);

        // build other tree nodes and insert their address in vector
        i++;
        while (arr[i] != -1)
        {
            tree_node<T> *temp = build(arr);
            if(temp != NULL)
                ptr->children.push_back(temp);
            i++;
        }
        if(isroot == true)
            root = ptr;
        return ptr;
    }

    template<class T>
    void tree<T>::eraseall(tree_node<T> *ptr )
    {
        if(ptr == NULL && root != NULL)
        {
            eraseall(root);
            return;
        }

        if(ptr == NULL)
        {
            return;
        }

        int s = ptr->children.size();
        for (int i = 0; i < s; i++)
        {
            eraseall(ptr->children[i]);
            delete (ptr->children[i]);
        }

        if(ptr == root)
        {
            delete ptr;
            root = NULL;
        }
    }

    //#################################################
    
} // namespace maurya
#endif
