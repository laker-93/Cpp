#include <iostream>
#include <vector>
#include <math.h>

std::vector<uint32_t> find(uint32_t first, uint32_t last, uint32_t n, uint32_t num_of_one_bits)
{
    uint32_t total_number = ceil(log2(n));
    uint32_t num_of_last_bits;
    if(last == 0) {
        num_of_last_bits = total_number - num_of_one_bits;
    } else {
        num_of_last_bits = num_of_one_bits;
    }
    uint32_t first_index = 0;
    std::vector<uint32_t> result;
    result.reserve(2);
    while((n & 1) != first) {
        n = n >> 1;
        first_index++;
        if(first_index > total_number) {
            result.push_back(-1);
            return result;
        }
    }
    uint32_t second_index = first_index;
    uint32_t lasts_encountered = 0;
    while((n & 1) != last && lasts_encountered < num_of_last_bits) {
        n = n >> 1;
        if((n & 1) == last){
            lasts_encountered++;
        }
        second_index++;
        if(second_index > total_number) {
            result.push_back(-1);
            return result;
        }
    }
    std::cout << first_index << second_index << std::endl;
    result.push_back(first_index);
    result.push_back(second_index);
    return result;
}

uint32_t return_num_of_set_bits(uint32_t i)
{
     // Java: use >>> instead of >>
     // C or C++: use uint32_t
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}
int main()
{
    uint32_t num_of_one_bits = return_num_of_set_bits(25);
    uint32_t total_number_bits = ceil(log2(25)); 
    std::vector<uint32_t> result = find(1, 0, 25, num_of_one_bits);
    
    for(std::vector<uint32_t>::const_iterator i = result.begin(); i != result.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    return 0;
}


