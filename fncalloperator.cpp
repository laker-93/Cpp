#include <iostream>
class Point {
    private:
      int x, y;
    public:
      Point() : x(0), y(0) { }
      Point& operator()(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;
      }
      void Print() { std::cout << x << " and " << y << std::endl; };
};

int main() {
  Point pt;
  pt.Print();

  // Offset this coordinate x with 3 points
  // and coordinate y with 2 points.
  //Point pt2;
  pt(3, 2);
  pt.Print();
  //pt2.Print();
}
