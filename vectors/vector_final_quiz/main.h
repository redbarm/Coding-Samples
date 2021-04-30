/*the header file for main.cpp*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class family
{
    public:
    string familyName;
    vector<std::string> familyMemberName;
    vector<int> familyMemberAge;
    void printFamilyNames(vector<string> vName);
    void printFamilyAges(vector<int> vAge);
};


