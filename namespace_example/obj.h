#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::iostream;

namespace nmspc1{
namespace nmspc2{

class obj    
{
private:
    /* data */
    string name;
    int len,width;
public:
    obj(/* args */);
    void setName(string nameIn);
    void getName();
    ~obj();
};

obj::obj(/* args */)
{
}

obj::~obj()
{
}
void obj::setName(string nameIn){
    name=nameIn;
}

void obj::getName(){
    std::cout<<name<<"\n";
};
    
}
}