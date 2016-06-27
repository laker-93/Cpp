#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class ABBA {
    public:
        int *string_to_int(string);
};

int *ABBA::string_to_int(string decimal)
{
    int decimal_len = decimal.length();
    int *result_int = (int *) malloc(sizeof(int)*decimal_len);
    return result_int;
}

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
        cout << "digit = " << digit << endl;
        cout << "base = " << base << endl;
        result += base*digit;
        cout << "result = " << result << endl;
        base /= 10;
    }
    return result;
}

int *int_in_binary(int input)
{
    int binary_len = ceil(log2 (input));
    int *result = (int *) malloc(sizeof(int)*binary_len);
    for(int i = binary_len; i > 0; i--) {
        *(result + i) = input & 1;
        input = input >> 1;
        cout << *(result + i) << endl;
    }
    return result;
}


int main()
{
//    ABBA test;
    string decimal = "12233.3857891";
    int decimal_len = decimal.length();
    const char *decimal_ptr = decimal.c_str();
    int point_index = get_index(decimal_ptr, decimal_len, '.');
    int major = char_to_int(decimal_ptr, point_index);
    int minor_len = decimal_len - point_index - 1;
    int minor = char_to_int(decimal_ptr + point_index + 1, minor_len);
    cout << "major = " << major << " minor = " << minor << endl;
    
    int converter = ((int) pow(5, minor_len));
    int convertable = minor % converter;
    if(convertable == 0)
        //can be represented.
    else
        //can not.

    int b = (minor/converter);
    int *minor_binary = int_in_binary(b);

    cout << decimal_len << " digit = " << decimal.at(4) << endl;
}
