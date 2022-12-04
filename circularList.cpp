#include <iostream>
#include "circularList.h"
using namespace std;

template <class T>
cirChain<T>::cirChain(T e)
{
    cirNode *head = new cirNode(e);
    first = last = head;
    last->next = first;
}

template <class T>
cirChain<T>::~cirChain()
{
    cirNode *cur = first;
    last->next = 0;
    while (cur != 0)
    {
        cirNode *temp = cur;
        cur = cur->next;
        delete temp;
    }
}

template <class T>
void cirChain<T>::InsertBack(const T e)
{ // Insert a cirNode in end of the list
    last->next = new cirNode(e);
    last = last->next;
    last->next = first;
}

template <class T>
void cirChain<T>::DeleteFront()
{ // delete a cirNode in front of the list
    cirNode *temp = first->next;
    if (temp == last)
    { // the list only have one cirNode
        first->next = first;
        last = first;
    }
    first->next = temp->next;
    delete temp;
}

template <class T>
int cirChain<T>::expr()
{
    int sum = 0;
    for (typename cirChain<T>::cirChainIterator i = begin(); i != end(); i++)
    {
        int count = 0;
        for (typename cirChain<T>::cirChainIterator j = i; j != end(); j++)
        {
            if (count == 5)
            {
                sum += (*i) * (*j);
                break;
            }
            count++;
        }
    }
    return sum;
}

template <class T>
ostream &operator<<(ostream &os, cirChain<T> &s)
{
    os << "-> ";
    for (typename cirChain<T>::cirChainIterator i = s.begin(); i != s.end(); i++)
    {
        os << *i << " -> ";
    }
    return os;
}