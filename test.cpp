#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
struct cell {
    int column;
    int row;
};


bool is_in_range(cell src, int r_disp, int c_disp) 
{
    int c = src.column;
    int r = src.row;
    return (0 <= (c + c_disp) && (c + c_disp) <= 7 && 0 <= (r + r_disp) && (r + r_disp) <= 7);
}

vector<cell> possible_moves(cell src)
{
    vector<cell> moves;
    int rc_disp[2] = {2, 1};
    for(int k = 0; k < 2; k++)
        for(int i = 0; i < 2; i++)
                for(int j = 0; j < 2; j++) {
                    int r_disp = pow(-1, k) * rc_disp[i] ;
                    int c_disp = pow( -1, j) * rc_disp[((i + 1) % 2)] ;
                    if(is_in_range(src, r_disp, c_disp)) {
                        cell new_cell;
                        new_cell.column = src.column + c_disp;
                        new_cell.row = src.row + r_disp;
                        moves.push_back(new_cell);
                        cout << new_cell.row << ", " << new_cell.column << endl;
                    }
            }
    return moves;
}
int main() {
   
    cell c;
    c.row = 1;
    c.column = 0;
    possible_moves(c);
    return 0;
}
