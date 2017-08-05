#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int height = 3;
const int width = 3;
int num_paths[height][width];
//[rows][columns]
struct node {
    int x;
    int y;
    bool is_vertical;
    node(int i, int j, bool v) {x = i; y = j; is_vertical = v;};
};
class AvoidRoads {
    public:
        int numWays(int, int, vector<string>);
};

vector<node> parse(vector<string> bad)
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
    vector<node> nodes;
    for(int k = 0; k < bad.size(); k++) {
        int i = 4*k;
        if(bad_ints.at(i) != bad_ints.at(i+2)) {
            int left_corner = bad_ints.at(i);
            if(bad_ints.at(i + 2) < left_corner) {
                left_corner = bad_ints.at(i+2);
            }
            node horizontal(left_corner, bad_ints.at(i+3), false);
            nodes.push_back(horizontal);
        }
        if(bad_ints.at(i + 1) != bad_ints.at(i+3)) {
            int left_corner = bad_ints.at(i);
            if(bad_ints.at(i + 2) < left_corner) {
                left_corner = bad_ints.at(i+2);
            }
            node vertical(left_corner, bad_ints.at(i+1), true);
            nodes.push_back(vertical);
        }
    }
            
    return nodes;
}
int AvoidRoads::numWays(int height, int width, vector<string> bad)
{
    vector<node> nodes = parse(bad);
    for(node b : nodes) {
        cout << b.x << " " << b.y << " " << " is_vertical " << b.is_vertical << endl;
    }
    bool blocked_bool = false;
    for(int i = 0; i < width; i++) {
        for(node b : nodes) {
        if((!b.is_vertical) && (b.x == i) && (b.y == 0)) {
            cout << "blocked " << endl;
            blocked_bool = true;
        }
        }
        if(!blocked_bool){
                cout << "free" << endl;
                num_paths[height - 1][i] = 1;
        }else {
                cout << "blocked" << endl;
                num_paths[height - 1][i] = 0;
        }
    }
    cout << " <<<<<<< " << endl;
    blocked_bool = false;

    for(int j = height - 1; j >= 0; j--) {
        for(node b : nodes) {
            if((b.is_vertical) && (b.x == 0) && (b.y == height - 1 - j)) {
                cout << "blocked " << endl;
                blocked_bool = true;
            }
        }
        if(!blocked_bool){
                num_paths[j][0] = 1;
                cout << "free" << endl;
        }else {
                cout << "blocked" << endl;
                num_paths[j][0] = 0;
        }
    }
    for(int i = 1; i < width; i++) {
        for (int j = height - 2; j >= 0; j--) {
            bool no_horizontal = false;
            bool no_vertical = false;
            cout << "i = " << i << " j = " << j << endl;
            for(node b : nodes) {
                if((!b.is_vertical) && (b.x == i - 1) && (b.y ==height - 1 - j)) {
                    no_horizontal = true;
                    cout << " no horiz set" << endl;
                }
                if((b.is_vertical) && (b.x == i) && (b.y == j + 1)) {
                    no_vertical = true;
                    cout << " no vertical set" << endl;
                }
            }
            if(!no_horizontal) {
                cout << "set num_paths[j][i] += " << num_paths[j][i-1] << endl;
                num_paths[j][i] += num_paths[j][i-1];
            }
            if(!no_vertical) {
                cout << "set num_paths[j][i] += " << num_paths[j + 1][i] << endl;
                num_paths[j][i] += num_paths[j + 1][i];
            }
        }
    }
    //PRINT
    cout << num_paths[width - 1][0] << endl;
   // for(int i = 0; i < width; i++) {
   //     for(int j = 0; j < height; j++) {
   //         cout << num_paths[i][j] << " " ;
   //     }
   //     cout << endl; 
   // }
    return 0;
}

int main()
{
    AvoidRoads a;
    vector<string> bad = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
    a.numWays(height, width, bad);
    return 0;
}
