/*Create a class that has four constructors:
* one that accepts no input parameters
* one that accepts name
* one that accepts license number
* one that accepts name and license number
* The default values are:
name = NA
license = 0
*/

#include<iostream>
#include<string>
using namespace std;

class Dog
{
    string name;
    int licenseNumber;

    public:
    void setName(string nameIn);
    void setLicense(int lcnsIn);
    string getName();
    int getLicense();

    //Defining Constructor
    Dog(){
        //cout<<"no input parameters\n";
        name="NA";
        licenseNumber=0;
    }

    Dog(string nameIn){
        //cout<<"one that accepts name\n";
        name=nameIn;
        licenseNumber=0;

    }

    Dog(int licenseIn){
        //cout<<"one that accepts license number\n";
        name="NA";
        licenseNumber=licenseIn;
    }

    Dog(string nameIn, int licenseIn){
        //cout<<"one that accepts name and license number\n";
        name=nameIn;
        licenseNumber=licenseIn;
    }

};


void Dog::setName(string nameIn){
    name=nameIn;
}

void Dog::setLicense(int lcnsIn){
    licenseNumber=lcnsIn;
}

string Dog::getName(){
    return name;
}

int Dog::getLicense(){
    return licenseNumber;
}


