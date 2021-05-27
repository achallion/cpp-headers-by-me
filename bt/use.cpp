#include <iostream>
#include "bt.hpp"

using namespace std;
using namespace kbbk;

int main()
{
    freopen("input.txt", "r", stdin);
    bt<int> t;
    t.input();
    cout << t.diameter(t.root).second;

    return 0;
}