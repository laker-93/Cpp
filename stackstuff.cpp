#include <iostream>
#include <stack>

using namespace std;
int main()
{
    stack<int> s;
    s.push(3);
    cout << s.size() << endl;
    int a = s.top();
    cout << s.size() << a << endl;
    return 0;
}
