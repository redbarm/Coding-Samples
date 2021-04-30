#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(vector<int> vIn);
void assignFunction(vector<int> vIn, int in);
void pushBackFunction(vector<int> vIn, int in);
void emplaceFunction(vector<int> vIn, int loc, int in);
void emptyFunction(vector<int> vIn);
void eraseVectorElement(vector<int> vIn, int strt, int end);
void usingPopBack(vector<int> vIn);

void printVector(vector<int> vIn)
{
    vector<int>::iterator it;
    for (it = vIn.begin(); it != vIn.end(); ++it)
    {
        cout << *it << " ";
    }
}

void assignFunction(vector<int> vIn, int in)
{
    cout << "\nAssigning " << in << " to vector" << '\n';
    vIn.assign(1, in);
    printVector(vIn);
}

void pushBackFunction(vector<int> vIn, int in)
{
    cout << "\npushBack " << in << " to vector" << '\n';
    vIn.push_back(in);
    printVector(vIn);
}

void emplaceFunction(vector<int> vIn, int loc, int in)
{
    cout << "\nemplace " << in << " to location " << loc << '\n';
    vector<int>::iterator it;
    it = vIn.begin();
    vIn.emplace(it + 1, in);
    printVector(vIn);
}

void emptyFunction(vector<int> vIn)
{
    vIn.clear();
    cout << "\nAfter Clearing the vector\n";
    printVector(vIn);
}

void eraseVectorElement(vector<int> vIn, int strt, int end)
{
    cout << "\nerasing from " << strt << "th element to " << end << '\n';
    vector<int>::iterator it;
    it = vIn.begin();
    // using iterator or vector.begin() as start point gives the same result

    //cout<<"\nerasing using iterator\n";
    //erasing using iterator
    //vIn.erase(it + strt, it + end);

    //erasing with vector.begin
    cout << "\nerasing using vector.begin()\n";
    vIn.erase(vIn.begin() + strt, vIn.begin() + end);
    printVector(vIn);
}

void usingPopBack(vector<int> vIn)
{
    cout << '\n';
    printVector(vIn);
    cout << "\nerasing last element by using pop_back\n";
    vIn.pop_back();
    //vIn.pop_back();
    //vIn.pop_back();
    printVector(vIn);
}
