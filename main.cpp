#include <iostream>
#include "circularList.h"
#include "circularList.cpp"
using namespace std;

int main()
{
    // cirChain<int> a;
    // a.InsertBack(1);
    // a.InsertBack(2);
    // a.InsertBack(3);

    // cout << a << endl;

    cirChain<int> x(0);
    for (int i = 1; i <= 10; i++)
    {
        x.InsertBack(i);
    }

    cout << x << endl;

    cout << x.expr() << endl;
    return 0;
}