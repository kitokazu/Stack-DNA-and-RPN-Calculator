#ifndef DNACOMP_H
#define DNACOMP_H
#include "GenStack.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

class DNAComp {
    public:
        DNAComp();
        ~DNAComp();
        NTStack<char>* myStack;
        string complement(string input);
        string reverseComplement(string input);
    private:
        string comp;
};

#endif