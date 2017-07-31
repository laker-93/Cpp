#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
 
using namespace std;
 
 
class BridgeCrossing {
public:
  int minTime(vector <int> times);
  
// BEGIN CUT HERE
//  public:
//  void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
//  private:
//  template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
//  void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//  void test_case_0() { int Arr0[] = { 1, 2, 5, 10 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(0, Arg1, minTime(Arg0)); }
//  void test_case_1() { int Arr0[] = { 1, 2, 3, 4, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, minTime(Arg0)); }
//  void test_case_2() { int Arr0[] = { 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(2, Arg1, minTime(Arg0)); }
//  void test_case_3() { int Arr0[] = { 1, 2, 3, 50, 99, 100 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 162; verify_case(3, Arg1, minTime(Arg0)); }
 
// END CUT HERE
 
};
 
int calcTime(vector<int> times, vector<bool> crossed, bool flside)
{
  bool allCrossed = true;
  for(int i = 0; i < crossed.size(); i++)
  {
    if(!crossed[i]) allCrossed = false;
  }
 
  if(allCrossed) return 0;
  
  // if flashlight on other side, try sending back everyone who has crossed
  int time = 0;
  int minTime = 1000000;
  bool minTimeSet = false;
  if(!flside)
  {
    for(int i = 0; i < crossed.size(); i++)
    {
      if(crossed[i])
      {
        crossed[i] = false;
        time = times[i] + calcTime(times, crossed, true);
        crossed[i] = true;
        if(time < minTime || !minTimeSet)
        {
          minTime = time;
          minTimeSet = true;
        }
      }
    }
    return minTime;
  }
  else // flashlight is on start side send every pair of two people over
  {
    for(int i = 0; i < crossed.size(); i++)
    {
      for(int j = i+1; j < crossed.size(); j++)
      {
        if(!crossed[i] && !crossed[j])
        {
          crossed[i] = true;
          crossed[j] = true;
          if(times[i] > times[j]) time = times[i] + calcTime(times, crossed, false);
          else time = times[j] + calcTime(times, crossed, false);
          crossed[i] = false;
          crossed[j] = false;
          if(time < minTime || !minTimeSet)
          {
            minTime = time;
            minTimeSet = true;            
          }
        }
      }
    }
    return minTime;
  }
}
 
int BridgeCrossing::minTime(vector <int> times)
{
  int minTime;
  vector<bool> crossed;
  bool flside = true;
  crossed.resize(times.size());
  if(times.size() == 1) minTime = times[0];
  else
  minTime = calcTime(times, crossed, flside);
 
// BEGIN CUT HERE
    //static bool s_FirstTime = true; if (s_FirstTime) { s_FirstTime = false; run_test(-1); }
// END CUT HERE
  return minTime;
}
 
 
int main()
{
    BridgeCrossing b;
    vector<int> times = {99, 13, 67, 32, 5, 17};
    b.minTime(times);
    return 0;
}

