#ifndef TRIE_HPP
#define TRIE_HPP

#include <unordered_map>
#include <iostream>

using namespace std;

namespace dasturchi
{
    class trienode                                   // Represents a node in trie data structure
    {
        public:
            char ch;
            unordered_map<char, trienode *> next;
            bool isterminal;

            trienode();                              // trienode constructor
            trienode(char);                          // trienode constructor taking character
            ~trienode();                             // trienode deconstructor

            bool ispresentinnext(char);              // tells if current char is present in next part of it
    };

    class trie                                       // Trie data structure definition
    {
        private:
            trienode root;                           // Root node of trie data structure

        public:
            trie();                                  // trie constructor
            ~trie();                                 // trie deconstructor

            void insert(string &);
    };
} // namespace dasturchi

#endif