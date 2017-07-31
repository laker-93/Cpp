#include <iostream>
#include <vector>

using namespace std;

struct state {
    int total;
    state(int t) { total = t; };
};
class BadNeighbors {
    public:
        int maxDonations(vector<int>);
};

int backward(vector<int> dons) {
    if(dons.size() == 1) {
        return dons.at(0);
    }
    int f = dons.at(dons.size() - 1);
    int s = dons.at(dons.size() - 2);
    int max_d = s;

    state first(f);
    state second(s);
    if(f > s) {
        max_d = f;
    }
    if(dons.size() == 2) {
        return max_d;
    }
    vector<state> states;
    states.push_back(first);
    states.push_back(second);
    int k = 2;
    for(int i = dons.size() - 3; i > 0; i--) {
        int max = 0;
        for(int j = k - 2; j >= 0; j--) {
            state tail = states.at(j);
            if(tail.total > max) {
                max = tail.total;
            }
        }
        int total = dons.at(i) + max;
        state head(total);
        states.push_back(head);
        if(total > max_d) {
            max_d = total;
        }
        k++;
    }

    return max_d;
}
int forward(vector<int> dons) {
    if(dons.size() == 1) {
        return dons.at(0);
    }
    int f = dons.at(0);
    int s = dons.at(1);
    int max_d = s;

    state first(f);
    state second(s);
    if(f > s) {
        max_d = f;
    }
    if(dons.size() == 2) {
        return max_d;
    }
    vector<state> states;
    states.push_back(first);
    states.push_back(second);
    for(int i = 2; i < dons.size() - 1; i++) {
        int max = 0;
        for(int j = i - 2; j >= 0; j--) {
            state tail = states.at(j);
            if(tail.total > max) {
                max = tail.total;
            }
        }
        int total = dons.at(i) + max;
        state head(total);
        states.push_back(head);
        if(total > max_d) {
            max_d = total;
        }
    }

    return max_d;
}
int BadNeighbors::maxDonations(vector<int> dons)
{

    int f_max = forward(dons);
    int b_max = backward(dons);
    return (f_max > b_max ? f_max : b_max);
}


int main()
{
    BadNeighbors b;
    vector<int> dons ={ 7, 7, 7, 7, 7, 7, 7 };
    int res = b.maxDonations(dons);
    cout << res << endl;
    return 0;
}

