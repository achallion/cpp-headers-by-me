#ifndef TREE_CPP
#define TREE_CPP

#include "tree.hpp"

namespace kbbk
{

    template <typename T>
    Treenode<T>::Treenode() : data(0)
    {
    }

    template <typename T>
    Treenode<T>::Treenode(T data) : data(data)
    {
    }

    template <typename T>
    Treenode<T>::~Treenode()
    {
        for (Treenode<T> *ch : this->children)
            delete ch;
    }

};

namespace kbbk
{

    template <typename T>
    Tree<T>::Tree() : root(NULL)
    {
    }

    template <typename T>
    Tree<T>::~Tree()
    {
        delete this->root;
    }

    template <typename T>
    Treenode<T> *Tree<T>::inputdfs()
    {
        cout << "\nEnter Parent : ";
        T temp;
        cin >> temp;
        Treenode<T> *ptr = new Treenode<T>(temp);
        cout << "\nEnter Number Of Children of " << temp << " : ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            ptr->children.push_back(inputdfs());

        return ptr;
    }

    template <typename T>
    void Tree<T>::input()
    {
        this->root = inputdfs();
    }

    template <typename T>
    void Tree<T>::printdfs(Treenode<T> *root)
    {
        // base
        if (root == NULL)
        {
            printdfs(this->root);
            return;
        }

        // rec
        cout << "\n"
             << root->data << " : ";
        for (Treenode<T> *ch : root->children)
            cout << ch->data << " ";
        for (Treenode<T> *ch : root->children)
            printdfs(ch);
    }

    template <typename T>
    void Tree<T>::printbfs()
    {
        cout << "\n";
        queue<Treenode<T> *> q;
        q.push(this->root);
        q.push(NULL);
        while (q.size() > 1)
        {
            Treenode<T> *f = q.front();
            q.pop();
            if (f == NULL)
            {
                cout << "\n";
                q.push(NULL);
                continue;
            }
            cout << f->data << " ";
            for (Treenode<T> *ch : f->children)
                q.push(ch);
        }
    }

    template <typename T>
    void Tree<T>::inputlw()
    {
        cout << "\nEnter Root : ";
        Treenode<T> *temp = new Treenode<T>();
        cin >> temp->data;
        queue<Treenode<T> *> q;
        q.push(temp);
        while (!q.empty())
        {
            Treenode<T> *f = q.front();
            q.pop();
            cout << "\nEnter No. of children of " << f->data << " : ";
            int c;
            cin >> c;
            cout << "\nEnter All Children of " << f->data << " : ";
            while (c > 0)
            {
                c--;
                T data;
                cin >> data;
                Treenode<T> *temp = new Treenode<T>(data);
                q.push(temp);
                f->children.push_back(temp);
            }
        }
        this->root = temp;
    }

    template <typename T>
    int Tree<T>::countnodes(Treenode<T> *head)
    {
        // base
        if (head == NULL)
            return countnodes(this->root);

        // rec
        int sum = 1;
        for (Treenode<T> *tn : head->children)
            sum += countnodes(tn);

        return sum;
    }

    template <typename T>
    int Tree<T>::height()
    {
        stack<Treenode<T> *> s;
        s.push(this->root);
        unordered_map<Treenode<T> *, bool> isthere;
        unordered_map<Treenode<T> *, int> ht;

        // insert all elements
        while (!s.empty())
        {
            Treenode<T> *top = s.top();
            bool evalstack = false;
            int nh = 0;
            for (Treenode<T> *ch : top->children)
            {
                nh = max(ht[ch], nh);
                if (!isthere[ch])
                {
                    s.push(ch);
                    evalstack = true;
                }
            }

            if (!evalstack)
            {
                ht[top] = nh + 1;
                isthere[top] = true;
                s.pop();
            }
        }

        return ht[this->root];
    }

};

#endif