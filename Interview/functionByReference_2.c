#include<iostream>
#include <cstdlib>

int test(int & a, int * ptr, int * arrayptr){
    return a+*ptr+arrayptr[3];
}; 

//int test(int & a, int * ptr);
main(){
    int x=5;
    int * ptr;
    int & ref=x;
    int * arrayptr;

    ptr=&x;
    //ref=x;
    int array[5]={1,2,3,4,5};
    

    arrayptr=array;

    std::cout<<ptr<<"\n";
    std::cout<<*ptr<<"\n";
    std::cout<<ref<<"\n";
    std::cout<<&ref<<"\n";
    std::cout<<test(x,ptr,arrayptr)<<"\n";
    std::cout<<test(x,ptr,array)<<"\n";
    std::cout<<&array<<"\n";
    std::cout<<array<<"\n";
    std::cout<<arrayptr<<"\n";
   
    
    //std::cout<<b<<"\n";
    return 0;
}
 
 
