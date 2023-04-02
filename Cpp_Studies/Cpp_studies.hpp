#include <iostream>
#include <string>
using namespace std;

class classObj{
private:
    //string privstringmem;
    int privintmem;
    int privcalculate(int privintmem);
public:
    //string pubstringmem;
    int pubintmem;
    int pubcalculate(int pubintmem);
};

int classObj::privcalculate(int privintmem)
{
    int rslt=2*privintmem;
}

int classObj::pubcalculate (int pubintmem)
{
    privintmem=pubintmem;
    privcalculate(privintmem);
    int rslt=4*pubintmem;
    cout<<privintmem;
    return rslt;
}

