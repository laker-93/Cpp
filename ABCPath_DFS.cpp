#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <vector>
#include <stack>
using namespace std;

class ABCPath {
    public:
        int length(vector<string>);
};

typedef struct node {
        char value;
        int row_index;
        int column_index;
}Node;

stack<Node> s;

vector<Node> adj_neighbours(Node center, vector<string> grid)
{
    int row = center.row_index;
    int column = center.column_index;
    vector<Node> nghbrs;
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            char target = 0;
            try {
                if(i == 0 && j == 0) continue;
                target = grid.at(row + i).at(column + j);
            } catch(const out_of_range& e) {
            }
            if(target != 0) {
                Node target_n;
                target_n.value = target;
                target_n.row_index = row + i;
                target_n.column_index = column + j;
                nghbrs.push_back(target_n);
            }
        }
    }
    return nghbrs;
}

vector<Node> find_As(vector<string> grid)
{
    vector<Node> As;
    int count = 0;
    int i = 0;
    for(string focus_row : grid) {
        int j = 0;
        for(char c : focus_row) {
            if (c == 'A') {
                Node target_n;
                target_n.value = 'A';
                target_n.row_index = i;
                target_n.column_index = j;
                As.push_back(target_n);
                count++;
            }
            j++;
        }
        i++;
    }
    As.resize(count);
    return As;
}
int ABCPath::length(vector<string> grid)
{
    int m = grid.size();
    int n = grid.at(0).size();
    bool **visits = new bool*[m];
    for(int i = 0; i < m; i++) {
        visits[i] = new bool[n];
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            visits[i][j] = false;
        }
    }

    vector<Node> As = find_As(grid);
    if(As.size() == 0)
        return 0;
    int len_max = 0;
    for(size_t i = 0; i < As.size(); i++) {

        Node focus = As.at(i);
        int len = 0;
        s.push(focus);
        len++;
        while(!s.empty()) {
            Node dequeued = s.top();
            vector<Node> nghbrs =  adj_neighbours(dequeued , grid);
            for(Node n : nghbrs) {
                if((n.value - dequeued.value) == 1) {
                    if(visits[n.row_index][n.column_index] == false) {
                           visits[n.row_index][n.column_index] = true;
                                s.push(n);
                                goto end;

                    }
                }
            }
            if((int) s.size() > len_max) {len_max = s.size();}
            s.pop();
end:
            ;
        }
    }
    return len_max;
}

int main()
{
    ABCPath a;
    const char *test[] = 
    /*                      {"ABCDEFGHIJKLMNOPQRSTUVWXA",*/
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXY",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           //"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           /*"ABCDEFGHIJKLMNOPQRSTUVWXA"};*/
      { "ABE",
        "CFG",
        "BDH",
        "ABC" }; 

    vector<string> v1(test, end(test));
    int len = a.length(v1);
    cout << len << endl;
    return 0;
}
