#include <iostream>
#include <stdio.h>
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
class ABCPath2 {
    public:
        int length(vector<string>);
};

typedef struct node {
        char value;
        int row_index;
        int column_index;
}Node;

queue<Node> q;

void que_neighbours(Node center, vector<string> grid)
{
    int row = center.row_index;
    int column = center.column_index;
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            char target = 0;
            try {
                if(i == 0 && j == 0) continue;
                target = grid.at(row + i).at(column + j);
            } catch(const out_of_range& e) {
            }
            if(target != 0) {
                Node target_n;
                target_n.value = target;
                target_n.row_index = row + i;
                target_n.column_index = column + j;
                q.push(target_n);
                cout << " target is " << target << endl;
            }
        }
    }
    return;
}

vector<Node> find_As(vector<string> grid)
{
    vector<Node> As;
    int count = 0;
    for(size_t i = 0; i < grid.size(); i++) {
        string focus_row = grid.at(i);
        for(size_t j = 0; j < focus_row.length(); j++) {
            if (focus_row.at(i) == 'A') {
                Node target_n;
                target_n.value = 'A';
                target_n.row_index = i;
                target_n.column_index = j;
                As.push_back(target_n);
                count++;
            }
        }
    }
    As.resize(count);
    return As;
}
int ABCPath2::length(vector<string> grid)
{
    vector<Node> As = find_As(grid);
    if(As.size() == 0)
        return 0;
    int len;
    for(size_t i = 0; i < As.size(); i++) {

        len = 0;
        Node A = As.at(i);
        que_neighbours(A , grid);
        char focus = A.value;
        printf("\nFocus(%d,%d) ", A.row_index, A.column_index);
        while(!q.empty()) {
            Node dequeued = q.front();
            char deq_char = dequeued.value;
            q.pop();
            if((deq_char - focus) == 1) {
                len++;
                focus = deq_char;
                q = {};
                que_neighbours(dequeued, grid);
            }
        }
    }
    return len;
}

int main()
{
    ABCPath2 a;
    const char *test[] = { "ABE", "CFG", "BDH", "ABC" };
                           /*<]{ "KCBVNRXSPVEGUEUFCODMOAXZYWEEWNYAAXRBKGACSLKYRVRKIO",*/
                           //"DIMCZDMFLAKUUEPMPGRKXSUUDFYETKYQGQHNFFEXFPXNYEFYEX",
                           //"DMFRPZCBOWGGHYAPRMXKZPYCSLMWVGMINAVRYUHJKBBRONQEXX",
                           //"ORGCBHXWMTIKYNLFHYBVHLZFYRPOLLAMBOPMNODWZUBLSQSDZQ",
                           //"QQXUAIPSCEXZTTINEOFTJDAOBVLXZJLYOQREADUWWSRSSJXDBV",
                           //"PEDHBZOVMFQQDUCOWVXZELSEBAMBRIKBTJSVMLCAABHAQGBWRP",
                           //"FUSMGCSCDLYQNIXTSTPJGZKDIAZGHXIOVGAZHYTMIWAIKPMHTJ",
                           //"QMUEDLXSREWNSMEWWRAUBFANSTOOJGFECBIROYCQTVEYGWPMTU",
                           //"FFATSKGRQJRIQXGAPLTSXELIHXOPUXIDWZHWNYUMXQEOJIAJDH",
                           //"LPUTCFHYQIWIYCVOEYHGQGAYRBTRZINKBOJULGYCULRMEOAOFP",
                           //"YOBMTVIKVJOSGRLKTBHEJPKVYNLJQEWNWARPRMZLDPTAVFIDTE",
                           //"OOBFZFOXIOZFWNIMLKOTFHGKQAXFCRZHPMPKGZIDFNBGMEAXIJ",
                           //"VQQFYCNJDQGJPYBVGESDIAJOBOLFPAOVXKPOVODGPFIYGEWITS",
                           //"AGVBSRLBUYOULWGFOFFYAAONJTLUWRGTYWDIXDXTMDTUYESDPK",
                           //"AAJOYGCBYTMXQSYSPTBWCSVUMNPRGPOEAVVBGMNHBXCVIQQINJ",
                           //"SPEDOAHYIDYUJXGLWGVEBGQSNKCURWYDPNXBZCDKVNRVEMRRXC",
                           //"DVESXKXPJBPSJFSZTGTWGAGCXINUXTICUCWLIBCVYDYUPBUKTS",
                           //"LPOWAPFNDRJLBUZTHYVFHVUIPOMMPUZFYTVUVDQREFKVWBPQFS",
                           //"QEASCLDOHJFTWMUODRKVCOTMUJUNNUYXZEPRHYOPUIKNGXYGBF",
                           /*"XQUPBSNYOXBPTLOYUJIHFUICVQNAWFMZAQZLTXKBPIAKXGBHXX" };*/
    vector<string> v1(test, end(test));
    int len = a.length(v1);
    cout << len << endl;
        return 0;
}
