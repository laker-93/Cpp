#include <iostream>

using namespace std;
int main()
{
    int t = 10;
    while(t >0) {
        for(int i = 0; i < 4; i++) {
            if(i%2 == 0)
                continue;
            cout << "i " << i << endl;
        }
    cout << "t " << t << endl;
    t--;
    cout << " end " << endl;
    }
    return 0;
}
