#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct blocked {
    int x;
    int y;
    bool is_vertical;
    blocked(int i, int j, bool v) {x = i; y = j; is_vertical = v;};
};
class AvoidRoads {
    public:
        int numWays(int, int, vector<string>);
};

vector<blocked> parse(vector<string> bad)
{
    vector<int> bad_ints;
    for(string coord_str : bad) {
        istringstream is(coord_str);
        int coord_int;
        while(is.good()) {
            is >> coord_int;
            bad_ints.push_back(coord_int);
        }
    }
    vector<blocked> blocks;
    for(int k = 0; k < bad.size(); k++) {
        int i = 4*k;
        if(bad_ints.at(i) != bad_ints.at(i+2)) {
            int left_corner = bad_ints.at(i);
            if(bad_ints.at(i + 2) < left_corner) {
                left_corner = bad_ints.at(i+2);
            }
            blocked horizontal(left_corner, bad_ints.at(i+3), false);
            blocks.push_back(horizontal);
        }
        if(bad_ints.at(i + 1) != bad_ints.at(i+3)) {
            int left_corner = bad_ints.at(i);
            if(bad_ints.at(i + 2) < left_corner) {
                left_corner = bad_ints.at(i+2);
            }
            blocked vertical(left_corner, bad_ints.at(i+1), true);
            blocks.push_back(vertical);
        }
    }
            
    return blocks;
}
int AvoidRoads::numWays(int height, int width, vector<string> bad)
{
    vector<blocked> blocks = parse(bad);
    for(blocked b : blocks) {
        cout << b.x << " " << b.y << " " << " is_vertical " << b.is_vertical << endl;
    }
    return 0;
    int num_paths[height][width] = {};
    bool blocked = false;
    for(int i = 0; i < width; i++) {
        for(blocked b : blocks) {
            if(b.is_vertical == false && b.x == 0 && b.y == i && !blocked) {
                num_paths[0][i] == 1;
            } else {
                num_paths[0][i] == 0;
                blocked = true;
            }
        }
    }
    blocked = false;
    for(int j = 0; j < height; j++) {
        for(blocked b : blocks) {
            if(b.is_vertical == true && b.x == 0 && b.y == i && !blocked) {
                num_paths[j][0] == 1;
            } else {
                num_paths[j][0] == 0;
                blocked = true;
            }
        }
}

int main()
{
    AvoidRoads a;
    vector<string> bad = {"0 0 0 1","6 6 5 6"};
    a.numWays(0, 0, bad);
    return 0;
}
