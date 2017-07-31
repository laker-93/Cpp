#include <iostream>
#include <vector>
#include "math.h"

class EllysBottles {
    public:
bool double_equal(double a, double b) {
    double eps = 0.00000000001;
    return fabs(a - b) < eps;
}

double getVolume(std::vector<int> b, int k) {
    std::vector<double> bottles(b.begin(), b.end());
    double small;
    for(int i = 0; i < k; ++i) {
        double smallest = bottles.at(0);
        int small_i = 0;
        double largest= bottles.at(0);
        int large_i = 0;
        for(double bot : bottles) {
            if(bot > largest) { largest = bot; }
            if(bot < smallest) {  smallest= bot; }
        }
        for(double bot : bottles) {
            if(double_equal(bot, largest)) {break;}
            else {large_i++;}
        }
        for(double bot : bottles) {
            if(double_equal(bot, smallest)) {break;}
            else {small_i++;}
        }
        double new_value = (largest + smallest) / 2;

        std::cout << "smallest = " << smallest << " small_i = " << small_i
            << " largest = "<< largest << " large_i = " << large_i <<
           " new_value = " << new_value << std::endl;
       bottles.at(large_i) = new_value;
       bottles.at(small_i) = new_value;
        for(auto bottle : bottles) {
            std::cout << bottle << std::endl;
        }
        small = smallest;
    }
    return small;
}
};
int main()
{
    EllysBottles eb;
    std::vector<int> bottles = {42, 13, 17, 7, 22};
    double smallest = eb.getVolume(bottles, 8);
    std::cout << " smallest = " << smallest << std::endl;
    return 0;
}


