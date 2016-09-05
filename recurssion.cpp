#include <iostream>
#include <vector>

using namespace std;

vector<int> threes()
{
    vector<int> result;
    int i = 0;
    while (i < 10) {
        if (i % 3 != 0) {
            int j = i;
            j += (3 - (j%3));
            result.push_back(j);
        } else {
        result.push_back(i);
        }
        i++;
    }
    return result;
}

vector<int> threes_rec(vector<int> res, int size)
{
    if(size == 0) {
        res.push_back(size);
        return res;
    }
    if(size % 3 != 0) {
        int j = size;
        j += (3 - (j%3));
        res.push_back(j);
    } else {
        res.push_back(size);
    }
    cout << "size = " << size << endl;
    return threes_rec(res, --size);
}
int main()
{
    vector<int> res = threes();
    for(int r : res) 
        cout << r << endl;

    cout << " <<<<<<<<<<<<<<<<<< "<< endl;
    vector<int> res_r;
    int size = 9;
    res_r = threes_rec(res_r, size);

    for(int r : res_r ) {
        cout << r << endl;
    }
    return 0;
}
