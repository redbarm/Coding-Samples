#include <iostream>
#include <vector>

using namespace std;

static const int NUM_OBJECTS = 10;

class MyClass 
{
 public:
 int age;
 double iq;
};

int main() {

   vector<MyClass*> vec;

   MyClass* p = NULL;

   // Load up the vector with MyClass objects
   for (int i = 0; i < NUM_OBJECTS; i++) {
      p = new MyClass();
      p->age=42+i;
      p->iq=150-2*i;	
      vec.push_back(p);
   }

   // Do something useful with this data, then delete the objects when
   // you're done
   for (vector<MyClass*>::iterator pObj = vec.begin();
        pObj != vec.end(); ++pObj) {
        std::cout << (*pObj)->age << '\n' << (*pObj)->iq << '\n';
      //delete *pObj; // Note that this is deleting what pObj points to,
                    // which is a pointer
   }

   vec.clear(); // Purge the contents so no one tries to delete them
                // again
}


