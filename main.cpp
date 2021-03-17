#include <iostream>
#include <string>
#include "GenStack.h"
#include "LinkedList.h"
#include "RPNCalc.h"

using namespace std;

int main(int argc, char **argv) {
  RPNCalc* rpn = new RPNCalc();
  rpn->calculate("12+");
  delete rpn;
//   NTStack<int> myStack(10);
//   myStack.push(0);
//   myStack.push(6);
//   myStack.push(8);
//   myStack.push(3);
//   myStack.printStack(false);

}