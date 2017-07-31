#include <iostream>
using namespace std;

template <class generic>

generic add_stuff(generic a, generic b) {

    return a + b;
}
int main() {
    int a = 1;
    int b = 2;
    int c = add_stuff(a,b);
    cout << c <<endl;
    string s1 = "Hi";
    string s2 = " There.";
    string s3 = add_stuff(s1, s2);
    cout << s3 << endl;
    return 0;
}
