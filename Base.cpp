#include "Base.h"
#include <iostream>

using namespace std;

Base::Base() {
    cout << "Base constructor" << endl;
}

Base::~Base() {
    cout << "Base deconstructor" << endl;
}
void Base::stuff(){
    //*publicv = 10;
    protectedv = 5;
    privateV = 0;
}

void Base::print() {

    cout << "base print publicv " << publicv << endl;
    //cout << "base print *publicv " << *publicv << endl;

}
