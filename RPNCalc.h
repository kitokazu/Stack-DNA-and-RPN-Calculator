#ifndef RPNCALC_H
#define RPNCALC_H
#include "GenStack.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;
class RPNCalc {
    public:
        RPNCalc();
        ~RPNCalc();
        NTStack<int>* myStack;
        int calculate(string input);
    private:
};

#endif