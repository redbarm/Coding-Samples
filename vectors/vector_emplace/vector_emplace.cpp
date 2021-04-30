#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<int> vectorInts;
    std::vector<int>::iterator it;

    vectorInts.push_back(0);
    vectorInts.push_back(1);
    vectorInts.push_back(2);
    vectorInts.push_back(3);
    vectorInts.push_back(4);
    vectorInts.push_back(5);
    vectorInts.push_back(6);
    vectorInts.push_back(7);

    for (it=vectorInts.begin();it !=vectorInts.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<'\n';

    /*
    Using it=vector.begin();
    //vectorInts.emplace(it+2,-1);
    //and
    //Using it=vector.begin()+2;
    //vectorInts.emplace(it,-1);
    are the same thing
    */


    /*
    std::cout<<"Using Emplace to Insert vector element"<<'\n';
    it=vectorInts.begin();
    vectorInts.emplace(it,-1);
       for (it=vectorInts.begin();it !=vectorInts.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<'\n';

    std::cout<<"Using Emplace to Insert vector element"<<'\n';
    it=vectorInts.begin();
    vectorInts.emplace(it+3,-2);
       for (it=vectorInts.begin();it !=vectorInts.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<'\n';

    std::cout<<"Using Emplace to Insert vector element"<<'\n';
    it=vectorInts.begin();
    vectorInts.emplace(it+5,-3);
       for (it=vectorInts.begin();it !=vectorInts.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<'\n';
    */

    std::cout<<"Using Emplace to Insert vector element"<<'\n';
    it=vectorInts.begin();
    vectorInts.emplace(it,-1);
       for (it=vectorInts.begin();it !=vectorInts.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<'\n';

    std::cout<<"Using Emplace to Insert vector element"<<'\n';
    it=vectorInts.begin()+3;
    vectorInts.emplace(it,-2);
       for (it=vectorInts.begin();it !=vectorInts.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<'\n';

    std::cout<<"Using Emplace to Insert vector element"<<'\n';
    it=vectorInts.begin()+5;
    vectorInts.emplace(it,-3);
       for (it=vectorInts.begin();it !=vectorInts.end();++it)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<'\n';

    return 0;
}
