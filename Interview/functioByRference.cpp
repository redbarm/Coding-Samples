#include <cstdlib>
#include<iostream>
void increment(int &input); //Note the addition of '&'
void increment2(int input);
void increment3(int *input);

int main()
{
    int a = 34;
    int *ptr;
    int &ref=a;
    ptr=&a;
    std::cout<<"Before the function call a = "<<a<<"\n";
    std::cout<<"Before the function call ref = "<<ref<<"\n";
    
    //increment(a);
    //increment(ref);
    //increment2(ref);
    increment3(ptr);//or increment3(&a)
    
    
    std::cout<<"After the function call a = "<<a<<"\n";
    std::cout<<"After the function call ref = "<<ref<<"\n";
    return 0;
}
void increment(int &input)//Note the addition of '&'
{
    input++; //**Note the LACK OF THE addition of '&'**
    std::cout<<"In the function call a = "<<input<<"\n";
}

void increment2(int & input)//Note the lack of the additon of '&'
{
    input++; //**Note the LACK OF THE addition of '&'**
    std::cout<<"In the function call a = "<<input<<"\n";
}

void increment3(int *input)//Usage of pointer
{
   ++*input ; 
    std::cout<<"In the function call a = "<<*input<<"\n";
}

//If we use const as below
//void increment3(const int *input)//Usage of pointer with const

//We receive the error:
//Line 40: Char 4: error: read-only variable is not assignable
//   ++*input ;
//   ^ ~~~~~~
