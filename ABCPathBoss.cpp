#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define forsn(i,s,n) for(int i=s;i<(int)(n);++i)
#define forall(i,c) for(typeof(c.begin()) i=c.begin();i!=c.end();++i)

class ABCPath {
public:
    int length(vector <string> g) {
        int dx[8] = {-1,-1,-1,0,0,1,1,1};
        int dy[8] = {-1,0,1,-1,1,-1,0,1};
        int res=0;
        vector< vector<int> > m(g.size(), vector<int>(g[0].size(), -1));
        list<int> qx,qy;
        forn(x,g.size())forn(y,g[x].size())
        if (g[x][y] == 'A') {
            qx.push_back(x);
            qy.push_back(y);
            m[x][y] = 0;
        }
        while(!qx.empty()) {
            int x = qx.front();
            qx.pop_front();
            int y = qy.front();
            qy.pop_front();
            forn(d, 8) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && ny >= 0 &&
                        nx < m.size() && ny < m[0].size()
                        && m[nx][ny] == -1 && g[nx][ny] == g[x][y] + 1) {
                    m[nx][ny] = m[x][y] + 1;
                    qx.push_back(nx);
                    qy.push_back(ny);
                }
            }
        }
        forn(x,m.size())forn(y,m[x].size()) res += m[x][y] + 1;
        return res;
    }

};
int main()
{
    ABCPath a;
    const char *test[] = { "KCBVNRXSPVEGUEUFCODMOAXZYWEEWNYAAXRBKGACSLKYRVRKIO",
                           "DIMCZDMFLAKUUEPMPGRKXSUUDFYETKYQGQHNFFEXFPXNYEFYEX",
                           "DMFRPZCBOWGGHYAPRMXKZPYCSLMWVGMINAVRYUHJKBBRONQEXX",
                           "ORGCBHXWMTIKYNLFHYBVHLZFYRPOLLAMBOPMNODWZUBLSQSDZQ",
                           "QQXUAIPSCEXZTTINEOFTJDAOBVLXZJLYOQREADUWWSRSSJXDBV",
                           "PEDHBZOVMFQQDUCOWVXZELSEBAMBRIKBTJSVMLCAABHAQGBWRP",
                           "FUSMGCSCDLYQNIXTSTPJGZKDIAZGHXIOVGAZHYTMIWAIKPMHTJ",
                           "QMUEDLXSREWNSMEWWRAUBFANSTOOJGFECBIROYCQTVEYGWPMTU",
                           "FFATSKGRQJRIQXGAPLTSXELIHXOPUXIDWZHWNYUMXQEOJIAJDH",
                           "LPUTCFHYQIWIYCVOEYHGQGAYRBTRZINKBOJULGYCULRMEOAOFP",
                           "YOBMTVIKVJOSGRLKTBHEJPKVYNLJQEWNWARPRMZLDPTAVFIDTE",
                           "OOBFZFOXIOZFWNIMLKOTFHGKQAXFCRZHPMPKGZIDFNBGMEAXIJ",
                           "VQQFYCNJDQGJPYBVGESDIAJOBOLFPAOVXKPOVODGPFIYGEWITS",
                           "AGVBSRLBUYOULWGFOFFYAAONJTLUWRGTYWDIXDXTMDTUYESDPK",
                           "AAJOYGCBYTMXQSYSPTBWCSVUMNPRGPOEAVVBGMNHBXCVIQQINJ",
                           "SPEDOAHYIDYUJXGLWGVEBGQSNKCURWYDPNXBZCDKVNRVEMRRXC",
                           "DVESXKXPJBPSJFSZTGTWGAGCXINUXTICUCWLIBCVYDYUPBUKTS",
                           "LPOWAPFNDRJLBUZTHYVFHVUIPOMMPUZFYTVUVDQREFKVWBPQFS",
                           "QEASCLDOHJFTWMUODRKVCOTMUJUNNUYXZEPRHYOPUIKNGXYGBF",
                           "XQUPBSNYOXBPTLOYUJIHFUICVQNAWFMZAQZLTXKBPIAKXGBHXX"
                         };
    vector<string> v1(test, end(test));
    int len = a.length(v1);
    cout << len << endl;
    return 0;
}
