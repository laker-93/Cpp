#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Rando.h"
#include "Base.h"
using namespace std;

Rando::Rando() {
    cout << "Rando constructor" << endl;
}

Rando::~Rando() {
    cout << "Rando deconstructor" << endl;
}
void Rando::doSomething(int *publicv){

     
     int rand = 3;
     publicv = (int *)malloc(sizeof(int));
     publicv = &rand;
     cout << "rando " << publicv << endl;
     cout << "rando * " << *publicv << endl;
     protectedv = 7;
     cout << "rando protectedv " << protectedv << endl;
}
