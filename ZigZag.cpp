#include <iostream>
#include <vector>

using namespace std;

struct state {
    int n;
    int prev_n;
    int len;
    state(int, int, int);
};

state::state(int a, int b, int c)
{
    n = a;
    prev_n = b;
    len = c;
}
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

class ZigZag {
    public:
    int longestZigZag(vector<int>);
};

int ZigZag::longestZigZag(vector<int> input)
{
        if(input.size() == 1) {
        return 1;
    }

    if(input.size() == 0) {
        return 0;
    }
    int first_prev;
    if(input.at(1) > input.at(0)) {
        first_prev = input.at(0) + 1;
    } else {
        first_prev = input.at(0) - 1;
    }


    state first(input.at(0), first_prev, 1);
    vector<state> seen;
    seen.push_back(first);
    int max = 1;
    for(int i = 1; i < input.size(); i ++) {
        int n = input.at(i);
        int prev_n = input.at(i - 1);
        int diff = n - prev_n;
        int n_sign = sgn(diff);
            if(n_sign == 0) {
                continue;
            }
        for(int i = seen.size() - 1; i >= 0; i--) {
            state prev = seen.at(i);
            int prev_diff = prev.n - prev.prev_n;
            int prev_sign = sgn(prev_diff);
            if(prev_sign == 0) {
                continue;
            }
            if(n_sign != prev_sign) {
                int new_len = prev.len + 1;
                state focus(n, prev.n, new_len);
                seen.push_back(focus);
                if(new_len > max) { max = new_len; }
                break;
            }
        }
    }
    return max;
}

int main()
{
    vector<int> input = {1, 1};


    ZigZag z;
    int res = z.longestZigZag(input);
    cout << res << endl;
    return 0;
}
