#include <iostream>

using namespace std;
struct node {
        char value;
        int row_index;
        int column_index;
/*        node(node& ref) {*/
            //cout << "copy constructor called" << endl;
                          //this->value = new char(*ref.value);
                          //ref.row_index = row_index;
                          //ref.column_index = column_index;
                  /*}*/
        node(int r, int c, char v) : value(v), row_index(r), column_index(c) {};
};

int main()
{
    char a = 'A';
    node n(3, 4, a);
    cout << n.value << endl;
    node t = n;
    cout << t.value << endl;
    return 0;
}
