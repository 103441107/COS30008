#pragma once
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include <stdexcept>
using namespace std;
template <typename T>
class List
{
private:
    // auxiliary definition to simplify node usage
    using Node = DoublyLinkedList<T>;
    Node* fRoot;   // the first element in the list
    size_t fCount; // number of elements in the list
public:
    // auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;
    ~List()
    {
        while (fRoot != nullptr)
        {
            if (fRoot != &fRoot->getPrevious())
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious());

                lTemp->isolate();
                delete lTemp;
            }
            else
            {
                delete fRoot;
                break;
            }
        }
    }
    void remove(const T& aElement)
    {
        Node* lNode = fRoot;

        while (lNode != nullptr)
        {
            if (**lNode == aElement)
            {
                break;
            }
            if (lNode != &fRoot->getPrevious())
            {
                lNode = const_cast<Node*>(&lNode->getNext());
            }
            else
            {
                lNode = nullptr;
            }
        }

        // At this point we have either reached the end or found the node.
        if (lNode != nullptr)
        {
            if (fCount != 1)
            {
                if (lNode == fRoot)
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());
                }
            }
            else
            {
                fRoot = nullptr;
            }

            lNode->isolate();
            delete lNode;
            fCount--;
        }
    }

    List() : fRoot(nullptr), fCount(0) // default constructor
    {
    }

    void push_front(const T& aElement) // adds aElement at front
    {
        Node* lNode = new Node(aElement);

        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else
        {
            *fRoot->push_front(*lNode);
            fRoot = lNode;
        }
        fCount++;
    }

    size_t size() const // list size
    {
        return fCount;
    }

    bool isEmpty() const // Is list empty?
    {
        return fCount == 0;
    }

    Iterator begin() const // return a forward iterator
    {
        Iterator it(fRoot);
        return it.begin();
    }

    Iterator end() const // return a forward end iterator
    {
        Iterator it(fRoot);
        return it.end();
    }

    Iterator rbegin() const // return a backwards iterator
    {
        Iterator it(fRoot);
        return it.rbegin();
    }

    Iterator rend() const // return a backwards end iterator
    {
        Iterator it(fRoot);
        return it.rend();
    }

    void push_back(const T& aElement) // adds aElement at back
    {
        Node* lNode = new Node(aElement);

        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else
        {
            const_cast<Node*>(&fRoot->getPrevious())->push_back(*lNode);
        }
        fCount++;
    }

    const T& operator[](size_t aIndex) const // list indexer
    {
        if (aIndex >= fCount)
        {
            throw range_error("Index out of range");
        }

        Node* lNode = fRoot;

        for (size_t i = 0; i < aIndex; i++)
        {
            lNode = const_cast<Node*>(&lNode->getNext());
        }

        return **lNode;
    }

    List(const List& aOtherList) : fRoot(nullptr), fCount(0) // copy constructor
    {
        for (Iterator it = aOtherList.begin(); it != aOtherList.end(); ++it)
        {
            push_back(*it);
        }
    }

    List& operator=(const List& aOtherList) // assignment operator
    {
        size_t s = size();
        for (Iterator it = aOtherList.begin(); it != aOtherList.end(); ++it)
        {
            push_back(*it);
        }
        for (size_t i = 0; i < s; i++)
        {
            remove(this->operator[](i));
        }
        return *this;
    }

    List(List&& aOtherList) : fRoot(nullptr), fCount(0) // move constructor
    {
        fRoot = aOtherList.fRoot;
        fCount = aOtherList.fCount;
        aOtherList.fRoot = nullptr;
        aOtherList.fCount = 0;
    }

    List& operator=(List&& aOtherList) // move assignment operator
    {
        if (this != &aOtherList)
        {
            fRoot = aOtherList.fRoot;
            fCount = aOtherList.fCount;
            aOtherList.fRoot = nullptr;
            aOtherList.fCount = 0;
        }
        return *this;
    }

    void push_front(T&& aElement) // adds aElement at front
    {
        Node* lNode = new Node(move(aElement));

        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else
        {
            *fRoot->push_front(*lNode);
            fRoot = lNode;
        }
        fCount++;
    }

    void push_back(T&& aElement) // adds aElement at back
    {
        Node* lNode = new Node(move(aElement));

        if (fRoot == nullptr)
        {
            fRoot = lNode;
        }
        else
        {
            const_cast<Node*>(&fRoot->getPrevious())->push_back(*lNode);
        }
        fCount++;
    }
};
