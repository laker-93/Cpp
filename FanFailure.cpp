#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class FanFailure {
    public:
        vector<int> getRange(vector<int>, int);
};

vector<int> FanFailure::getRange(vector<int> capacities, int minCooling)
{
    sort(capacities.begin(), capacities.end());
    int sum = accumulate(capacities.begin(), capacities.end(), 0);
    int MFS= 0;
    int MFC= 0;
    int sum_s = sum;
    int sum_c = sum;
    vector<int> res;
    
    for(int i = 0; i < capacities.size(); i++) {
        cout << capacities.at(i) << ' ';
    }
    cout << endl;
    for(int i = 0; i < capacities.size(); i++) {
        sum_s -= capacities.at(i);
        if(sum_s < minCooling) {
            MFS = i;
            break;
        }
    }
    for(int i = capacities.size() - 1;i > 0; i--) {
        sum_c -= capacities.at(i);
        if(sum_c < minCooling) {
            break;
        }
        MFC++;
    }
    cout << MFS << " " << MFC << endl;
            res.push_back(MFC);
            res.push_back(MFS);
    res.resize(2);
    return res;
}

int main()
{
    FanFailure f;
    vector<int> test = {2, 4, 6, 8};
    vector<int> r = f.getRange(test, 1);
    for(int i : r) {
        cout << i << endl;
    }
    return 0;
}


