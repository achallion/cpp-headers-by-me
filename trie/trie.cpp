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
        empty();
    }

    bool trienode :: ispresentinnext(char x)
    {
        unordered_map<char, trienode *>::iterator end;
        end = next.end();
        if (next.find(x) == end)
            return false;
        return true;
    }

    trienode* trienode :: insert(char x)
    {
        if(ispresentinnext(x))
            return next[x];
        trienode *temp = new trienode(x);
        next[x] = temp;
        return temp;
    }

    void trienode :: empty()
    {
        unordered_map<char, trienode *>::iterator it, end;
        end = next.end();
        for (it = next.begin(); it != end; it++)
        {
            it->second->empty();
            delete it->second;
        }
        cout << ch << " ";
        return;
    }

    trie :: trie()
    {
    }

    trie :: ~trie()
    {
    }

    void trie :: insert(string &str)
    {
        trienode *ptr = &root;
        int n = str.size();
        char x = '\0';
        for (int i = 0; i < n; i++)
        {
            x = str[i];
            ptr = ptr->insert(x);
        }
        ptr->isterminal = true;
    }

    bool trie :: search(string str)
    {
        trienode *ptr = &root;
        int n = str.size();
        char x = '\0';
        for (int i = 0; i < n; i++)
        {
            x = str[i];
            if (!ptr->ispresentinnext(x))
            {
               return false;
            }
            ptr = ptr->next[x];
        }
        return ptr->isterminal;
    }
} // namespace dasturchi

#endif