#pragma once

#include <stack>

#include "BNode.h"

template <typename T>
class BinarySearchTreeIterator
{
private:
    const BNode<T> *fBNodeTree;          // binary search tree
    std::stack<const BNode<T> *> fStack; // DFS traversal stack

public:
    using Iterator = BinarySearchTreeIterator<T>;

    BinarySearchTreeIterator(const BNode<T> *aBNodeTree) : fBNodeTree(aBNodeTree)
    {
        if (!fBNodeTree->empty())
        {
            fStack.push(fBNodeTree);

            while (!fStack.top()->left->empty())
            {
                fStack.push(fStack.top()->left);
            }
        }
    }

    const T &operator*() const
    {
        return fStack.top()->key;
    }

    Iterator &operator++()
    {
        if (fStack.empty())
        {
            fStack.push(&BNode<T>::NIL);
        }
        else
        {
            const BNode<T> *lNode = fStack.top();
            fStack.pop();
            if (!lNode->right->empty())
            {
                fStack.push(lNode->right);

                while (!fStack.top()->left->empty())
                {
                    fStack.push(fStack.top()->left);
                }
            }
        }
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const Iterator &aOther) const
    {
        return fStack == aOther.fStack;
    }

    bool operator!=(const Iterator &aOther) const
    {
        return !(*this == aOther);
    }

    Iterator begin() const
    {
        return Iterator(fBNodeTree);
    }

    Iterator end() const
    {
        return Iterator(BNode<T>::NIL);
    }
};