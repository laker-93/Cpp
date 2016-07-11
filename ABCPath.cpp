#include <iostream>
#include <stdio.h>
#include <stdexcept>
#include <vector>
#include <queue>
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

queue<Node> q;

void que_neighbours(Node center, vector<string> grid)
{
    int row = center.row_index;
    int column = center.column_index;
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
                q.push(target_n);
            }
        }
    }
    return;
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
    vector<Node> As = find_As(grid);
    if(As.size() == 0)
        return 0;
    int len;
    int len_max = 0;
    for(size_t i = 0; i < As.size(); i++) {

        len = 1;
        Node A = As.at(i);
        cout << " \n " << " i = " << A.row_index << " j = " << A.column_index <<  "\n" << endl;
        que_neighbours(A , grid);
        char focus = A.value;
        while(!q.empty()) {
            Node dequeued = q.front();
            char deq_char = dequeued.value;
            cout << "focus = " << focus << endl;
            q.pop();
            if((deq_char - focus) == 1) {
                len++;
            cout << "deq = " << deq_char << dequeued.row_index << " " << dequeued.column_index << endl;
                focus = deq_char;
                q = {};
                que_neighbours(dequeued, grid);
            }
        }
        if(len > len_max) {
            len_max = len;
        }
    }
    return len_max;
}

int main()
{
    ABCPath a;
    const char *test[] =  {"ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXY",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA",
                           "ABCDEFGHIJKLMNOPQRSTUVWXA"};

    vector<string> v1(test, end(test));
    int len = a.length(v1);
    cout << len << endl;
    return 0;
}
