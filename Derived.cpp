#include <iostream>
#include "Base.h"
#include "Derived.h"
using namespace std;

void Derived::doSomething(){

     cout << "start of derived" << publicv << endl;
     publicv = 1;
     protectedv = 6;
     cout << "end of derived" << publicv << endl;

}
