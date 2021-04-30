#include<iostream>
#include<string>

using namespace std;

template<class T>
class StudentRecord
{
    private:
        const int size=5;
        T grade;
        int studentId;
    public:
        StudentRecord(T input);
        void setId(int idIn);
        void printGrades();
};

template<class T>
StudentRecord<T>::StudentRecord(T input)
{
    grade=input;
}

template<class T>
void StudentRecord<T>::setId(int idIn)
{
    studentId=idIn;
}

template<class T>
void StudentRecord<T>::printGrades()
{
    cout<<"ID# "<<studentId<<": ";
    cout<<grade<<"\n";
    cout<<"\n";

}


