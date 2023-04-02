#include <iostream>
#include <string>
#include "Cpp_studies.hpp"

using namespace std;
int main(){
    classObj obj;
    obj.pubintmem=2;
    
    //obj.privintmem=2;//The class members declared as private can be accessed only by the member functions inside the class

    printf("\n%d\n",obj.pubcalculate(obj.pubintmem));
    //cout<<obj.privintmem;
    //printf("\n test");

    return 0;

}