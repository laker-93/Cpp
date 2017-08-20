#include <iostream>
#include <cmath>
#include <bitset>

void copy_bits(unsigned int *dest, size_t dest_word_count,
               unsigned int *src, size_t src_word_count,
               size_t dest_offset, size_t count_bits)
{

    unsigned int d = *dest;
    unsigned int s = *src;

    double base = 2;
	unsigned int mask = static_cast<unsigned int> (pow(base, count_bits) - 1);
    std::bitset<32> src_bits(s);
    std::cout << "src = " << src_bits << std::endl;
    std::bitset<32> dest_bits(d);
    std::cout << "dest = " << dest_bits << std::endl;
    mask <<= dest_offset;
    mask = ~mask;
    mask = mask & d;
    std::bitset<32> mask_bits(mask);
    std::cout << mask_bits << std::endl;
    s <<= dest_offset;
    d = s | mask;
    std::bitset<32> result(d);
    std::cout << "result = " << result << std::endl;

    std::cout << std::hex << d << std::endl;
    return;
}

int main() {

    unsigned int dest = 0x87654321;
    unsigned int src = 0x0;
	
	size_t count_bits = 32;
    size_t dest_offset = 0;
    copy_bits(&dest, 8, &src, 1, dest_offset, count_bits);
    return 0;
}
