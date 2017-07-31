#include <iostream>

template <class T>
class Spunky{
    public:
        Spunky(T x) {
            std::cout << x << " is not a character." << std::endl;
        }
};

template<>
class Spunky<char>{

    public:
        Spunky(char x) {
            std::cout << x << " is a character." << std::endl;
        }
};
int main() {

    Spunky<double> s1(4.5);
    Spunky<char> s2('q');
    int a = 1;
    for(int i = 3; i > 0; i--)
    {
        std::cout << a << std::endl;
        a = a >> 1;
    }
}
