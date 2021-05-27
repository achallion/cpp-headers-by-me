#include <iostream>
#include "trie.hpp"
#include <string>

using namespace std;
using namespace kbbk;

int main()
{
    trie<char> t;
    string s;
    cin >> s;
    char *carr = &s[0];
    t.insert(carr, s.size());
    return 0;
}