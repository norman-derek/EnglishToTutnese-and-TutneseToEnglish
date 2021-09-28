/*
Derek Norman
2364922
norman@chapman.edu
CPSC-350-03
Assignment 2
*/

//This file contains the basic structure for file processor class. The file processor class takes a text file with english text and outputs a file with the tutnese translation to a text file 
// or takes a text file with tutnese words or sentences and translates them to english and outputs a text file with the english translations. 

#include "fileprocessor.h"
#include "translator.h"


FileProcessor::FileProcessor(){ // Constructor

}

FileProcessor::~FileProcessor(){ // Destructor 

}

/*
* This method is called processFile
* This method takes two parameters. The first parameter is a string called input which represents the file to translate from, the second parameter is called output which represents the file to output the translation to
*/
void FileProcessor::processFile(string input, string output){
    Translator *t = new Translator(); // initialized translator object to use translation methods from translator
    string line; //this variable will be used to get lines of text from input file. 

    ofstream tutnesefile(output); // opens output file for writing
    ifstream englishfile(input); // open input file for reading 

    while(getline(englishfile, line) && englishfile.is_open()){ // while the input file still has lines of text and is open
        tutnesefile << t->translateEnglishSentence(line) << endl; //translates line of text from englishfile and writes it tutnese file
    } 
    
    englishfile.close(); //close the input file
    tutnesefile.close(); //close the output file. 

    delete t; //deletes the translator object now that we don't need it anymore

}

/*
* This method is called processFile
* This method takes three parameters. The first parameter is a string called input which represents the file to translate from, the second parameter is called output which represents the file to output the translation to, the third parameter is called translationPath which represents the user choice to translate from E2T (english to tutnese) or T2E (tutnese to english)
*/
void FileProcessor::processFile(string input, string output, string translationPath){
    Translator *t = new Translator(); // initialized translator object to use translation methods from translator

    if(translationPath == "E2T"){
        string line; //this variable will be used to get lines of text from input file.
        ofstream tutnesefile(output); // opens output file for writing
        ifstream englishfile(input); // open input file for reading 

        while(getline(englishfile, line) && englishfile.is_open()){ // while the input file still has lines of text and is open
            tutnesefile << t->translateEnglishSentence(line) << endl; //translates line of text from englishfile and writes it tutnese file
        } 
    
        englishfile.close(); //close the input file
        tutnesefile.close(); //close the output file. 
    } else if (translationPath == "T2E"){
        string line; //this variable will be used to get lines of text from input file.
        ofstream englishfile(output); // opens output file for writing
        ifstream tutnesefile(input); // open input file for reading 

        while(getline(tutnesefile, line) && tutnesefile.is_open()){ // while the input file still has lines of text and is open
            englishfile << t->translateTutneseSentence(line) << endl; //translates line of text from tutnesefile and writes the translation to englishfile
        } 
        
        tutnesefile.close(); //close the input file
        englishfile.close(); //close the output file. 
    }

    delete t; //deletes the translator object now that we don't need it anymore

}