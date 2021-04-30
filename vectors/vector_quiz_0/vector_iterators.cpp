#include <vector>
#include <string>
#include <iostream>

using namespace std;


int main(){
    //creating a vector of integers
    std::vector<int> vectorsInts;
    //creating an iterator for the vector
    std::vector<int>::iterator it;

    //change the size to 10
    //vectorsInts.resize(10);

    std::cout<<"the size of the vectorInts "<<vectorsInts.size()<<'\n';
    vectorsInts.assign(2,15);

    std::cout<<"the value at element 5 is "<< vectorsInts[4]<<'\n';
    std::cout<<"the value at element 20 is "<< vectorsInts[20]<<'\n';

    //when print out a not assigned element it shows 0, no matter is integer or float
    //when print out the last element it shows something like 13786064, the elements more than that show 0
    //vector tipiyle,int, iterator tipi,int, ayni olmali 

    for (it = vectorsInts.begin(); it != vectorsInts.end(); ++it){
        std::cout<<*it<<" ";
    }

    return 0;

}
