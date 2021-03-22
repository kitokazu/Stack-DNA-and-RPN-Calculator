#include "FileProcessor.h"
#include "DNAComp.h"

#include <iostream>
#include <fstream>
#include <string>

//Constructor
FileProcessor::FileProcessor(){
  dna = new DNAComp();
};
//Destructor
FileProcessor::~FileProcessor(){};

//Function to take the input text file and create and output file
//Or apppend to an existing output text file
string FileProcessor::getFile(string inputFile) {
  //For input
  ifstream inFS;
  //For output
  ofstream outFS;
  //Opens the file but it alson appends to the file
  outFS.open("dnaoutput.txt");
  //String that holds the sentence from input file
  string fileSentence;

  string finalString = "";
  //Opening input file
  inFS.open(inputFile);

  //If there is a problem opening the output file
  if(!outFS.is_open()) {
    cout << "Could not open file" << endl;
    return "";
  }

  //If the input file does not exist
   if(!inFS.is_open()) {
     cout << "Error opening file" << endl;
     return "";
   }

   cout << "Reading file..." << endl;

   //Loops and gets each sentence, line by line
   //Stores the line string into the variable fileSentence
   string temp = "";
   
   //iterates through the file
   while(getline(inFS, fileSentence)) {
     //All of the operations here outputs to dnaoutput.txt
     //Original sequence
     outFS << "Original: " << fileSentence << endl;
     //Complement
     outFS << "Complemenent: " << dna->complement(fileSentence) << endl;
     //Reverse Complement
     outFS << "Reverse Complement: " << dna->reverseComplement(fileSentence) << '\n' << endl;
     
   }

   //In case there is an error for detecting failure for input
   if (!inFS.eof()){
     cout << "input failure" << endl;
   }

   cout << "Closing file" << endl;

   //Closes files
   inFS.close();
   outFS.close();

   return finalString;

};