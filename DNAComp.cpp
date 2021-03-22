#include <iostream>
#include <string>
#include <cctype>
#include "DNAComp.h"

using namespace std;

DNAComp::DNAComp() {
    myStack = new NTStack<char>();
    comp = "";
}

DNAComp::~DNAComp() {
    delete myStack;
}

string DNAComp::complement(string input) {
     while (myStack->isEmpty() == false) {
        myStack->pop();
    }
    string comp = "";
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
    //myStack->printStack(false);

    // cout << "COMPLEMENT " << comp << endl;
    return comp;
}

string DNAComp::reverseComplement(string input) {
     while (myStack->isEmpty() == false) {
        myStack->pop();
    }

    string reverse = "";
    complement(input);
    myStack->printStack(false);
    for (int i = 0; i < input.size() - 1; ++i) {
        reverse += myStack->pop();
        cout << "R: " << reverse << endl;
    }
    cout << "REVERSE " << reverse << endl;
    return reverse;
}