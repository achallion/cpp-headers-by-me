#ifndef TRIE_HPP
#define TRIE_HPP

#include <unordered_map>

using namespace std;

namespace kbbk
{

    template <typename T>
    class trienode
    {
    public:
        T data;
        unordered_map<T, trienode<T> *> children;
        bool isterminal;

        trienode();
        ~trienode();
    };

}

namespace kbbk
{
    template <typename T>
    class trie
    {
    protected:
    public:
        trienode<T> *root;

        trie();
        ~trie();

        void insert(T *, int, trienode<T> *root = NULL);
        bool search(T *, int);
    };
}

#include "trie.cpp"

#endif