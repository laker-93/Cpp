#include <vector>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

struct node {
    int x;
    int y;
    node(int, int);
};

node::node(int a, int b){
    x = a;
    y = b;
}

class LargestCircle {

    public:
        int radius(vector<string>);

};

bool pass_through(node centre, int radius, node point)
{
    int a = centre.x;
    int b = centre.y;
    int x = point.x;
    int y = point.y;
    int r_1 = (pow(((x - 1) - a), 2)) + (pow(((y - 1) - b), 2));
    int r_2 = (pow((x - a), 2)) + (pow((y - b), 2));
    if(radius >= r_1 && radius <= r_2) {
        return true;
    }
    return false;
}

bool check_free(node focus, vector<string> grid)
{
    int x = focus.x;
    int y = focus.y;
    if(grid.at(grid.size() - y - 1).at(x) == '.')
        return true;
    else
        return false;
}

vector<node> quadrant_1(vector<string> grid, node centre, int radius)
{
    vector<node> res;
    cout << centre.x << " " << centre.y  << " " << radius << endl;

    if(grid.size() < centre.x + radius || grid.size() < centre.y + radius) {
        res.clear();
        return res;
    }
    int a = centre.x;
    int b = centre.y;
    node focus(a + radius, b + 1);
    if(!check_free(focus, grid)) {
        res.clear();
        return res;
    } else {
        res.push_back(focus);
    }

    while(focus.x + 1 != a) {

        node up(focus.x, focus.y + 1);
        node diag(focus.x -1, focus.y + 1);
        node left(focus.x -1, focus.y);
        if (pass_through(centre, radius, up)) {
            if (check_free(up, grid)) {
                res.push_back(up);
            } else {
                res.clear();
                return res;
            }
        }
        if (pass_through(centre, radius, diag)) {
            if (check_free(diag, grid)) {
                res.push_back(diag);
            } else {
                res.clear();
                return res;
            }
        }
        if (pass_through(centre, radius, left)) {
            if (check_free(left, grid)) {
                res.push_back(left);
            } else {
                res.clear();
                return res;
            }
        }
    }
    return res;
}

bool complete_quads(vector<node> q1, node centre, int radius, vector<string> grid)
{
    if(centre.x - radius < 0 || centre.y - radius < 0 || 
       grid.size() - centre.x - radius < 0 || 
       grid.size() - centre.y - radius < 0) {
        return false;
    }

    for(node n : q1) {
        node test1(centre.x - (n.x - centre.x), n.y);
        if(!check_free(test1, grid)) {
            return false;
        }
        node test2(centre.x - (n.x - centre.x), centre.y - (n.y - centre.y));
        if(!check_free(test2, grid)) {
            return false;
        }
        node test3(centre.x, centre.y - (n.y - centre.y));
        if(!check_free(test3, grid)) {
            return false;
        }
    }
    return true;
}
int LargestCircle::radius(vector<string> grid)
{
    for(int r = 1; r < grid.size() - 2; r++) {
        for(int c = 1; c < grid.at(0).length() - 2; c++) {
            node centre(c,r);

            cout << grid.size() << endl;
            for(int radius = grid.size()/2; radius >= 1; radius --) {
                vector<node> q1 = quadrant_1(grid, centre, radius);
                if(q1.size() != 0) {
                    if(complete_quads(q1, centre, radius, grid)) {
                        return radius;
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    LargestCircle l;
    vector<string> grid = { "####", "#..#", "#..#", "####" };
    int a = l.radius(grid);
    cout << a << endl;
    return 0;
}
