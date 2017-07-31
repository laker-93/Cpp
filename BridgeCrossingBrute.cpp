#include <iostream>
#include <vector>

using namespace std;
int best,n = 4,side[6]; // side[x]=0 if on the start side, =1 if on the other side
vector<int> timev;

void go(int tm, int left)
{
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if (side[i]==0 && side[j]==0) {
        // i and j will cross
        side[i]=side[j]=1;
        int new_tm=tm + max(timev[i],timev[j]);
        if (left==2) {
          if (new_tm > best) best=new_tm;
        } else {
          for(int k=0;k < n;k++)
            // k will go back
            if (side[k]==1) {
              side[k]=0;
              go(new_tm+timev[k],left-1);
              side[k]=1;
            }
        }
        side[i]=side[j]=0;
      }
}

int main()
{
    timev = { 1, 2, 5, 10 };
    go(0, 4);
    cout << best << endl;
}
