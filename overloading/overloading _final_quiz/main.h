//the header file for main.cpp

#include <iostream>
#include <string>

using namespace std;

class sector
{
private:
    string name;
    float length;
    float width;

public:
    sector(string name, float length, float width);
    string getName();
    float getLength();
    float getWidth();
    float area();
};

sector::sector(string nameIn, float lengthIn, float widthIn)
{
    name = nameIn;
    length = lengthIn;
    width = widthIn;
}

string sector::getName()
{
    return name;
}

float sector::getLength()
{
    return length;
}

float sector::getWidth()
{
    return width;
}

float sector::area()
{
    return length * width;
}
