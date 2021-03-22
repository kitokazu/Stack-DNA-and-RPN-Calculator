//Header file for fileProcessor class
#include <iostream>
#include <string>
#include "DNAComp.H"

using namespace std;

class FileProcessor{
  private:
  public:
    FileProcessor();
    ~FileProcessor();
    string getFile(string inputFile);
    string writeFile(string outputFile);
    DNAComp* dna;

};