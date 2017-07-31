#include <iostream>
#include <algorithm>

using namespace std;

class ABBA {
    public:
        string canObtain(string, string);
};

string ABBA::canObtain(string initial,string target)
{
    int in_len = initial.length();
    int ta_len = target.length();

    while(ta_len > in_len) {

        char focus = target.at(ta_len - 1);
        if(focus == 'A') {
            target.pop_back();
        }
        else if(focus == 'B') {
            target.pop_back();
            reverse(target.begin(), target.end());
        }
        ta_len = target.length();
    } 

    if(target == initial)
        return "Possible";
    else
        return "Impossible";
}
int main()
{
    string initial = "B";
    string target = "ABBA";
    
    ABBA test;
    string result = test.canObtain(initial, target);
    cout << result << endl;
}
