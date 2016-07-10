#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
class TallPeople {
    public:
        vector<int> getPeople(vector<string>);
        vector<int> parse_string(string);
        vector<vector <int>> parse_string_vector(vector<string>);

};

vector<int> TallPeople::parse_string(string in)
{
    int temp;
    vector<int> cds;
    stringstream s;
    s.str(in);
    while(s >> temp)
        cds.push_back(temp);
    return cds;
}

vector<vector <int>> TallPeople::parse_string_vector(vector<string> people)
{
    int rows = people.size();
    vector<vector <int>> matrix;
    for(string row_str : people) {
        vector<int> row_int = parse_string(row_str);
        matrix.push_back(row_int);
        
    }
    matrix.resize(rows);

    return matrix;
}
vector<int> TallPeople::getPeople(vector<string> people)
{
    vector<vector <int>> matrix = parse_string_vector(people);
    vector<int> row_mins;
    vector<int> column_max;
    for(vector<int> row : matrix) {
        int min  = *min_element(row.begin(), row.end());
        row_mins.push_back(min);
        
    }
    int columns = matrix.at(0).size();
    int rows = matrix.size();
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
    ret.push_back(max);
    ret.push_back(min);
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
