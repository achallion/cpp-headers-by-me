#ifndef TRIE_CPP
#define TRIE_CPP

#include "trie.hpp"

namespace kbbk // trienode
{
    template <typename T>
    trienode<T>::trienode()
    {
        this->data = 0;
        this->isterminal = false;
    }

    template <typename T>
    trienode<T>::~trienode()
    {
        for (pair<T, trienode<T> *> p : this->children)
            delete p.second;
    }

};

namespace kbbk // trie
{
    template <typename T>
    trie<T>::trie()
    {
        this->root = new trienode<T>;
        this->root->isterminal = false;
        this->root->data = 0;
    }

    template <typename T>
    trie<T>::~trie()
    {
        delete this->root;
    }

    template <typename T>
    void trie<T>::insert(T *arr, int n, trienode<T> *root)
    {
        // base

        if (root == NULL)
        {
            insert(arr, n, this->root);
            return;
        }

        if (n == 0)
        {
            root->isterminal = true;
            return;
        }

        // rec
        if (!root->children[*arr])
        {
            trienode<T> *temp = new trienode<T>;
            temp->data = *arr;
            root->children[*arr] = temp;
        }

        insert(arr + 1, n - 1, root->children[*arr]);
    }

    template <typename T>
    bool trie<T>::search(T *arr, int n)
    {
        trienode<T>*ptr = this->root;
        while()
        {
            ptr->
        }
    }

};

#endif