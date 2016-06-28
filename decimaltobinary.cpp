#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class ABBA {
    public:
        int *string_to_int(string);
};

int get_index(const char *array, size_t size, char c)
 {
      const char* end = array + size;
      const char* match = std::find(array, end, c);
      return (end == match)? -1 : (match-array);
 }

int char_to_int(const char *start, int len)
{
    int base = pow(10, (len - 1));
    int result = 0;
    for(int i = 0; i < len; i++)
    {

        int digit = *(start + i) - '0';
        result += base*digit;
        base /= 10;
    }
    return result;
}

int *int_in_binary(int input)
{
    int binary_len = ceil(log2 (input));

    /*
     * Store binary_len at position 0 of *result.
     */

    int *result = (int *) malloc(sizeof(int)*(binary_len + 1));
    for(int i = binary_len; i > 0; i--) {
        *(result + i) = input & 1;
        input = input >> 1;
    }
    *(result) = binary_len;
    return result;
}

string decimal_to_binary(string decimal)
{
    int decimal_len = decimal.length();
    const char *decimal_ptr = decimal.c_str();
    int point_index = get_index(decimal_ptr, decimal_len, '.');
    int major = char_to_int(decimal_ptr, point_index);
    int minor_len = decimal_len - point_index - 1;
    int minor = char_to_int(decimal_ptr + point_index + 1, minor_len);
    
    int converter = ((int) pow(5, minor_len));
    int convertable = minor % converter;
    if(convertable != 0)
        return "ERROR";

    int b = (minor/converter);
    int *minor_binary = int_in_binary(b);
    int minor_binary_len = *minor_binary;
    int *major_binary = int_in_binary(major);
    int major_binary_len = *major_binary;

    string result;
    for(int i = 1; i <= major_binary_len; i++) {
        string digit = (to_string(*(major_binary + i)));
        result.append(digit);
    }
    result += '.';
    for(int i = 1; i <= minor_binary_len; i++) {
        string digit = (to_string(*(minor_binary + i)));
        result.append(digit);
    }
    return result;
}


int main()
{
//    ABBA test;
    string decimal = "12233.755859";
    string result = decimal_to_binary(decimal);
    cout << result << endl;
}
