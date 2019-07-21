#ifndef TRIE_CPP
#define TRIE_CPP

#include "trie.hpp"

namespace dasturchi
{
    trienode :: trienode() : ch('\0') , isterminal(false)
    {
    }

    trienode ::trienode(char x) : ch(x), isterminal(false)
    {
    }

    trienode :: ~trienode()
    {
    }

    bool trienode :: ispresentinnext(char x)
    {
        unordered_map<char, trienode *>::iterator end;
        if (next.find(x) == end)
            return false;
        return true;
    }

    trie :: trie()
    {
        trienode();
    }

    trie :: ~trie()
    {
    }

    void trie ::insert(string &str)
    {
        
    }
} // namespace dasturchi

#endif