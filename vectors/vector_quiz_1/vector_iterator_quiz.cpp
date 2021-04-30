// !!!!! Compile "shift+ctr+B"ederken her zaman xxx.cpp dosyasinin icinde olun. Diger dosyada olunca update etmiyor!!!

// Goal: pracitce constructing vectors
// and their iterators
// Call the vector vFloat
// Call the iterator it

//TODO: Add the necessary libraries
#include "main.h"

int main ()
{
  //TODO: create a vector of floats
   vector<float> vFloat;
   vector<float>::iterator it;

  std::cout<<"vFloat has "<<vFloat.size()<<" elements\n";

  //TODO: add elements to the library

  std::cout<<"\n\nAdding 10 elements to the vector\n";

  //TODO: assign the value 8.8 to 10 elements of the vector
   vFloat.assign(10, 8.8);
   std::cout<<"vFloat has "<<vFloat.size()<<" elements\n"; 

   //Adding elements by using push_back. It always add elements to the end

   vFloat.push_back(10);
   vFloat.push_back(20);
   vFloat.push_back(30);

  //TODO: Complete the Print function in main.hpp 
  // Call the function here to print out each element of vFloat
  printVector(vFloat);

  it=vFloat.begin()+1;
  vFloat.insert(it,0.11);
  printVector(vFloat);

  it=vFloat.begin();
  vFloat.insert(it+2,0.22);
  printVector(vFloat);

  it=vFloat.begin();
  vFloat.insert(it+4,0.33);
  printVector(vFloat);

  it=vFloat.end();
  vFloat.insert(it,0.99);
  printVector(vFloat);

  it=vFloat.end();
  //vFloat.insert(it+5,1.11); //it+5 calismiyor!!!!,
  vFloat.insert(it-5,1.11);//it-5 calisiyor!!
  printVector(vFloat);
  

  return 0;
}