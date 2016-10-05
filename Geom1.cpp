#include <vector>
#include <algorithm>
#include <iostream>

class Point {
    public:
    int x;
    int y;
    Point (int x, int y) : x(x), y(y) {};
    Point() : x(0), y(0) {};
};

class Vector {
    public:
        int x;
        int y;
        Vector () : x(0), y(0) {};
        Vector (Point p1, Point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {};
};

class Line {
    public:
    Point start;
    Point finish;
    Vector direction_vector;
    Line(Point st, Point fin) {
        direction_vector = Vector(st, fin);
        start = st;
        finish = fin;
    };
};

int operator^(const Vector& v1, const Vector& v2) {
    int ret = ((v1.x) * (v2.y)) - ((v1.y) * (v2.x));
    return ret;
}

int operator*(const Vector& v1, const Vector& v2) {
    int ret = ((v1.x) * (v2.x)) - ((v1.y) * (v2.y));
    return ret;
}

int distance_line_point(Line l, Point p) {
    Vector AB = l.direction_vector;
    Vector AC(l.start, p); 
    int abs = (AB)*(AB);
    int norm = std::sqrt(abs);
    int dist = (AB^AC) / norm;
    return dist;
}

int main() {
    Point p1(1, 1);
    Point p2(2, 6);
    Point p3(3,3);
    Vector v(p1, p2);
    int x = v.x;
    int y = v.y;
    std::cout << x << " " << y << std::endl;
    Line l1(p1, p2);
    int xl = l1.direction_vector.x;
    int yl = l1.direction_vector.y;
    std::cout << xl << " " << yl << std::endl;
    int res = distance_line_point(l1, p3);
    std::cout << res << std::endl;
    return 0;
}
