#include <iostream>
#include "Overload.h"
using namespace std;

Overload::Overload()
{
}

Overload::Overload(int a) {
    num = a;
}

Overload Overload::operator+(Overload aso) {
    Overload brandNew;
    brandNew.num = num + aso.num;
    return(brandNew);
}
