#include <iostream>
#include <string>
#include <cctype>
#include "RPNCalc.h"

using namespace std;

//Constructor
RPNCalc::RPNCalc() {
    myStack = new NTStack<int>();
}

//Destructor
RPNCalc::~RPNCalc() {
    delete myStack;
}

//Calculator function for the RPN calculator
int RPNCalc::calculate(string input) {
    //temp string for multiple-digit numbers
    string temp;
    //Iterates through the input string
    for (int i = 0; i < input.size(); ++i) {
        //temporary variable to push to stack
        int newNum;

        //Skips if the index is a whitespace
        if(input[i] == ' ') {
            continue;
        }

        //To prevent Segmentation Fault
        if (i != input.size() - 1) {
            //If the next index is not blank
            if(input[i+1] != ' ') {
                //add the current index to a temp string
                temp += input[i];
                continue;
            }
        }
        //input adds to temp string
        //will be converted to a number after
        temp += input[i];

        //If the char at the index is an operator
        if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/')) {
            //Pop two numbers from the stack.
            //There should be two numbers in the stack when an operator is called
            int num1 = myStack->pop();
            int num2 = myStack->pop();

            //Addition
            if(input[i] == '+') {
                newNum = num2 + num1;
            }

            //Subtraction
            else if(input[i] == '-') {
                newNum = num2 - num1;
            }

            //Multiplication
            else if(input[i] == '*') {
                newNum = num2 * num1;
            }

            //Division
            else if(input[i] == '/') {
                newNum = num2 / num1;
            }
        //If the char at index is a number
        } else {
            //converts the char into an integer
            //found this method online
            newNum = stoi(temp);
        }
        //Pushes the new number to the stack
        myStack->push(newNum);
        //Prints the stack
        myStack->printStack(false);
        temp = "";
    }
    //Final Answer
    return myStack->pop();
}


