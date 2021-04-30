#include <cstdlib>
#include<iostream>

void arrayAsPointer(int *input, int size);
int main()
{
    int const size=5;
    int arr[size]={1,2,3,4,5};
    arrayAsPointer(arr,size);
    return 0;
}

void arrayAsPointer(int *input, int size)//Usage of pointer
{
   for (int i=0;i<size;i++){ 
       std::cout<<input[i]<<"\n";
   }       
}

