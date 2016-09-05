 #include <iostream>
 
 using namespace std;
 
 int id() {
     cout << "d" << endl;
     return 1;
 }
 int ie() {
     cout << "e" << endl;
     return 1;
 }
 
 class a {
   public:
 
     int e;
     int d;
     
     a() : d(id()), e(ie()) { }
     
 };
 
int main() {
     a A;
     return 0;
}
