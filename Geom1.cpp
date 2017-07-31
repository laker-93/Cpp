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
    Vector cross;
    cross.x = ret;
    return ret;
}

int operator*(const Vector& v1, const Vector& v2) {
    int ret = ((v1.x) * (v2.x)) + ((v1.y) * (v2.y));
    Vector cross;
    cross.x = ret;
    return ret;
}

double distance_line_point(Line l, Point p) {
    Vector AB = l.direction_vector;
    Vector AC(l.start, p); 
    int abs = ((AB)*(AB));
    double norm = (double) std::sqrt(abs);
    double dist = ((double) (AB^AC)) / ((double) norm);
    return std::abs(dist);
}

int main() {
    Point p1(1, 1);
    Point p2(2, 6);
    Point p3(3,3);
    Vector v(p1, p2);
    Line l1(p1, p2);
    double res = distance_line_point(l1, p3);
    std::cout << res << std::endl;
    return 0;
}
