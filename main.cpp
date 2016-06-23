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
    check.resize(len);
    /*
     * If len is odd, don't care about len/2 element, must check elements 0 to
     * n/2 -1 is equal to reverse of n/2 + 1 to n.
     * If len is even, do care. Must have elements 0 to n/2 equal to reverse of
     * n/2 to n.
     */
    vector<size_t>::iterator first = check.begin() + len/2;
    vector<size_t>::iterator last = check.end();
    vector<size_t>::reverse_iterator first2 = check.rbegin() + len/2;
    for(; first != last; ++first, ++first2){
       if(*first != *first2) {
           return false;
       }
       
     }

    return true;
}

int palindromify(size_t x)
{
    bool result;
	result = is_pallindrome(x);
	if(result == true) {
       return x; 
	}
	while(result != true) {
		x += reverse_digits(x);
		result = is_pallindrome(x);
		if(x >= 500000000) {
			return -1;
		}
	}
	return x;

}
int main() {
    
    size_t x = 196;
	int pal = palindromify(x);

	cout << "x = " << x << " pal = " << pal << endl;

    return 0;
}
