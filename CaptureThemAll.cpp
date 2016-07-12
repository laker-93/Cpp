
// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include <math.h>
#include <vector>
#include<iostream>
#include <list>
 
using namespace std;
 
struct cell {
    int num_moves = 0;
    int column;
    int row;
};

// This class represents a directed graph using adjacency list representation
class CaptureThemAll
{
    public:
        int fastKnight(string king, string rook, string queen);
        cell parse_str(string piece);
        int BFS(cell start, cell dst);  // returns distance from start to dst
};
 
cell CaptureThemAll::parse_str(string piece)
{
     cell c;
     c.column = piece.at(0) - 'a';
     c.row = piece.at(1) - '1';
     return c;
}
/*
 * cells available to knight at (x, i) are S(x,i) := 
 * (x +/- 2, i +/- 1) U (x +/- 1, i +/- 2)
 * from S(x,i) calculate minimum of (k -> r) and (k -> q) then add (r -> q)
 */
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
                    }
            }
    return moves;
}

int CaptureThemAll::BFS(cell start, cell dst)
{
    // Mark all the vertices as not visited
    int V = 8;
    bool visited[V][V];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            visited[i][j] = false;
 
    // Create a queue for BFS
    list<cell> queue;
 
    // struct cell s = parse_knight(knight);
    // Mark the current node as visited and enqueue it
    
    int r = start.row;
    int c = start.column;
    visited[r][c] = true;
    queue.push_back(start);
 
    int num_moves;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        cell s = queue.front();
        queue.pop_front();
 
        if(s.column == dst.column && s.row == dst.row) {
            num_moves = s.num_moves;
            return num_moves;
        }
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        vector<cell> valid_moves = possible_moves(s);
        for(cell next_cell : valid_moves)
        {

            if(!visited[next_cell.row][next_cell.column])
            {
                visited[next_cell.row][next_cell.column] = true;
                int num_moves_local = s.num_moves + 1;
                next_cell.num_moves = num_moves_local;
                queue.push_back(next_cell);
            }
        }
    }
    return 0;
}
int CaptureThemAll::fastKnight(string king, string rook, string queen)
{
    cell k = parse_str(king);
    cell r = parse_str(rook);
    cell q = parse_str(queen);
    int min_r = BFS(k, r);
    int min_q = BFS(k, q);
    int min_rq = BFS(r, q);
    int possibility_a = min(min_r, min_q) + min_rq;
    int possibility_b = min(2*min_r + min_q, 2*min_q + min_r);
    return min(possibility_a, possibility_b);
}


int main()
{
   CaptureThemAll c;
   int res = c.fastKnight("h8","e2", "d2");         
   cout << "res = " << res << endl;
   return 0;
}
