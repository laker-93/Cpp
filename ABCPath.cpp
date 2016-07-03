#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
//#include <math.h>
//#include <stdlib.h>
using namespace std;

//template<typename T, size_t N>
//T * end(T (&ra)[N]) {
//    return ra + N;
//}
class ABCPath {
    public:
        int length(vector<string>);
};

class Node {
    public:
        char value;
        int row_index;
        int column_index;
        Node(char v, int r, int c) {value = v; row_index = r; column_index = c;};
};

queue<Node> q;

void que_neighbours(int row, int column, vector<string> grid)
{
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            char target = 0;
            try {
                if(i == 0 && j == 0) continue;
                target = grid.at(row + i).at(column + j);
            } catch(const out_of_range& e) {
            }
            if(target != 0) {
                Node target_n(target, row + i, column + j);
                q.push(target_n);
                cout << " target is " << target << endl;
            }
        }
    }
    cout << " as normal " << endl;
    return;
}

vector<int> find_As(vector<string> grid)
{
    string first_row = grid.at(0);
    vector<int> As;
    int count = 0;
    for(int i = 0; i < first_row.length(); i++) {
        if (first_row.at(i) == 'A') {
            count++;
            As.push_back(i);
        }
    }
    As.resize(count);
    return As;
}
int ABCPath::length(vector<string> grid)
{
    vector<int> As = find_As(grid);
    int len;
    for(int i = 0; i < As.size(); i++) {

        len = 0;
        int column = As.at(i);
        if(column == -1)
            return 0;
        que_neighbours(0, column, grid);
        char focus = grid.at(0).at(0);
        while(!q.empty()) {
            Node dequeued = q.front();
            char deq_char = dequeued.value;
            q.pop();
            if((deq_char - focus) == 1) {
                len++;
                focus = deq_char;
                q = {};
                que_neighbours(dequeued.row_index,
                               dequeued.column_index, grid);
            }
        }
    }
    return len;
}

int main()
{
    ABCPath a;
    const char *test[] = { "KCBVNRXSPVEGUEUFCODMOAXZYWEEWNYAAXRBKGACSLKYRVRKIO", "DIMCZDMFLAKUUEPMPGRKXSUUDFYETKYQGQHNFFEXFPXNYEFYEX", "DMFRPZCBOWGGHYAPRMXKZPYCSLMWVGMINAVRYUHJKBBRONQEXX", "ORGCBHXWMTIKYNLFHYBVHLZFYRPOLLAMBOPMNODWZUBLSQSDZQ", "QQXUAIPSCEXZTTINEOFTJDAOBVLXZJLYOQREADUWWSRSSJXDBV", "PEDHBZOVMFQQDUCOWVXZELSEBAMBRIKBTJSVMLCAABHAQGBWRP", "FUSMGCSCDLYQNIXTSTPJGZKDIAZGHXIOVGAZHYTMIWAIKPMHTJ", "QMUEDLXSREWNSMEWWRAUBFANSTOOJGFECBIROYCQTVEYGWPMTU", "FFATSKGRQJRIQXGAPLTSXELIHXOPUXIDWZHWNYUMXQEOJIAJDH", "LPUTCFHYQIWIYCVOEYHGQGAYRBTRZINKBOJULGYCULRMEOAOFP", "YOBMTVIKVJOSGRLKTBHEJPKVYNLJQEWNWARPRMZLDPTAVFIDTE", "OOBFZFOXIOZFWNIMLKOTFHGKQAXFCRZHPMPKGZIDFNBGMEAXIJ", "VQQFYCNJDQGJPYBVGESDIAJOBOLFPAOVXKPOVODGPFIYGEWITS", "AGVBSRLBUYOULWGFOFFYAAONJTLUWRGTYWDIXDXTMDTUYESDPK", "AAJOYGCBYTMXQSYSPTBWCSVUMNPRGPOEAVVBGMNHBXCVIQQINJ", "SPEDOAHYIDYUJXGLWGVEBGQSNKCURWYDPNXBZCDKVNRVEMRRXC", "DVESXKXPJBPSJFSZTGTWGAGCXINUXTICUCWLIBCVYDYUPBUKTS", "LPOWAPFNDRJLBUZTHYVFHVUIPOMMPUZFYTVUVDQREFKVWBPQFS", "QEASCLDOHJFTWMUODRKVCOTMUJUNNUYXZEPRHYOPUIKNGXYGBF", "XQUPBSNYOXBPTLOYUJIHFUICVQNAWFMZAQZLTXKBPIAKXGBHXX" };
    vector<string> v1(test, end(test));
    int len = a.length(v1);
    cout << len << endl;
        return 0;
}
