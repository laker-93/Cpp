#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
class TallPeople {
    public:
        vector<int> getPeople(vector<string>);

};

vector<int> split(string in)
{
    int temp;
    vector<int> cds;
    stringstream s;
    s.str(in);
    while(s >> temp)
        cds.push_back(temp);
    return cds;
}

vector<int> TallPeople::getPeople(vector<string> people)
{
    int rows = people.size();
    int columns;
    vector<int> row_int;
    vector<int> row_mins;
    vector<int> column_max;
    vector<vector <int>> matrix;
    for(string row_str : people) {
        row_int = split(row_str);
        columns = row_int.size();
        matrix.push_back(row_int);
        int min  = *min_element(row_int.begin(), row_int.end());
        row_mins.push_back(min);
        
    }
    matrix.resize(rows);
    for(int i = 0; i < columns; i++) {
        vector<int> column_int;
        for(int j =0 ; j < rows; j++) {
            int col = matrix.at(j).at(i);
            column_int.push_back(col);
        }
        int max = *max_element(column_int.begin(), column_int.end());
        column_max.push_back(max);
    }

    row_mins.resize(rows);
    column_max.resize(columns);
    int min = *min_element(column_max.begin(), column_max.end());
    int max = *max_element(row_mins.begin(), row_mins.end());
        
    vector<int> ret;
    ret.push_back(min);
    ret.push_back(max);
    return ret;
}
int main()
{

    TallPeople t;

    vector<string> input =  {"9 2 3", "4 8 7"};
    
    vector<int> res = t.getPeople(input);
    for(int r : res)
        cout << r << endl;
    return 0;
}
