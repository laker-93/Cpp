#include <iostream>

using namespace std;

void testy(int& a)
{
    cout << "I am & " << a << endl;
    int b = 3;
    testy(&b);
    return;
}
int main()
{
    int a = 1;
    testy(a);
}
