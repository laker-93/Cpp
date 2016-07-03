#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;


double *roots(int K, int l)
{
	double determinant = sqrt((pow((3 + 4*l), 2)) + 4*6*K);
	double *result = (double *) malloc(2*sizeof(double));
	for(int i = 0; i < 2; i++) {
		*(result + i) = ((- (3 + 4*l) + pow(-1, i) * determinant) / 2);
	}
	return result;
}

int main() {

    int N = 5;
	int K = 10;
    int contender = 10000;
    int l_value = 0;
	int n_contenders = 0;
	for(int l = 0; l < 3; l++) {
	    double *result = roots(K, l);
	    for(int i = 0; i < 2; i++) {
			double root = *(result + i);
			if(root > 0 && (root == (int) root) && root < contender) {
                contender = root;
                l_value = l;
			}
	    }
	}
	
    cout << "contender = " << contender << endl;
    cout << "l_value = " << l_value << endl;

    string str_return;
    int full_cycles = contender/3;
    for(int i = 0; i < full_cycles; i++)
        str_return.append("ABC");
    for(int l = 0; l < l_value; l++)
        str_return.append("C");
    int n = contender + l_value;
    for(int i = n; i < N; i++)
        str_return.append("A");
    cout << str_return << endl;
}
