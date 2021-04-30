#include "C:\C++Projects\Udacity_c++_course\vectors\vector_quiz_2\main.h"

int main()
{
    vector<int> vInts;
    vInts.assign(10, 5);
    printVector(vInts);
    assignFunction(vInts, 1);
    pushBackFunction(vInts, 2);
    emplaceFunction(vInts, 1, 3);
    //emptyFunction(vInts);
    eraseVectorElement(vInts, 3, 5);
    usingPopBack(vInts);

    int i = 10;
    int j = i++;
    cout<<"i="<<i<<" j="<<j;

}
