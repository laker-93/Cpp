#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <class T>
class MyClass {
    int i;
    vector<int> vi;
    vector<int>::iterator vitr;

    T t;
    vector<T> vt;
    vector<T>::iterator viter;

};

int main()
{
    MyClass<char> a;
    return 0;
}

