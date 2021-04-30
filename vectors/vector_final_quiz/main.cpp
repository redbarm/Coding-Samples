/*Put your code here*/

//#include "main.hpp"
#include "C:\C++Projects\Udacity_c++_course\vectors\vector_final_quiz\mainFunctions.cpp"

int main()
{
    family fm1;
    family* fmptr;
    fmptr=&fm1;
    //createVector(fm1);
    createVectorPtr(fmptr);
    fm1.familyName="Gozu Family";
    //fm1.printFamilyNames();
    printNames(fm1);
    std::cout<<fm1.familyMemberName[1];
    return 0;
}

