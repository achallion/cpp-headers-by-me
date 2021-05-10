#ifndef BT_HPP
#define BT_HPP

#include <iostream>
#include <utility>

using namespace std;

namespace kbbk
{
#define max3(x, y, z) max(max((x), (y)), (z))

    template <typename T>
    class btnode
    {
    public:
        T data;
        btnode<T> *left;
        btnode<T> *right;

        btnode();
        btnode(T);
        ~btnode();
    };

    template <typename T>
    class bt
    {
    protected:
        btnode<T> *inputdfs();

    public:
        btnode<T> *root;

        bt();
        ~bt();
        void input();
        void print(btnode<T> *);
        int countnodes(btnode<T> *);
        int height(btnode<T> *);
        pair<int, int> diameter(btnode<T> *);
    };
};

#include "bt.cpp"

#endif