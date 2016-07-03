/*
 * Function to return number of bits required to convert int A into into B.
 * Assume A < B.
 */
#include <iostream>
#include <math.h>
/*
 * Cleaner way:
 */

int bits_required_2(int A, int B)
{
    /*
     * Number of 1 bits in difference gives the number of bits that are
     * difference in A and B.
     */
    int result = 0;
    for(int difference = A ^ B; difference != 0; difference = difference >> 1)
    {
        result += difference & 1;
    }
    return result;
}
int bits_required_1(int difference)
{
    int result = 0;
    while(difference)
    {
        int bit = difference & 1;
        if(bit == 1)
            result++;
        difference = difference >> 1;
    }
    return result;
}

int swap_bits(int input)
{
    int num_of_bits = ceil(log2(input));
    int even_mask = 0;
    int odd_mask = 0;
    for(int i = 0 ; i < num_of_bits/2; i++) {
        even_mask += pow(2, 2*i);
        odd_mask += pow(2, (2*i + 1));
    }
    int even_to_odd = input & even_mask << 1;
    int odd_to_even = input & odd_mask >> 1;
    int new_odds = even_to_odd & odd_mask;
    int new_evens = odd_to_even & even_mask;
    return (new_odds | new_evens);
}
int main()
{
    int A = 31;
    int B = 15;
    int difference = A - B;
    int result = bits_required_1(difference);
    int clean_result = bits_required_2(A,B);
    std::cout << result << std::endl;
    std::cout << clean_result << std::endl;
}
