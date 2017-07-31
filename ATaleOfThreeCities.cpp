#include <iostream>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <vector>

using namespace std;
class ATaleOfThreeCities {
    public:
        double connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy);
};

double check_distance(int focus_x, int focus_y, int target_x, int target_y)
{
    int del_x = abs(focus_x - target_x);
    int del_y = abs(focus_y - target_y);
    return sqrt(pow(del_x, 2) + pow(del_y, 2));
}

double ATaleOfThreeCities::connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy)
{
    double A_B_min = DBL_MAX;
    double A_C_min = DBL_MAX;
    double B_C_min = DBL_MAX;
    int num_A = ax.size();
    int num_B = bx.size();
    int num_C = cx.size();

    for(int i = 0; i < num_A; i++) {
        int focus_x = ax.at(i);
        int focus_y = ay.at(i);
        for(int j = 0; j < num_B; j++) {
            int target_x = bx.at(j);
            int target_y = by.at(j);
            double dist = check_distance(focus_x, focus_y, target_x, target_y);
            if(dist < A_B_min) { A_B_min = dist; }
        }
        for(int k = 0; k < num_C; k++) {
            int target_x = cx.at(k);
            int target_y = cy.at(k);
            double dist = check_distance(focus_x, focus_y, target_x, target_y);
            if(dist < A_C_min) { A_C_min = dist; }
        }
    }
    for(int i = 0; i < num_C; i++) {
        int focus_x = cx.at(i);
        int focus_y = cy.at(i);
        for(int j = 0; j < num_B; j++) {
            int target_x = bx.at(j);
            int target_y = by.at(j);
            double dist = check_distance(focus_x, focus_y, target_x, target_y);
            if(dist < B_C_min) { B_C_min = dist; }
        }
    }
    cout << A_B_min << endl;
    cout << A_C_min << endl;
    cout << B_C_min << endl;
    double res = min({A_B_min + A_C_min, A_B_min + B_C_min, A_C_min + B_C_min});
    cout << res<< endl;
    return res;
}

int main()
{
    int fx = 1;
    int fy = 2;
    int tx = 3;
    int ty = 4;
    check_distance(fx, fy, tx, ty);
    ATaleOfThreeCities atoc;
    vector<int> ax = {0,0,0};
    vector<int> ay = {0,1,2};
    vector<int> bx = {2,3};
    vector<int> by = {1,1};
    vector<int> cx = {1,5};
    vector<int> cy = {3,28};
    double res = atoc.connect(ax, ay, bx, by, cx, cy);
    return 0;    
}                
