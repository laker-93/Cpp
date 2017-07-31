// A C++ program to implement flood fill algorithm
#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
 
// Dimentions of paint screen
#define M 400
#define N 600

static int size = 0;

class grafixMask {
    public:
        vector<int> sortedAreas(vector<string>);
};

void placeMasks(int **screen, string rectangle)
{
    string str(rectangle);
    int buf;
    stringstream ss(str);
    vector<int> coordinates;
    coordinates.reserve(4);
    while (ss >> buf) {
        coordinates.push_back(buf);
    }
    coordinates.resize(4);
    for(int c = coordinates.at(1); c <= coordinates.at(3); c++) {
        for(int r = coordinates.at(0); r <= coordinates.at(2); r++) {
            screen[r][c] = 1;
        }
    }

    return;
}
// A recursive function to replace previous color 'prevC' at  '(x, y)' 
// and all surrounding pixels of (x, y) with new color 'newC' and
void floodFillUtil(int **screen, int x, int y)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return;
    }
 
    if(screen[x][y] != 0) {
        return;
    } else {
    size++;
    screen[x][y] = 2;
 
    floodFillUtil(screen, x+1, y);
    floodFillUtil(screen, x-1, y);
    floodFillUtil(screen, x, y+1);
    floodFillUtil(screen, x, y-1);
    }
}
 
 
vector<int> grafixMask::sortedAreas(vector<string> rectangles)
{

    vector<int> res;

    /*
     * Array is quite large, therefore allocate on the heap.
     */

    int **screen = new int*[M];
    for(int i = 0; i < M; ++i) {
        screen[i] = new int[N];
    }
    for(int r = 0; r < M; r++)
    {
        for(int c = 0; c < N; c++) {
            screen[r][c] = 0;
        }
    }

    for(string rec : rectangles) {
        placeMasks(screen, rec);
    }


    int count = 0;
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++) {
            floodFillUtil(screen, i, j);
            if(size != 0) {
            res.push_back(size);
            count++;
            }
            size = 0;
        }
    }
    
    /*
     * Mo longer need the screen so clean it up.
     */
    for(int i = 0; i < M; ++i) {
        delete [] screen[i];
    }
    delete [] screen;

    res.resize(count);
    sort(res.begin(), res.end());
    return res;
}
// Driver program to test above function
int main()
{
    vector<string> rectangles ={"0 0 0 0"};
//    {"50 300 199 300","201 300 350 300","200 50 200 299","200 301 200 550"};

    //{"0 0 0 0"};
    
    grafixMask a;
    vector<int> res = a.sortedAreas(rectangles);

    for(int s : res) {
        cout << "size = " << s << endl;
    }
 
}
