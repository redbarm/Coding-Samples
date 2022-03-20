#include <cstdlib>
#include<iostream>

void arrayAsPointer(int *input, int size);

int main()
{
    int const size=5;
    int array[size]={1,2,3,4,5};
    int * arrayptr;
    arrayptr=array;

    arrayAsPointer(array,size);
    std::cout<<&array<<"\n";
    std::cout<<array<<"\n";
    std::cout<<arrayptr<<"\n";
    /*
    data[0] is equivalent to *data and &data[0] is equivalent to data
    data[1] is equivalent to *(data + 1) and &data[1] is equivalent to data + 1
    data[2] is equivalent to *(data + 2) and &data[2] is equivalent to data + 2
    */
    return 0;
}

void arrayAsPointer(int *input, int size)//Usage of pointer
{
   for (int i=0;i<size;i++){ 
       std::cout<<input[i]<<"\n";
   }       
}

