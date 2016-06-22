#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;

size_t reverse_digits(size_t input)
{

     size_t len = ceil(log10 (input));
     cout << len << endl;
     size_t i;
     size_t base = pow(10, len - 1);
     size_t result = 0;
     for(i = 0; i < len; i++) {
         size_t digit = input % 10;
         input /= 10;
         result += (digit*base);
         base /= 10;
     } 
   
     return result;
}

bool is_pallindrome(size_t input)
{
     vector<size_t> check;
     size_t len = ceil(log10 (input));
     for(size_t i = 0; i < len; i++) {
         size_t digit = input % 10;
         input /= 10;
         check.push_back(digit);
    }
    return false;
}

int main() {
    
    size_t x = 89;
    size_t reversed = reverse_digits(x);
    size_t pal = x + reversed;
    cout << pal << endl;
    /*try{*/
        //vec.at(1000) = 0;
    //}
    //catch(std::out_of_range o){
        //std::cout<<o.what()<<std::endl;
    /*}*/
    return 0;
}
