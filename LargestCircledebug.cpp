#include <vector>
#include <algorithm>
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
    int x_a = point.x;
    int y_a = point.y;
    int x_b = point.x + 1;
    int y_b = point.y;
    int x_c = point.x + 1;
    int y_c = point.y - 1;
    int x_d = point.x;
    int y_d = point.y - 1;
    int radius_sq = pow(radius, 2);
    int norm_a = pow(x_a - a, 2) + pow(y_a - b, 2) - radius_sq;
    int norm_b = pow(x_b - a, 2) + pow(y_b - b, 2) - radius_sq;
    int norm_c = pow(x_c - a, 2) + pow(y_c - b, 2) - radius_sq;
    int norm_d = pow(x_d - a, 2) + pow(y_d - b, 2) - radius_sq;
    if(norm_a >= 0 && norm_b >= 0 && norm_c >= 0 && norm_d >= 0) {
        return false;
    }
    if(norm_a <= 0 && norm_b <= 0 && norm_c <= 0 && norm_d <= 0) {
        return false;
    }
    return true;
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
    cout << " y " << centre.y << " x " << centre.x << endl;
    if(grid.at(0).size() < centre.x + radius || grid.size() <= centre.y + radius) {
        res.clear();
        return res;
    }
    int a = centre.x;
    int b = centre.y;
    node focus(a + radius - 1, b + 1);
    cout << " first focus = " << focus.x << " " << focus.y << endl;
    if(!check_free(focus, grid)) {
        res.clear();
        return res;
        cout << " exit first " << endl;
    } else {
        res.push_back(focus);
    }

    //need to iterate through one quarter of the circle's circumference so
    //from 0 to 2*pi*R/4 ~ 2*R to be safe.
    while(focus.x != a) {
    cout << 
        "centre = " << centre.x << " " << centre.y  << endl;
        cout<<
        "r =  " << radius << endl;
    if(focus.y + 1 <= grid.size() - 1) {
        node up(focus.x, focus.y + 1);
        cout << "up = " << up.x << " " << up.y << endl;
        if (pass_through(centre, radius, up)) {
            focus = up;
            if (check_free(up, grid)) {
                res.push_back(up);
                cout << " added " << up.x << " " << up.y << endl;
                continue;
            } else {
                cout << " up not free exit " << endl;
                res.clear();
                return res;
            }
        } 
    }
        if(focus.y + 1 <= grid.size() - 1) {
        node diag(focus.x -1, focus.y + 1);
            cout << "diag = " << focus.x - 1 << " " << focus.y + 1 << endl;
        if (pass_through(centre, radius, diag)) {
                focus = diag;
            if (check_free(diag, grid)) {
                res.push_back(diag);
                cout << " added " << diag.x << " " << diag.y << endl;
                continue;
            } else {
                cout << " diag not free exit " << endl;
                res.clear();
                return res;
            }
        }
        }
            node left(focus.x -1, focus.y);
            cout << "left = " << focus.x - 1 << " " << focus.y << endl;
        if (pass_through(centre, radius, left)) {
            focus = left;
            if (check_free(left, grid)) {
                res.push_back(left);
                cout << " added " << left.x << " " << left.y << endl;
                continue;
            } else {
                cout << " left not free exit " << endl;
                res.clear();
                return res;
            }
        } else {
            res.clear();
            return res;
        }

    }
    return res;
}

bool complete_quads(vector<node> q1, node centre, int radius, vector<string> grid)
{
    if((centre.x - radius) < 0 || 
       (centre.y + 1 - radius < 0) ||
       (grid.at(0).size() - centre.x - radius) < 0 || 
       (grid.size() - centre.y - radius) < 0) {
        cout << " BAAA " << endl;
        cout << "cen.x " << centre.x << " y " << centre.y << " r " << radius <<
            " grid.sz " << grid.size() << " " << grid.at(0).size() <<
            endl;
        return false;
    }

    for(node n : q1) {
        node test1(centre.x - (n.x + 1 - centre.x), n.y);
        if(!check_free(test1, grid)) {
                cout << " >>>>>> " << test1.x << " " << test1.y << endl;
            return false;
        }
        node test2(centre.x - (n.x + 1 - centre.x), centre.y + 1 - (n.y - centre.y));
        if(!check_free(test2, grid)) {
                cout << " >>>>>> " << test2.x << " " << test2.y << endl;
            return false;
        }
        node test3(n.x, centre.y + 1 - (n.y - centre.y));
        if(!check_free(test3, grid)) {
                cout << " >>>>>> " << test3.x << " " << test3.y << endl;
            return false;
        }
    }
    return true;
}
int LargestCircle::radius(vector<string> grid)
{
    int max = 0;
    if(grid.size() < 2 || grid.at(0).size() < 2)
        return 0;
    for(int r = 0; r <= grid.size() - 1; r++) {
        for(int c = 0; c <= grid.at(0).size() - 1; c++) {
            node centre(c,r);
            for(int radius = grid.size()/2; radius >= 1; radius --) {
                cout << " CENTRE " << c << " " << r << " RADIUS " << radius << endl;
                vector<node> q1 = quadrant_1(grid, centre, radius);
                if(q1.size() != 0) {
                    bool comp = complete_quads(q1, centre, radius, grid);
                    cout << "complete q1 ---------- centre " << c << r << " r = " << radius << " max = " << max  <<" comp = " << comp << endl;
                    if(comp && radius > max) {
                        cout << " new max " << max << endl;
                        max = radius;
                    }
                }
                    if(max > (grid.at(0).size() - c) && (max > (grid.size() - r))) {
                        return max;
                    }
            }
        }
    }
        cout << grid.size() << " SIZE  " << grid.at(0).size() << endl;
    return max;
}
int main()
{
    LargestCircle l;
    vector<string> grid =
 	{   "##################..............##################",
        "###############...##############...###############",
        "#############...##################...#############",
        "###########...######################...###########",
        "##########..##########################..##########",
        "########..#######..............#########..########",
        "#######..######...############...########..#######",
        "######..#####...################...#######..######",
        "#####..####...####################...######..#####",
        "#####.####..########################..######.#####",
        "####.####..##########################..######.####",
        "###..###..############################..#####..###",
        "###.###..##############################..#####.###",
        "##..##..################################..####..##",
        "##.###.##################################.#####.##",
        "#..##..##################################..####..#",
        "#.###.####################################.#####.#",
        "#.##..####################################..####.#",
        ".###.######################################.#####.",
        ".##..######################################..####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        ".##.########################################.####.",
        "#.#..######################################..###.#",
        "#.##.######################################.####.#",
        "#..#..####################################..###..#",
        "##.##.####################################.####.##",
        "##..#..##################################..###..##",
        "###.##.##################################.####.###",
        "###..#..################################..###..###",
        "####.##..##############################..####.####",
        "#####.##..############################..####.#####",
        "#####..##..##########################..####..#####",
        "######..##..########################..####..######",
        "#######..##...####################...####..#######",
        "########..###...################...#####..########",
        "##########..###...############...#####..##########",
        "###########...###..............#####...###########",
        "#############...##################...#############",
        "###############...##############...###############",
        "##################..............##################"};
    int a = l.radius(grid);
    cout << "R = " << a << endl;
    return 0;
}
