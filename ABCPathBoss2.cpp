#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;
typedef unsigned int uint;

class ABCPath
{
    char grid[52][52];

    int scores[52][52];

    int calc(uint x, uint y, char c) {
        if (grid[y][x] != c) return 0;

        if (scores[y][x] != -1) return scores[y][x];

        vector<int> v;

        int s;

        s = calc(x-1, y-1, c+1);
        v.push_back(s);
        s = calc(x, y-1, c+1);
        v.push_back(s);
        s = calc(x+1, y-1, c+1);
        v.push_back(s);
        s = calc(x-1, y, c+1);
        v.push_back(s);
        s = calc(x+1, y, c+1);
        v.push_back(s);
        s = calc(x-1, y+1, c+1);
        v.push_back(s);
        s = calc(x, y+1, c+1);
        v.push_back(s);
        s = calc(x+1, y+1, c+1);
        v.push_back(s);

        s = 0;
        for (uint i = 0; i < v.size(); ++i)
            if (s < v[i]) s = v[i];

        ++s;
        scores[y][x] = s;
        return s;
    }

public:

    int length(vector<string> vg) {
        for (uint i = 0; i < 52; ++i)
            for (uint j = 0; j < 52; ++j) {
                grid[i][j] = ' ';
                scores[i][j] = -1;
            }

        for (uint i = 0; i < vg.size(); ++i) {
            string s = vg[i];
            for (uint j = 0; j < s.length(); ++j)
                grid[i+1][j+1] = s[j];
        }

        int score = 0;

        for (uint i = 0; i < 52; ++i)
            for (uint j = 0; j < 52; ++j) {
                int s = calc(i, j, 'A');
                if (score < s) score = s;
            }

        return score;
    }
};
