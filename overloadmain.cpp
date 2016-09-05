#include <iostream>
#include "Overload.h"
using namespace std;

int main() {
    Overload a(34);
    Overload b(21);
    Overload c;
    c = a + b;
    cout << c.num << endl;
}
