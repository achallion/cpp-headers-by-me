#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

#define sqr(x) ((x) * (x))

int pow2(int x)
{
    return 1 << x;
}

namespace kbbk
{

    template <typename T>
    class bst
    {

    protected:
        void cbstfsa(int *, int, int, int); // create bst from sorted array

    public:
        vector<T> bt;

        bst();
        bst(int);
        ~bst();

        void insert(T);
        int search(T);
        void from_sortedarray(T *, int);
        void inrange(int, int, int pos = 1);
        void printlevelwise();
    };
};

#include "bst.cpp"

#endif