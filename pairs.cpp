#include <string>
#include <iostream>
template<typename T1, typename T2> struct pair {
    T1 first;
    T2 second;
};

int main()
{
 pair<std::string, pair<int,int> > P; 
 std::string s = P.first; // extract string 
 int x = P.second.first; // extract first int 
 int y = P.second.second; // extract second int
 std::cout << x << y << std::endl;
 return 0;
}
