#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define M 40
#define N 60
using namespace std;

int mask_layer[M][N] = {}; //initilaize all elements with value of 0

class grafixMask {
    public:
        vector<int> sortedAreas(vector<string>);
        void placeMasks(string);
};

void grafixMask::placeMasks(string rectangle)
{
    string str(rectangle);
    int buf;
    stringstream ss(str);
    vector<int> coordinates;
    while (ss >> buf) {
        coordinates.push_back(buf);
    }

    for(int c = coordinates.at(1); c < coordinates.at(3); c++) {
        for(int r = coordinates.at(0); r <= coordinates.at(2); r++) {
            mask_layer[r][c] = -1;
        }
    }

    //place '-1' into place where user has placed a rectangle
    return;
}

void flood_fill(int row, int col, int& size)
{

    if(0 > row || row >= M || 0 > col || col >= N || mask_layer[row][col] != 0) {
              return;
    }

    size++;
    mask_layer[row][col] = 1;
    flood_fill(row, ++col, size);
    flood_fill(++row, col, size);
    flood_fill(--row, col, size);
    flood_fill(row, --col, size);

}

vector<int> grafixMask::sortedAreas(vector<string> rectangles)
{
    vector<int> result;
    for(string rectangle : rectangles) {
        placeMasks(rectangle);
    }
    int size = 0;
    for(int r = 0; r < M - 1; r++) {
        for(int c = 0; c < N - 1; c++) {
                flood_fill(r, c, size); //fill this area with 1s and return size
                if(size != 0) {
                    result.push_back(size);
                }
                size = 0;
        }
    }
    return result;
}
void print()
{
    for(int c = 0; c < M - 1; c++) {
        for(int r = 0; r < N - 1; r++) {
            cout << mask_layer[r][c] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    grafixMask a;

    vector<string> rectangles = {"0 29 39 17"};

    for(string rec : rectangles) {
        a.placeMasks(rec);
    }

    vector<int> res = a.sortedAreas(rectangles);


    for(int r : res) {
        cout << r << endl;
    }
    print();
    return 0;
}
