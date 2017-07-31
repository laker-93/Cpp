#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 6;

class BridgeCrossing {
        vector<int> times;
        vector<int> crossed;
        vector<int> totals;
    public:
        int minTime(vector<int>);
        vector<int> go(int, int, int*);
        void set_times(vector<int> times) { this->times = times; };
};
void alter(vector<int> &in)
{
    vector<int> result;
    vector<int>::iterator m;
    vector<int>::iterator m_2;
        m = min_element(begin(in), end(in));
        result.push_back(*m);
        in.erase(m);
        m_2 = min_element(begin(in), end(in));
        result.push_back(*m_2);
        in.erase(m_2);

        return;

}

vector<int> BridgeCrossing::go(int tm, int left, int *side)
{
    int min;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(side[i] == 0 && side[j] == 0) {
                int t = tm +max(times[i], times[j]);
                side[i] = side[j] = 1;
                min = times[i];
                cout << "CROSSING " << i << j << endl;
                cout << "left with " << endl;
                for(int i = 0; i < n; i++) {
                        cout << i << " " << side[i] << endl;
                }
                if(left == 2) {
                    cout << "RESULT " << t << endl;
                    totals.push_back(t);
                }else{
                    int min_index;
                    for(int k = 0; k < n; k++) {
                        if(side[k] == 1) {
                            if(times[k] <= min) { 
                                min = times[k];
                                min_index = k;
                            }
                        }
                    }
                        cout << "return " << min << " index " << min_index << endl;
                        side[min_index] = 0;
                        this->go(t + min, left - 1, side);
                        side[min_index] = 1;
                }
            side[i] = side[j] = 0;
            }
        }
    }
    return totals;
}


vector<int> get_pair(vector<int> &in, bool fastest)
{
    vector<int> result;
    vector<int>::iterator m;
    vector<int>::iterator m_2;
    if(fastest) {
        m = min_element(begin(in), end(in));
        result.push_back(*m);
        in.erase(m);
        m_2 = min_element(begin(in), end(in));
        result.push_back(*m_2);
        in.erase(m_2);
    } else {
        m = max_element(begin(in), end(in));
        result.push_back(*m);
        in.erase(m);
        m_2 = max_element(begin(in), end(in));
        result.push_back(*m_2);
        in.erase(m_2);
    }

    return result;
}

int BridgeCrossing::minTime(vector<int> times_v)
{
    vector<int> crossed;
    size_t n_people = times_v.size();
    vector<int> final_time;
    if(n_people == 1) {
        crossed = times_v;
        final_time.push_back(crossed.at(0));
    }
    while(crossed.size() < n_people) {
    vector<int> fast_pair = get_pair(times_v, true);
    cout << "fast pair " << endl;
    for(int i : fast_pair) {
        cout << i << endl;
    }
    final_time.push_back(*max_element(begin(fast_pair), end(fast_pair)));
    crossed.insert(end(crossed), begin(fast_pair), end(fast_pair));
    cout << "insert pair " << endl;
    for(int i : crossed) {
        cout << i << endl;
    }
    cout << "-------" << endl;
    if(crossed.size() == n_people) {
        break;
    }
    vector<int>::iterator returner = min_element(begin(crossed), end(crossed));
    final_time.push_back(*returner);
    cout << "return 1 " << *returner << endl;
    times_v.push_back(*returner);
    crossed.erase(returner);
    vector<int> slow_pair = get_pair(times_v, false);
    cout << "slow pair " << endl;
    for(int i : slow_pair) {
        cout << i << endl;
    }
    final_time.push_back(*max_element(begin(slow_pair), end(slow_pair)));
    crossed.insert(end(crossed), begin(slow_pair), end(slow_pair));
    if(crossed.size() == n_people) {
        break;
    }
    returner = min_element(begin(crossed), end(crossed));
    cout << "return 2 " << *returner << endl;
    final_time.push_back(*returner);
    times_v.push_back(*returner);
    crossed.erase(returner);
    }
    int sum = 0;
    cout << " >>>>>>> " << endl;

    for(int i : final_time) {
        cout << i << endl;
        sum += i;
    }
    return sum;
}
void rec(int level) {
    if(level == 0)
        return;
    cout << level << endl;
    rec(level - 1);
}
int main()
{
    vector<int> times = //{1, 2, 5 ,10 };
    {99, 13, 67, 32, 5, 17};
    cout << " >> " << endl;
    
    int a = 10;
    BridgeCrossing b;
    b.set_times(times);
    int side[6] = {0, 0, 0, 0};
    vector<int> totes = b.go(0, times.size(), side);

    int min = *min_element(begin(totes), end(totes));
    cout << min << endl;
    return 0;
}
