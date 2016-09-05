#include <iostream>

template <class T>
class Bucky {
    T first, second;
    public:
        Bucky(T a, T b) {
            first = a;
            second = b;
        }
        T bigger();
};

//need to declare the template again to use in a different function
template <class T>
//T inside angular brackets signifies we are using the same template T within
//the class Bucky.
T Bucky<T>::bigger() {
    return (first < second ? second : first);
}
int main () {

    int alpha = 3;
    int beta = 4;
    Bucky<int> b(beta, alpha);
    std::cout << b.bigger() << std::endl;

}

