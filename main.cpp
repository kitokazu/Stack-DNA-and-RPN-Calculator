#include <iostream>
#include <string>
#include <cctype>
#include "GenStack.h"
#include "LinkedList.h"
#include "FileProcessor.h"
#include "DNAComp.H"
#include "RPNCalc.h"

using namespace std;

int main(int argc, char **argv) {
  //If the user does not enter the correct command line parameters
  if (argc != 2) {
    cerr << "Error. Please enter mode RPN or DNA" << endl;
    return -1;
  }

  //string for the mode, either RPN or DNA
  string mode = argv[1];
  
  //If the user enters the RPN calculator mode
  if (mode == "RPN") {
    string input;
    //Prompts the user for what to be calculated
    cout << "Enter operands and operators in postfix notification. "<< endl;
    cout << "Make sure there is a space between each operator and operand. " << endl;

    //Gets the operators/operand
    getline(cin, input);

    //Creates insatnce of RPN calculator class
    RPNCalc* rpn = new RPNCalc();

    //Displays answer
    cout << "ANSWER: " << rpn->calculate(input) << endl;

    delete rpn;
  }

  //If the users enters DNA mode
  else if (mode == "DNA") {
    //stores input
    string input;
    //stores dna sequence
    string sequence;
    //Prompts the user for sequence
    cout << "Enter file name for DNA sequence: " << endl;
    cin >> input;

    //New instance of file processor class is created
    FileProcessor* file = new FileProcessor();

    //Calls the function in file processor class
    sequence = file->getFile(input);

  } 
  else {
    cout << "Invalid Input" << endl;
  }


}