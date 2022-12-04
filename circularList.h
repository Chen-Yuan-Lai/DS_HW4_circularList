#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
using namespace std;

template <class T>
class cirChain
{
    class cirNode;

public:
    cirChain(T e);
    ~cirChain();
    // insert q cirNode in front of the list
    void InsertBack(const T e);
    // delte a cirNode in end of the list
    void DeleteFront();

    // Exercise 4 of Chapter 4.3
    int expr();

    // Forward declaration
    class cirChainIterator;
    // root of linkedlist wrapped in Iterator type
    cirChainIterator begin() const { return cirChainIterator(first->next); }
    // end of linkedList wrapped in Iterator type
    cirChainIterator end() const { return cirChainIterator(first); }

    template <typename U>
    friend ostream &operator<<(ostream &os, cirChain<U> &s);

    class cirChainIterator
    {
    public:
        // contructor
        cirChainIterator(cirNode *startcirNode = 0) : current(startcirNode){};
        // deferencing operators
        T &operator*() const { return current->data; }
        T *operator->() const { return &current->data; }

        // increment
        cirChainIterator &operator++() // preincrement
        {
            current = current->next;
            return *this;
        }
        cirChainIterator operator++(int) // postincrement
        {
            cirChainIterator old = *this;
            current = current->next;
            return old;
        }
        // equality testing
        bool operator!=(const cirChainIterator right) const
        {
            return current != right.current;
        }
        bool operator==(const cirChainIterator right) const
        {
            return current == right.current;
        }

    private:
        cirNode *current;
    };

private:
    class cirNode
    { // nested class for cirNode
    public:
        // 0 is the defult value for element and next
        cirNode(T element = 0) : data(element), next(0){};
        T data;
        cirNode *next;
    };
    cirNode *first;
    cirNode *last;
};

#endif