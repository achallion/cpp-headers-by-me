#ifndef BST_CPP
#define BST_CPP

#include "bst.hpp"

namespace kbbk
{
    template <typename T>
    bst<T>::bst()
    {
        this->bt.reserve(2);
        this->bt.push_back(0);
        this->bt.push_back(-1);
    }

    template <typename T>
    bst<T>::bst(int s)
    {
        this->bt.reserve(s + 1);
        this->bt.push_back(0);
        this->bt.push_back(-1);
    }

    template <typename T>
    bst<T>::~bst()
    {
        this->bt.clear();
    }

    template <typename T>
    void bst<T>::insert(T element)
    {
        int i = 1;
        while (this->bt[i] != -1)
        {
            if (element <= this->bt[i])
                i <<= 1;
            else
                i = (i << 1) + 1;
        }

        int rs = pow2(log2(i) + 2);
        if (this->bt.size() < rs)
            this->bt.resize(rs);

        this->bt[i] = element;
        this->bt[i << 1] = -1;
        this->bt[(i << 1) + 1] = -1;
        this->bt[0]++;
    }

    template <typename T>
    int bst<T>::search(T element)
    {
        int i = 1;
        while (this->bt[i] != -1)
        {
            if (this->bt[i] == element)
                break;

            if (element < this->bt[i])
                i <<= 1;
            else
                i = (i << 1) + 1;
        }
        return i;
    }

    template <typename T>
    void bst<T>::from_sortedarray(T *arr, int n)
    {
        this->bt.resize(4);
        this->bt[0] = n;
        this->bt[1] = -1;
        this->cbstfsa(arr, 0, n - 1, 1);
    }

    template <typename T>
    void bst<T>::cbstfsa(int *a, int s, int e, int i)
    {
        // base
        if (s > e)
            return;

        // rec
        int mid = (s + e) >> 1;
        int rs = pow2(log2(i) + 2);
        if (this->bt.size() < rs)
            this->bt.resize(rs);
        this->bt[i] = a[mid];
        this->bt[i << 1] = -1;
        this->bt[(i << 1) + 1] = -1;
        cbstfsa(a, s, mid - 1, i << 1);
        cbstfsa(a, mid + 1, e, (i << 1) + 1);
    }

    template <typename T>
    void bst<T>::inrange(int l, int r, int pos)
    {
        T root = this->bt[pos];
        // base
        if (root == -1)
            return;

        // rec
        if (root >= l && root <= r)
            cout << root << " ";

        if (root <= r)
            this->inrange(l, r, (pos << 1) + 1);
        if (root >= l)
            this->inrange(l, r, pos << 1);
    }

    template <typename T>
    void bst<T>::printlevelwise()
    {
        queue<T> q;
        q.push(1);
        q.push(-1);
        while (q.size() > 1)
        {
            T f = q.front();
            q.pop();
            if (f == -1)
            {
                q.push(-1);
                cout << "\n";
                continue;
            }
            if (this->bt[f << 1] != -1)
                q.push(f << 1);
            if (this->bt[(f << 1) + 1] != -1)
                q.push((f << 1) + 1);
            cout << this->bt[f] << "\t";
        }
    }

};

#endif