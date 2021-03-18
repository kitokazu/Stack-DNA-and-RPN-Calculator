#include <iostream>
#include <string>
#include <cctype>
#include "DNAComp.h"

using namespace std;

DNAComp::DNAComp() {
    myStack = new NTStack<char>();
}

DNAComp::~DNAComp() {
    delete myStack;
}

string DNAComp::complement(string input) {
    string comp;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 'A') {
            comp += 'T';
            myStack->push('T');
        }
        else if (input[i] == 'T') {
            comp += 'A';
            myStack->push('A');
        }
        else if (input[i] == 'G') {
            comp += 'C';
            myStack->push('C');
        }
        else if (input[i] == 'C') {
            comp += 'G';
            myStack->push('G');
        }
    }
    return comp;
}

string DNAComp::reverseComplement(string input) {
    string reverse;
    complement(input);
    for (int i = 0; i < input.size(); ++i) {
        reverse += myStack->pop();
    }
    return reverse;
}