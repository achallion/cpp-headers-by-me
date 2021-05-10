#ifndef BT_CPP
#define BT_CPP

#include "bt.hpp"

namespace kbbk
{
    template <typename T>
    btnode<T>::btnode() : data(0), left(NULL), right(NULL)
    {
    }

    template <typename T>
    btnode<T>::btnode(T data) : data(data), left(NULL), right(NULL)
    {
    }

    template <typename T>
    btnode<T>::~btnode()
    {
        delete left;
        delete right;
    }
};

namespace kbbk
{
    template <typename T>
    bt<T>::bt()
    {
        root = NULL;
    }

    template <typename T>
    bt<T>::~bt()
    {
        delete root;
    }

    template <typename T>
    void bt<T>::input()
    {
        this->root = this->inputdfs();
    }

    template <typename T>
    btnode<T> *bt<T>::inputdfs()
    {
        T temp;
        cin >> temp;
        if (temp == 0)
            return NULL;

        btnode<T> *node = new btnode<T>(temp);
        node->left = inputdfs();
        node->right = inputdfs();
        return node;
    }

    template <typename T>
    void bt<T>::print(btnode<T> *head)
    {
        if (head == NULL)
        {
            return;
        }

        cout << head->data << " : ";
        if (head->left != NULL)
            cout << head->left->data;
        if (head->right != NULL)
            cout << " , " << head->right->data;
        cout << "\n";
        this->print(head->left);
        this->print(head->right);
    }

    template <typename T>
    int bt<T>::countnodes(btnode<T> *head)
    {
        // base
        if (head == NULL)
            return 0;

        // rec
        return countnodes(head->left) + countnodes(head->right) + 1;
    }

    template <typename T>
    int bt<T>::height(btnode<T> *root)
    {
        if (root == NULL)
            return 0;

        // rec
        int l = height(root->left);
        int r = height(root->right);
        return max(l, r) + 1;
    }

    template <typename T>
    pair<int, int> bt<T>::diameter(btnode<T> *root)
    {
        // base
        if (root == NULL)
        {
            return make_pair<int, int>(0, 0);
        }

        // rec
        pair<int, int> l = this->diameter(root->left);
        pair<int, int> r = this->diameter(root->right);
        int d1, d2, d3;
        d1 = l.first + r.first;
        d2 = l.second;
        d3 = r.second;
        int d = max<int>(d2, d3);
        d = max(d1, d);
        int h = max<int>(l.first, r.first) + 1;
        return make_pair(h, d);
    }
};

#endif