#include <iostream>
#include <string>
#include <cctype>
#include "DNAComp.h"

using namespace std;

//Constructor
DNAComp::DNAComp() {
    //Creates a stack of char
    myStack = new NTStack<char>();
    comp = "";
}

//Destructor
DNAComp::~DNAComp() {
    delete myStack;
}

//Creates a complement of the DNA input string
string DNAComp::complement(string input) {
    //If the stack is not empty, then it pops until its empty
    //avoids previous stacks messing with the new stacks
     while (myStack->isEmpty() == false) {
        myStack->pop();
    }

    //temporary string for complement
    string comp = "";

    //Loops through the input
    //iterates through each character and adds to temporary string 
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 'A') {
            comp += 'T';
            //Pushes to the stack so that when we get the reverse, we can just call pop
            //This will reverse it since stack is LIFO
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

//Returns the reverse complement of the DNA
string DNAComp::reverseComplement(string input) {
    //Checks if stack is empty
    //If not, makes it empty
     while (myStack->isEmpty() == false) {
        myStack->pop();
    }

    //temp string for reverse string 
    string reverse = "";

    //Calls the complement function so that it creates the stack
    complement(input);

    for (int i = 0; i < input.size() - 1; ++i) {
        //Since we have a stack of the input, using pop will get you the reverse
        reverse += myStack->pop();
    }
    return reverse;
}