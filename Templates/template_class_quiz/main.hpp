#include <iostream>
#include <string>

using namespace std;

template<class T>
class Multiplier
{
    private:
        T input1;
        T input2;
        T result;
    public:
        void setM1(T in);
        void setM2(T in);
        void setProduct();
        void printEquation();
};

template<class T>
void Multiplier<T>::setM1(T in)
{
    input1=in;
}

template<class T>
void Multiplier<T>::setM2(T in)
{
    input2=in;
}

template<class T>
void Multiplier<T>::setProduct()
{
    result= input1*input2;
}

template<class T>
void Multiplier<T>::printEquation()
{
    cout<<"the result is "<<result;
}








