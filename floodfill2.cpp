// A C++ program to implement flood fill algorithm
#include <vector>
#include<iostream>
using namespace std;
 
// Dimentions of paint screen
#define M 400
#define N 600
int screen[M][N] = {};
 
int size = 0;
// A recursive function to replace previous color 'prevC' at  '(x, y)' 
// and all surrounding pixels of (x, y) with new color 'newC' and
void floodFillUtil(int x, int y)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != 0)
        return;
 
    // Replace the color at (x, y)
    screen[x][y] = 3;
 
    //if (x == 0) {
        //size = 0;
    //}

    size++;
    // Recur for north, east, south and west
    floodFillUtil(x+1, y);
    floodFillUtil(x-1, y);
    floodFillUtil(x, y+1);
    floodFillUtil(x, y-1);
}
 
 
void print()
{
    cout << "Updated screen after call to floodFill: \n";
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
           cout << screen[i][j] << " ";
        cout << endl;
    }
    return;
}
// Driver program to test above function
int main()
{
    vector<int> res;
    for(int i = 0; i < 4; i++) {
    int x = 0, y = 0;
    floodFillUtil(x, y);
    res.push_back(size);
    size = 0;
    }
    for(int r : res) {
    cout << r << endl;
    }
 
}
