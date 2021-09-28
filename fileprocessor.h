/*
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 2
*/

//This file contains the basic structure for file processor class. The file processor class takes a text file with english text and outputs a file with the tutnese translation to a text file 
// or takes a text file with tutnese words or sentences and translates them to english and outputs a text file with the english translations. 

#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor {

    public:
    FileProcessor(); //Constructor
    ~FileProcessor(); //Destructor
    void processFile(string input, string output); //process takes an input file of english text and creates an output file with the tutnese translation
    void processFile(string input, string output, string translationPath); //process take an input file and creates an output file with the translation of the input file, from english to tutnese or tutnese to english using E2T or T2E
};