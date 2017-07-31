#include <iostream>
using namespace std;

template <class F, class S>

S smaller(F a, S b) {

    return (a < b ? a : b);
}
int main() {
    
    int x = 89;
    double y = 56.76;
    cout << smaller(x,y) << endl;
    return 0;
}
