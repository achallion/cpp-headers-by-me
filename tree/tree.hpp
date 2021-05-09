#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

namespace kbbk
{

    template <typename T>
    class Treenode
    {
    public:
        T data;
        vector<Treenode<T> *> children;

        Treenode();
        Treenode(T);
        ~Treenode();
    };

    template <typename T>
    class Tree
    {
        Treenode<T> *inputdfs();

    public:
        Treenode<T> *root;

        Tree();
        ~Tree();

        void input();
        void inputlw();
        int countnodes(Treenode<T> *head = NULL);
        void printdfs(Treenode<T> *root = NULL);
        void printbfs();
        int height();
    };

};

#include "tree.cpp"

#endif