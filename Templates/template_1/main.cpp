#include "main.h"
#include <string>

int main()
{
    int i1 = 10;
    int i2 = 20;
    float f1 = 4.56;
    float f2 = 6.788;
    std::string s1 = "string 1";
    std::string s2 = "string 2";
    std::cout << "Integer Sum= " << addNumbers(i1, i2) << "\n";
    std::cout << "Float Sum= " << addNumbers(f1, f2) << "\n";
    std::cout << "String Sum= " << addNumbers(s1, s2) << "\n";
    std::cout << "The bigger one between " << i1 << " and " << f2 << " is " << getBigger(i1, f2) << "\n";
}
