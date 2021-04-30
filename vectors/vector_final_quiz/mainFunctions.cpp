/*functions can go here if you like*/

#include <C:\C++Projects\Udacity_c++_course\vectors\vector_final_quiz\main.h>

void family::printFamilyNames(vector<string> vName){
    vector<string>::iterator it;
    for (it=vName.begin();it !=vName.end();++it){
        std::cout<<*it<<" ";
    }
}

void family::printFamilyAges(vector<int> vAge){
    vector<int>::iterator it;
    for (it=vAge.begin();it !=vAge.end();++it){
        std::cout<<*it<<" ";
    }
}

void createVector(family &fm){
    string name;
    std::cin >> name;
    std::cout<<"adding name: "<<name<<" \n";
    fm.familyMemberName.push_back(name);
    std::cin >> name;
    std::cout<<"adding name: "<<name<<" \n";
    fm.familyMemberName.push_back(name);
    std::cin >> name;
    std::cout<<"adding name: "<<name<<" \n";
    fm.familyMemberName.push_back(name);
    //fm.familyMemberAge.push_back();
}

void createVectorPtr(family *fmptr){
    string name;
    std::cin >> name;
    std::cout<<"adding name: "<<name<<" \n";
    fmptr->familyMemberName.push_back(name);
    std::cin >> name;
    std::cout<<"adding name: "<<name<<" \n";
    fmptr->familyMemberName.push_back(name);
    std::cin >> name;
    std::cout<<"adding name: "<<name<<" \n";
    fmptr->familyMemberName.push_back(name);
    //fm.familyMemberAge.push_back();
}

void printNames(family &fm){
    std::cout<<"In printnames\n";
    std::cout<<fm.familyName<<'\n';
    vector<std::string>::iterator it;
    for (it=fm.familyMemberName.begin();it !=fm.familyMemberName.end();++it){
        std::cout<<*it<<" ";
    }
}


