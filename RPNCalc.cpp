#include <iostream>
#include <string>
#include "RPNCalc.h"

using namespace std;

RPNCalc::RPNCalc() {
    myStack = new NTStack<int>(5);
}


RPNCalc::~RPNCalc() {
    delete myStack;
}


int RPNCalc::calculate(string input) {
    myStack->push(10);
    myStack->push(3);
    myStack->push(2);
    myStack->printStack(false);
    myStack->pop();
    myStack->printStack(false);
    // for (int i = 0; i < input.size(); ++i) {
    //     int newNum;
    //     if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/')) {
    //         char first = myStack->pop();
    //         //char second = myStack->pop();
    //         int num1 = first - '0';
    //        // int num2 = second - '0';
    //         int num2 = 0;
    //         if(input[i] == '+') {
    //             newNum = num2 + num1;
    //             cout << newNum << endl;
    //         }
    //         else if(input[i] == '-') {
    //             newNum = num2 - num1;
    //         }
    //         else if(input[i] == '*') {
    //             newNum = num2 * num1;
    //         }
    //         else if(input[i] == '/') {
    //             newNum = num2 / num1;
    //         }
    //         //newNum = (char)newNum;
    //         cout << newNum;
    //         myStack->push(newNum);
    //     } else {
    //         int temp = input[i] - '0';
    //         cout << temp << endl;
    //         myStack->push(temp);
    //     }
    //     myStack->printStack(false);
    // }
}


