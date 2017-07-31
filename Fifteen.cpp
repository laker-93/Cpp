#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > magic_square;

class Fifteen {
    public:
        string outcome(vector<int>);
};
void move(int is_dealer, int m,vector<vector<int> > &square)
{
//     if(m == 4) { square.at(0).at(0) = is_dealer; }
//    if(m == 9) { square.at(0).at(1) = is_dealer; }
//    if(m == 2) { square.at(0).at(2) = is_dealer; }
//    if(m == 3) { square.at(1).at(0) = is_dealer; }
//    if(m == 5) { square.at(1).at(1) = is_dealer; }
//    if(m == 7) { square.at(1).at(2) = is_dealer; }
//    if(m == 8) { square.at(2).at(0) = is_dealer; }
//    if(m == 1) { square.at(2).at(1) = is_dealer; }
//    if(m == 6) { square.at(2).at(2) = is_dealer; }

    square.at(magic_square[m].at(0)).at(magic_square[m].at(1)) = is_dealer;
}
string Fifteen::outcome(vector<int> moves)
{

    magic_square[4] = {0, 0};
magic_square[9] = {0, 1};   
magic_square[2] = {0, 2};
magic_square[3] = {1, 0};
magic_square[5] = {1, 1};   
magic_square[7] = {1, 2};
magic_square[8] = {2, 0};
magic_square[1] = {2, 1};   
magic_square[6] = {2, 2};
    vector<vector<int> > square;
    vector<int> row(3, 0);
    for(int i = 0; i < 3; i++) {
        square.push_back(row);
    }
    for(int i = 0; i < moves.size(); i+= 2) {
        move(-10 , moves.at(i), square);
    }
    for(int i = 1; i < moves.size(); i+= 2) {
        move(1 , moves.at(i), square);
    }
    for(vector<int> r : square) {
        for(int i : r) {
            cout << i << ' ';
        }
        cout << endl;
    }
    //rows
    int sum = 0;
    vector<int> matches;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum += square.at(i).at(j);
            cout << "row sum = " << sum << endl;
        }
        if(sum == 2) {
            for(int j = 0; j < 3; j++) {
                if(square.at(i).at(j) == 0) {
                    map<int , vector<int> >::iterator it = magic_square.begin(); 
                    vector<int> test = {i, j};
                    while(it != magic_square.end()) {
                        if(it->second == test) {
                            cout << "MATCH at " << it->first << endl;
                            matches.push_back(it->first);
                        }
                        it++;
                    }
                }
            }
        }
        sum = 0;
    }
    //columns
    sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum += square.at(j).at(i);
            cout << "column sum = " << sum << endl;
            if(sum == 2) {
            for(int j = 0; j < 3; j++) {
                if(square.at(j).at(i) == 0) {
                    map<int , vector<int> >::iterator it = magic_square.begin(); 
                    vector<int> test = {j, i};
                    while(it != magic_square.end()) {
                        if(it->second == test) {
                            cout << "MATCH at " << it->first << endl;
                            matches.push_back(it->first);
                        }
                        it++;
                    }
                }
            }
        }
       }
        sum = 0;
    }
    //diagonal
    sum = 0;
    for(int i = 0; i < 3; i++) {
        sum += square.at(i).at(i);
        cout << "diag sum = " << sum << endl;
        if(sum == 2) {
            for(int i = 0; i < 3; i++) {
                if(square.at(i).at(i) == 0) {
                    cout << "I " << i << endl;
                    map<int , vector<int> >::iterator it = magic_square.begin(); 
                    vector<int> test = {i, i};
                    while(it != magic_square.end()) {
                        if(it->second == test) {
                            cout << "MATCH at " << it->first << endl;
                            matches.push_back(it->first);
                        }
                        it++;
                    }
                }
            }
        }
    }

    if(matches.size() == 0) {
    return "LOSE";
    } else {
        return "WIN " + to_string(*min_element(matches.begin(), matches.end()));
    }
}
int main()
{



    vector<int> moves = {7, 5, 9, 6, 8, 1, 2};
    vector<int> moves2 = {6, 3, 7, 8, 1};
    vector<int> moves3 = {9, 2, 1, 6, 3, 4, 8};
    Fifteen f;
    string res = f.outcome(moves2);
    cout << res << endl;
    return 0;
}
