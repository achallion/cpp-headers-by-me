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
        if(this == NULL)
            return;
        unordered_map<char, trienode *>::iterator it, end;
        end = next.end();
        for (it = next.begin(); it != end; it++)
        {
            delete it->second;
        }
    }

    trie :: trie()
    {
    }

    trie :: ~trie()
    {
        //empty();
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

    void trie :: empty(trienode *head)
    {
        if(head == NULL)
            head = &root;
        if(head->next.size() == 0)
            return;
        unordered_map<char, trienode *>::iterator it, end;
        end = head->next.end();
        for (it = head->next.begin(); it != end; it++)
        {
            empty(it->second);
        }
        head->empty();
        return;
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
               }ptr = ptr->next[x];
        }
        return ptr->isterminal;
    }
} // namespace dasturchi

#endif